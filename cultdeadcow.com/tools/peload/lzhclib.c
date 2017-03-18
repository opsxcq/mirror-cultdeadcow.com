/**
 *
 *  LZHCLib.C - Compression module
 *
 *  Compression Library (LZH) from Haruhiko Okumura's "ar".
 *
 *  Copyright(c) 1996 Kerwin F. Medina
 *  Copyright(c) 1991 Haruhiko Okumura
 *
 *  In MSDOS, this MUST be compiled using compact, large,
 *      or huge memory models
 *
 *  To test, compile as below to create a stand-alone compressor (will
 *      compress standard input to standard output):
 *          bcc -O2 -mc -D__TEST__ lzhclib.c
 *              or
 *          gcc -O2 -D__TEST__ lzhclib.c
 *      then run as: lzhclib <infile >outfile
 *
 *  To use as a library for your application, __TEST__ must
 *      not be defined.
 *
 */

#include <string.h>

#include "lzh.h"

/*
 * Additions
 */

#define OUTBUFSIZE (1024 * 4)

static uchar far *outbuf;
static int outbufpos;

static type_fnc_read   fnc_read;
static type_fnc_write  fnc_write;
static type_fnc_malloc fnc_malloc;
static type_fnc_free   fnc_free;

static int error_write;

/*
 * io.c
 */

static uint subbitbuf;
static int bitcount;

/*
 * Write rightmost n bits of x
 */
static void putbits (int n, uint x)
{
    if (n < bitcount)
    {
         subbitbuf |= x << (bitcount -= n);
    }
    else
    {
        outbuf[outbufpos++] = subbitbuf | (x >> (n -= bitcount));
        if (outbufpos >= OUTBUFSIZE)
        {
	    if (fnc_write (outbuf, outbufpos) != outbufpos)
                error_write = 1;
            outbufpos = 0;
        }
        if (n < CHAR_BIT)
        {
            subbitbuf = x << (bitcount = CHAR_BIT - n);
        }
        else
        {
            outbuf[outbufpos++] = x >> (n - CHAR_BIT);
            if (outbufpos >= OUTBUFSIZE)
            {
		if (fnc_write (outbuf, outbufpos) != outbufpos)
                    error_write = 1;
                outbufpos = 0;
            }
            subbitbuf = x << (bitcount = 2 * CHAR_BIT - n);
        }
    }
}

static void init_putbits (void)
{
    bitcount = CHAR_BIT;
    subbitbuf = 0;
}

/*
 * maketree.c
 */

static int maketree_n, maketree_heapsize;
static short maketree_heap[NC + 1];
static ushort far *maketree_freq, far *maketree_sortptr, maketree_len_cnt[17];
static uchar far *maketree_len;
static ushort left[2 * NC - 1], right[2 * NC - 1];

static void count_len (int i)          /* call with i = root */
{
    static int depth = 0;

    if (i < maketree_n)
        maketree_len_cnt[(depth < 16) ? depth : 16]++;
    else
    {
        depth++;
        count_len (left[i]);
        count_len (right[i]);
        depth--;
    }
}

static void make_len (int root)
{
    int i, k;
    uint cum;

    for (i = 0; i <= 16; i++)
        maketree_len_cnt[i] = 0;
    count_len (root);
    cum = 0;
    for (i = 16; i > 0; i--)
        cum += maketree_len_cnt[i] << (16 - i);
    while (cum != (1U << 16))
    {
      #if 0
        fflush (stderr);
        fprintf (stderr, "17");
        fflush (stderr);
      #endif
        maketree_len_cnt[16]--;
        for (i = 15; i > 0; i--)
        {
            if (maketree_len_cnt[i] != 0)
            {
                maketree_len_cnt[i]--;
                maketree_len_cnt[i + 1] += 2;
                break;
            }
        }
        cum--;
    }
    for (i = 16; i > 0; i--)
    {
        k = maketree_len_cnt[i];
        while (--k >= 0)
            maketree_len[*maketree_sortptr++] = i;
    }
}

/*
 * priority queue; send i-th entry down maketree_heap
 */
static void downheap (int i)
{
    int j, k;

    k = maketree_heap[i];
    while ((j = 2 * i) <= maketree_heapsize)
    {
        if (j < maketree_heapsize && maketree_freq[maketree_heap[j]] > maketree_freq[maketree_heap[j + 1]])
            j++;
        if (maketree_freq[k] <= maketree_freq[maketree_heap[j]])
            break;
        maketree_heap[i] = maketree_heap[j];
        i = j;
    }
    maketree_heap[i] = k;
}

static void make_code (int maketree_n, uchar far *maketree_len, ushort far *code)
{
    int i;
    ushort start[18];

    start[1] = 0;
    for (i = 1; i <= 16; i++)
        start[i + 1] = (start[i] + maketree_len_cnt[i]) << 1;
    for (i = 0; i < maketree_n; i++)
        code[i] = start[maketree_len[i]]++;
}

/*
 * make tree, calculate maketree_len[], return root
 */
int make_tree (int nparm, ushort far *freqparm,
		uchar far *lenparm, ushort far *codeparm)
{
    int i, j, k, avail;

    maketree_n = nparm;
    maketree_freq = freqparm;
    maketree_len = lenparm;
    avail = maketree_n;
    maketree_heapsize = 0;
    maketree_heap[1] = 0;
    for (i = 0; i < maketree_n; i++)
    {
        maketree_len[i] = 0;
        if (maketree_freq[i])
            maketree_heap[++maketree_heapsize] = i;
    }
    if (maketree_heapsize < 2)
    {
        codeparm[maketree_heap[1]] = 0;
        return maketree_heap[1];
    }
    for (i = maketree_heapsize / 2; i >= 1; i--)
        downheap (i);                  /* make priority queue */
    maketree_sortptr = codeparm;
    do
    {   /* while queue has at least two entries */
        i = maketree_heap[1];   /* take out least-maketree_freq entry */
        if (i < maketree_n)
            *maketree_sortptr++ = i;
        maketree_heap[1] = maketree_heap[maketree_heapsize--];
        downheap (1);
        j = maketree_heap[1];   /* next least-maketree_freq entry */
        if (j < maketree_n)
            *maketree_sortptr++ = j;
        k = avail++;                   /* generate new node */
        maketree_freq[k] = maketree_freq[i] + maketree_freq[j];
        maketree_heap[1] = k;
        downheap (1);                  /* put into queue */
        left[k] = i;
        right[k] = j;
    } while (maketree_heapsize > 1);
    maketree_sortptr = codeparm;
    make_len (k);
    make_code (nparm, lenparm, codeparm);
    return k;                          /* return root */
}

/*
 * huf.c
 */

#define BUFSIZ (1024 * 16)

#define NP (DICBIT + 1)
#define NT (CODE_BIT + 3)
#define PBIT 4      /* smallest integer such that (1U << PBIT) > NP */
#define TBIT 5      /* smallest integer such that (1U << TBIT) > NT */
#if NT > NP
    #define NPT NT
#else
    #define NPT NP
#endif

static uchar far *buf, far c_len[NC], far pt_len[NPT];
static ushort far c_freq[2 * NC - 1], far c_code[NC],
              far p_freq[2 * NP - 1], far pt_code[NPT],
              t_freq[2 * NT - 1];

static void count_t_freq (void)
{
    int i, k, n, count;

    for (i = 0; i < NT; i++)
        t_freq[i] = 0;
    n = NC;
    while (n > 0 && c_len[n - 1] == 0)
        n--;
    i = 0;
    while (i < n)
    {
        k = c_len[i++];
        if (k == 0)
        {
            count = 1;
            while (i < n && c_len[i] == 0)
            {
                i++;
                count++;
            }
            if (count <= 2)
                t_freq[0] += count;
            else if (count <= 18)
                t_freq[1]++;
            else if (count == 19)
            {
                t_freq[0]++;
                t_freq[1]++;
            }
            else
                t_freq[2]++;
        }
        else
            t_freq[k + 2]++;
    }
}

static void write_pt_len (int n, int nbit, int i_special)
{
    int i, k;

    while (n > 0 && pt_len[n - 1] == 0)
        n--;
    putbits (nbit, n);
    i = 0;
    while (i < n)
    {
        k = pt_len[i++];
        if (k <= 6)
            putbits (3, k);
        else
            putbits (k - 3, (1U << (k - 3)) - 2);
        if (i == i_special)
        {
            while (i < 6 && pt_len[i] == 0)
                i++;
            putbits (2, (i - 3) & 3);
        }
    }
}

static void write_c_len (void)
{
    int i, k, n, count;

    n = NC;
    while (n > 0 && c_len[n - 1] == 0)
        n--;
    putbits (CBIT, n);
    i = 0;
    while (i < n)
    {
        k = c_len[i++];
        if (k == 0)
        {
            count = 1;
            while (i < n && c_len[i] == 0)
            {
                i++;
                count++;
            }
            if (count <= 2)
            {
                for (k = 0; k < count; k++)
                    putbits (pt_len[0], pt_code[0]);
            }
            else if (count <= 18)
            {
                putbits (pt_len[1], pt_code[1]);
                putbits (4, count - 3);
            }
            else if (count == 19)
            {
                putbits (pt_len[0], pt_code[0]);
                putbits (pt_len[1], pt_code[1]);
                putbits (4, 15);
            }
            else
            {
                putbits (pt_len[2], pt_code[2]);
                putbits (CBIT, count - 20);
            }
        }
        else
            putbits (pt_len[k + 2], pt_code[k + 2]);
    }
}

static void encode_c (int c)
{
     putbits (c_len[c], c_code[c]);
}

static void encode_p (uint p)
{
    uint c, q;

    c = 0;
    q = p;
    while (q)
    {
        q >>= 1;
        c++;
    }
    putbits (pt_len[c], pt_code[c]);
    if (c > 1)
        putbits (c - 1, p & (0xFFFFU >> (17 - c)));
}

static void send_block (void)
{
    uint i, k, flags, root, pos, size;

    root = make_tree (NC, c_freq, c_len, c_code);
    size = c_freq[root];
    putbits (16, size);
    if (root >= NC)
    {
        count_t_freq ();
        root = make_tree (NT, t_freq, pt_len, pt_code);
        if (root >= NT)
        {
            write_pt_len (NT, TBIT, 3);
        }
        else
        {
            putbits (TBIT, 0);
            putbits (TBIT, root);
        }
        write_c_len ();
    }
    else
    {
        putbits (TBIT, 0);
        putbits (TBIT, 0);
        putbits (CBIT, 0);
        putbits (CBIT, root);
    }
    root = make_tree (NP, p_freq, pt_len, pt_code);
    if (root >= NP)
    {
        write_pt_len (NP, PBIT, -1);
    }
    else
    {
        putbits (PBIT, 0);
        putbits (PBIT, root);
    }
    pos = 0;
    for (i = 0; i < size; i++)
    {
        if (i % CHAR_BIT == 0)
            flags = buf[pos++];
        else
            flags <<= 1;
        if (flags & (1U << (CHAR_BIT - 1)))
        {
            encode_c (buf[pos++] + (1U << CHAR_BIT));
            k = buf[pos++] << CHAR_BIT;
            k += buf[pos++];
            encode_p (k);
        }
        else
            encode_c (buf[pos++]);
        if (error_write)
            return;
    }
    for (i = 0; i < NC; i++)
        c_freq[i] = 0;
    for (i = 0; i < NP; i++)
        p_freq[i] = 0;
}

static uint output_pos, output_mask;

static void output (uint c, uint p)
{
    static uint cpos;

    if ((output_mask >>= 1) == 0)
    {
        output_mask = 1U << (CHAR_BIT - 1);
	if (output_pos >= BUFSIZ - 3 * CHAR_BIT)
        {
            send_block ();
            if (error_write)
                return;
            output_pos = 0;
        }
        cpos = output_pos++;
        buf[cpos] = 0;
    }
    buf[output_pos++] = (uchar) c;
    c_freq[c]++;
    if (c >= (1U << CHAR_BIT))
    {
        buf[cpos] |= output_mask;
        buf[output_pos++] = (uchar) (p >> CHAR_BIT);
        buf[output_pos++] = (uchar) p;
        c = 0;
        while (p)
        {
            p >>= 1;
            c++;
        }
        p_freq[c]++;
    }
}

static void huf_encode_start (void)
{
    int i;

    buf[0] = 0;
    for (i = 0; i < NC; i++)
        c_freq[i] = 0;
    for (i = 0; i < NP; i++)
        p_freq[i] = 0;
    output_pos = output_mask = 0;
    init_putbits ();
}

static void huf_encode_end (void)
{
    if (!error_write)
    {
        send_block ();
        putbits (CHAR_BIT - 1, 0);     /* flush remaining bits */
    }
    if (outbufpos > 0)
	fnc_write (outbuf, outbufpos);
}

/*
 * encode.c
 */

#define PERCOLATE  1
#define NIL        0
#define MAX_HASH_VAL (3 * DICSIZ + (DICSIZ / 512 + 1) * UCHAR_MAX)

#define PERC_FLAG 0x8000U

typedef short node;

static uchar far *text, far *childcount;
static node pos, matchpos, avail,
            far *position, far *parent,
            far *prev, far *next;
static int remainder, matchlen;

#if MAXMATCH <= (UCHAR_MAX + 1)
    static uchar *level;
#else
    static ushort *level;
#endif

static void init_slide (void)
{
    node i;

    for (i = DICSIZ; i <= DICSIZ + UCHAR_MAX; i++)
    {
        level[i] = 1;
#if PERCOLATE
        position[i] = NIL;             /* sentinel */
#endif
    }
    for (i = DICSIZ; i < DICSIZ * 2; i++)
        parent[i] = NIL;
    avail = 1;
    for (i = 1; i < DICSIZ - 1; i++)
        next[i] = i + 1;
    next[DICSIZ - 1] = NIL;
    for (i = DICSIZ * 2; i <= MAX_HASH_VAL; i++)
        next[i] = NIL;
}

#define HASH(p, c) ((p) + ((c) << (DICBIT - 9)) + DICSIZ * 2)

static node child (node q, uchar c)
/* q's child for character c (NIL if not found) */
{
    node r;

    r = next[HASH (q, c)];
    parent[NIL] = q;                   /* sentinel */
    while (parent[r] != q)
        r = next[r];
    return r;
}

static void makechild (node q, uchar c, node r)
/* Let r be q's child for character c. */
{
    node h, t;

    h = HASH (q, c);
    t = next[h];
    next[h] = r;
    next[r] = t;
    prev[t] = r;
    prev[r] = h;
    parent[r] = q;
    childcount[q]++;
}

static void split (node old)
{
    node new, t;

    new = avail;
    avail = next[new];
    childcount[new] = 0;
    t = prev[old];
    prev[new] = t;
    next[t] = new;
    t = next[old];
    next[new] = t;
    prev[t] = new;
    parent[new] = parent[old];
    level[new] = matchlen;
    position[new] = pos;
    makechild (new, text[matchpos + matchlen], old);
    makechild (new, text[pos + matchlen], pos);
}

static void insert_node (void)
{
    node q, r, j, t;
    uchar c, far *t1, far *t2;

    if (matchlen >= 4)
    {
        matchlen--;
        r = (matchpos + 1) | DICSIZ;
        while ((q = parent[r]) == NIL)
            r = next[r];
        while (level[q] >= matchlen)
        {
            r = q;
            q = parent[q];
        }
#if PERCOLATE
        t = q;
        while (position[t] < 0)
        {
            position[t] = pos;
            t = parent[t];
        }
        if (t < DICSIZ)
            position[t] = pos | PERC_FLAG;
#else
        t = q;
        while (t < DICSIZ)
        {
            position[t] = pos;
            t = parent[t];
        }
#endif
    }
    else
    {
        q = text[pos] + DICSIZ;
        c = text[pos + 1];
        if ((r = child (q, c)) == NIL)
        {
            makechild (q, c, pos);
            matchlen = 1;
            return;
        }
        matchlen = 2;
    }
    for (;;)
    {
        if (r >= DICSIZ)
        {
            j = MAXMATCH;
            matchpos = r;
        }
        else
        {
            j = level[r];
            matchpos = position[r] & ~PERC_FLAG;
        }
        if (matchpos >= pos)
            matchpos -= DICSIZ;
        t1 = &text[pos + matchlen];
        t2 = &text[matchpos + matchlen];
        while (matchlen < j)
        {
            if (*t1 != *t2)
            {
                split (r);
                return;
            }
            matchlen++;
            t1++;
            t2++;
        }
        if (matchlen >= MAXMATCH)
            break;
        position[r] = pos;
        q = r;
        if ((r = child (q, *t1)) == NIL)
        {
            makechild (q, *t1, pos);
            return;
        }
        matchlen++;
    }
    t = prev[r];
    prev[pos] = t;
    next[t] = pos;
    t = next[r];
    next[pos] = t;
    prev[t] = pos;
    parent[pos] = q;
    parent[r] = NIL;
    next[r] = pos;                     /* special use of next[] */
}

static void delete_node (void)
{
#if PERCOLATE
    node q, r, s, t, u;
#else
    node r, s, t, u;
#endif

    if (parent[pos] == NIL)
        return;
    r = prev[pos];
    s = next[pos];
    next[r] = s;
    prev[s] = r;
    r = parent[pos];
    parent[pos] = NIL;
    if (r >= DICSIZ || --childcount[r] > 1)
        return;
#if PERCOLATE
    t = position[r] & ~PERC_FLAG;
#else
    t = position[r];
#endif
    if (t >= pos)
        t -= DICSIZ;
#if PERCOLATE
    s = t;
    q = parent[r];
    while ((u = position[q]) & PERC_FLAG)
    {
        u &= ~PERC_FLAG;
        if (u >= pos)
            u -= DICSIZ;
        if (u > s)
            s = u;
        position[q] = (s | DICSIZ);
        q = parent[q];
    }
    if (q < DICSIZ)
    {
        if (u >= pos)
            u -= DICSIZ;
        if (u > s)
            s = u;
        position[q] = s | DICSIZ | PERC_FLAG;
    }
#endif
    s = child (r, text[t + level[r]]);
    t = prev[s];
    u = next[s];
    next[t] = u;
    prev[u] = t;
    t = prev[r];
    next[t] = s;
    prev[s] = t;
    t = next[r];
    prev[t] = s;
    next[s] = t;
    parent[s] = parent[r];
    parent[r] = NIL;
    next[r] = avail;
    avail = r;
}

static void get_next_match (void)
{
    int n;

    remainder--;
    if (++pos == DICSIZ * 2)
    {
	memcpy (&text[0], &text[DICSIZ], DICSIZ + MAXMATCH);
	n = fnc_read (&text[DICSIZ + MAXMATCH], DICSIZ);
	if (n < 0)
            n = 0;
        remainder += n;
        pos = DICSIZ;
    }
    delete_node ();
    insert_node ();
}

/*
 * Additions
 */

static struct struct_mem_list {
    void_far_pointer *p;
    int size;
} mem_list[] = {
    { &text      , DICSIZ * 2 + MAXMATCH                           },
    { &level     , (DICSIZ + UCHAR_MAX + 1) * sizeof (*level)      },
    { &childcount, (DICSIZ + UCHAR_MAX + 1) * sizeof (*childcount) },
    { &position  , (DICSIZ + UCHAR_MAX + 1) * sizeof (*position)   },
    { &parent    , DICSIZ * 2 * sizeof (*parent)                   },
    { &prev      , DICSIZ * 2 * sizeof (*prev)                     },
    { &next      , (MAX_HASH_VAL + 1) * sizeof (*next)             },
    { &buf       , BUFSIZ                                          },
    { &outbuf    , OUTBUFSIZE                                      },
    { 0L         , 0                                               }
};

static int allocate_memory (void)
{
    struct struct_mem_list * p = mem_list, *q = mem_list;
    while (p->size)
    {
	if ((*(p->p) = fnc_malloc (p->size)) == 0L)
	{
	    while (q != p)
		fnc_free (*(q->p)), q++;
	    return (1);
	}
	p++;
    }
    return (0);
}

static void release_memory (void)
{
    struct struct_mem_list * p = mem_list;
    while (p->size)
	fnc_free (*(p->p)), p++;
}

int lzh_freeze (type_fnc_write  pfnc_read,
		type_fnc_read   pfnc_write,
		type_fnc_malloc pfnc_malloc,
		type_fnc_free   pfnc_free)
{
    int lastmatchlen;
    node lastmatchpos;

    /* Additions */
    fnc_write   = pfnc_write;
    fnc_read	= pfnc_read;
    fnc_malloc	= pfnc_malloc;
    fnc_free	= pfnc_free;
    if (allocate_memory() != 0)
	return (1);
    error_write = 0;
    outbufpos = 0;

    /* encode.c :: void encode (void) */

    init_slide ();
    huf_encode_start ();
    remainder = fnc_read (&text[DICSIZ], DICSIZ + MAXMATCH);
    if (remainder < 0)
	remainder = 0;
    matchlen = 0;
    pos = DICSIZ;
    insert_node ();
    if (matchlen > remainder)
        matchlen = remainder;
    while (remainder > 0 && !error_write)
    {
        lastmatchlen = matchlen;
        lastmatchpos = matchpos;
        get_next_match ();
        if (matchlen > remainder)
            matchlen = remainder;
        if (matchlen > lastmatchlen || lastmatchlen < THRESHOLD)
            output (text[pos - 1], 0);
        else
        {
            output (lastmatchlen + (UCHAR_MAX + 1 - THRESHOLD),
                    (pos - lastmatchpos - 2) & (DICSIZ - 1));
            while (--lastmatchlen > 0)
                get_next_match ();
            if (matchlen > remainder)
                matchlen = remainder;
        }
    }
    huf_encode_end ();

    release_memory ();
    return (0);
}

#ifdef __TEST__
#ifdef __TURBOC__
#include <io.h>
#include <fcntl.h>
#else
#include <stdio.h>
#endif
#include <stdlib.h>
int read0 (void far *p, int n) {return read (0, p, n);}
int write1 (void far *p, int n) {return write (1, p, n);}
void main (void)
{
    long n;
  #ifdef __TURBOC__  
    setmode (0, O_BINARY);
    setmode (1, O_BINARY);
  #endif  
    n = lseek (0, 0, 2);
    write (1, &n, sizeof (n));
    lseek (0, 0, 0);
    lzh_freeze (read0, write1, malloc, free);
}
#endif

/* end of LZHCLib.C */