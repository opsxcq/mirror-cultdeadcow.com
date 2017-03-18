#ifndef LZH_H
#define LZH_H

#ifndef __TURBOC__
#define far
#endif

typedef unsigned char  uchar;   /*  8 bits or more */
typedef unsigned int   uint;    /* 16 bits or more */
typedef unsigned short ushort;  /* 16 bits or more */
typedef unsigned long  ulong;   /* 32 bits or more */

#ifndef CHAR_BIT
    #define CHAR_BIT            8
#endif

#ifndef UCHAR_MAX
    #define UCHAR_MAX           255
#endif

#define BITBUFTYPE ushort

#define BITBUFSIZ (CHAR_BIT * sizeof (BITBUFTYPE))
#define DICBIT    13                              /* 12(-lh4-) or 13(-lh5-) */
#define DICSIZ (1U << DICBIT)
#define MAXMATCH 256                              /* formerly F (not more than UCHAR_MAX + 1) */
#define THRESHOLD  3                              /* choose optimal value */
#define NC (UCHAR_MAX + MAXMATCH + 2 - THRESHOLD) /* alphabet = {0, 1, 2, ..., NC - 1} */
#define CBIT 9                                    /* $\lfloor \log_2 NC \rfloor + 1$ */
#define CODE_BIT  16                              /* codeword length */

#define MAX_HASH_VAL (3 * DICSIZ + (DICSIZ / 512 + 1) * UCHAR_MAX)

typedef void far * void_far_pointer;
typedef int (*type_fnc_read) (void far *data, int n);
typedef int (*type_fnc_write) (void far *data, int n);
typedef void_far_pointer (*type_fnc_malloc) (unsigned n);
typedef void (*type_fnc_free) (void far *p);

int lzh_freeze (type_fnc_read   pfnc_read,
                type_fnc_write  pfnc_write,
		type_fnc_malloc pfnc_malloc,
		type_fnc_free   pfnc_free);

int lzh_melt (type_fnc_read   pfnc_read,
              type_fnc_write  pfnc_write,
	      type_fnc_malloc pfnc_malloc,
	      type_fnc_free   pfnc_free,
	      ulong origsize);

#endif /* ifndef LZH_H */