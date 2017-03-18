// nbname.cpp - decodes NetBIOS name packets (UDP 137), with some other options
// Copyright 2000 Sir Dystic of the Cult of the Dead Cow - sd@cultdeadcow.com
//
// For Win32 should be compiled with /DWIN32 /MT (use multi-threaded libraries)
//
//  Thanks to all the people who helped me with ideas, testing and making it work
//   under Unix, especially:
//   Optyx, FreqOut, Nyar, Netmask, T12, Sangfroid, Missnglnk
//           and many others I am too lame to remember

/*

Version history:

v1.8 - July 29, 2000
Discussed nbname at Defcon

v1.9 - August 1, 2000
Began keeping history
Added /SCAN option
Added /RETRY option
Changed /NOBOOTY option to /ALLOW and /DENY (sorry all you anal lovers)
Made commandline options case-insensitive (thanks missnglnk for being aware of 
  strcasecmp() which nobody else mentioned to me)
Added /RESPOND option

v2.0 - August 6, 2000
Added /QUERY option
Added the ability to specify a service value for names to /QUERY /RESPOND /ALLOW and /DENY
Changed /OUTSERVC and /OUTALL to /OUTSRVC so you can specify the service value to trigger output
Added a service option to /SPAWN
Added /ASTATBACK option, removed /FINDALL option, "/QUERY * /ASTATBACK" accomplishes the same thing

v2.01 - August 7, 2000
Bug fixes relating to broadcast queries

v2.1 - August 10, 2000
Added /RESPONDIP option and made it so /RESPOND files can include IP address to respond with like lmhosts style files


v2.2 - August 15, 2000
Added socks 5 proxy support with /PROXYIP and /PROXYPORT and /PROXYUSER and /PROXYPASS
** currently only plain text authentication is supported for proxy
Added /DESTPORT to be able to send to ports other than 137
socket errors now return errno under unix
Added /BCASTIP option so you can specify the broadcast IP, often necessary with /PROXY
Added #ifndef for socklen_t stuff 

v2.3 - August 16, 2000
Added /SVCDESC option


v2.4 - August 21, 2000
Changed /QUERY so queries can be directed to a specific IP instead of broadcast only
Added some stuff so /SPAWN and /OUTSVC won't do the same IP twice in a row

  */




#ifdef WIN32

// comment the following line to make a Winsock 1.1 compile 
#define WINSOCK2

#pragma comment(linker, "/SUBSYSTEM:CONSOLE")

#define CLOSESOCKET(x) closesocket(x)
#define GETSOCKETERROR() WSAGetLastError()
#define GETRANDSEED()  GetTickCount()
#define SLEEP(x) Sleep(x)
#define CREATETHREAD(x, y) _beginthread(x, 0, y)
#define EXITTHREAD() _endthread()
#define STRICMP(x, y) stricmp(x, y)
#define STRNICMP(x, y, z) strnicmp(x, y, z)
#define SOCKETBLOCKINGERROR WSAEWOULDBLOCK

#include <process.h>

#ifdef WINSOCK2

#include <winsock2.h>
#include <Ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#else

#include <windows.h>
#include <winsock.h>
#pragma comment(lib, "wsock32.lib")

#endif

#include <io.h>

#endif


// common includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


#ifndef socklen_t 
	#define socklen_t int
#endif


#ifndef WIN32

#include <sys/socket.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>

typedef unsigned char BYTE, *LPBYTE;
typedef unsigned short WORD, *LPWORD;
typedef unsigned long DWORD, *LPDWORD;
typedef unsigned long BOOL, *LPBOOL;
typedef int SOCKET;
typedef struct sockaddr SOCKADDR;
typedef struct sockaddr_in SOCKADDR_IN;
typedef SOCKADDR *LPSOCKADDR;
typedef SOCKADDR_IN *LPSOCKADDR_IN;
typedef struct hostent HOSTENT;
typedef HOSTENT *LPHOSTENT;
typedef unsigned long ULONG;
typedef unsigned short USHORT;
typedef long LONG;

#define GETSOCKETERROR() errno
#define GETRANDSEED() clock()
#define CLOSESOCKET(x) close(x)
#define SLEEP(x) usleep(x*1000)
#define STRICMP(x, y) strcasecmp(x, y)
#define STRNICMP(x, y, z) strncasecmp(x, y, z)
#define SOCKETBLOCKINGERROR EAGAIN



#define MAKEWORD(a, b)      ((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))
#define MAKEULONG(l, h) ((ULONG)(((USHORT)(l)) | ((ULONG)((USHORT)(h))) << 16))
#define MAKELONG(l, h)  ((LONG)MAKEULONG(l, h))

#define FALSE 0
#define TRUE 1
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

#endif


#pragma pack(1)


#define NETBIOSNAMEPORT 137
#define WILDCARDNAME "*\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define SOCKS5PROXYPORT 1080

// uncomment the following line to display statistics info (windows and samba boxes seem to always set this info to 0s)
//#define STUFFTHATSUSUALLYALLZERO

BOOL g_Conflict = FALSE;
BOOL g_Reverse = FALSE;
BOOL g_NoLocal = FALSE;
BOOL g_NoLocalNet = FALSE;
BOOL g_AstatBack = FALSE;
BOOL g_SvcDesc = FALSE;
BOOL g_RandSweep = FALSE;


char *g_OutSvcFile = NULL;
char *g_ASOutFile = NULL;
char *g_SpawnCommand = NULL;
char *g_SpawnArgs = NULL;
char *g_ScanFile = NULL;
char *g_AllowName = NULL;
char *g_DenyName = NULL;
char *g_RespondName = NULL;
char *g_QueryName = NULL;
char *g_ProxyUser = "";
char *g_ProxyPass = "";

BYTE g_OutSvcVal = 0;
BYTE g_SpawnSvcVal = 0;

DWORD g_AstatIP = 0;
DWORD g_LocalIP = 0;
DWORD g_BroadcastIP = INADDR_BROADCAST;
DWORD g_NetmaskIP = 0;
DWORD g_SweepStartIP = 0;
DWORD g_SweepEndIP = 0;
DWORD g_RespondIP = 0;
DWORD g_ProxyIP = 0;
DWORD g_QueryIP = 0;

DWORD g_PacketDelay = 100;
DWORD g_ReceiveTimeout = 0;
DWORD g_DelayDrift = 0;

WORD g_LocalPort = NETBIOSNAMEPORT;
WORD g_DestPort = NETBIOSNAMEPORT;
WORD g_ProxyPort = SOCKS5PROXYPORT;
WORD g_ProxyUDPPort = 0;

int g_Retries = 3;

#define ONT_BNODE 0
#define ONT_PNODE 1
#define ONT_MNODE 2
#define ONT_HNODE 3

typedef struct 
{
	BYTE UnitID[6];				// MAC address
	BYTE Jumpers;
	BYTE TestResult;
	WORD Version;
	WORD StatsPeriod;
	WORD NumCRCs;
	WORD NumAlignmentErrors;
	WORD NumCollisions;
	WORD NumSendAborts;
	DWORD NumGoodSends;
	DWORD NumGoodRcvs;
	WORD NumRetransmits;
	WORD NumResourceConditions;
	WORD NumFreeCommandBlocks;
	WORD NumCommandBlocks;
	WORD NumMaxCommandBlocks;
	WORD NumPendingSessions;
	WORD NumMaxPendingSessions;
	WORD NumMaxTotalSessions;
	WORD SessionDataPacketSize;
} NETBIOSSTATS, *PNETBIOSSTATS;

typedef struct
{
	WORD Reserved:13;
	WORD ONT:2;			// Owner Node Type:
						//  00 = B node
                        //  01 = P node
                        //  10 = M node
                        //  11 = Reserved for future use
                        // For registration requests this is the
                        // claimant's type.
                        // For responses this is the actual owner's type.
	WORD fGroup:1;		// Group Name Flag.
						// If one (1) then the RR_NAME is a GROUP NetBIOS name.
						// If zero (0) then the RR_NAME is a UNIQUE NetBIOS name.
} NBFLAGS;


typedef struct
{
	WORD Reserved:9;	// Reserved for future use.  Must be zero (0).
	WORD fPermanent:1;	// Permanent Name Flag.  If one (1) then entry is for the permanent node name.  
						//  Flag is zero (0) for all other names.
	WORD fActive:1;		// Active Name Flag.  All entries have this flag set to one (1).
	WORD fConflict:1;	// Conflict Flag.  If one (1) then name on this node is in conflict.
	WORD fDeregister:1;	// Deregister Flag.  If one (1) then this name is in the process of being deleted.
	WORD OwnerType:2;	// Owner Node Type:
                        //  00 = B node
                        //  01 = P node
                        //  10 = M node
                        //  11 = Reserved for future use
	WORD fGroupName:1;	// Group Name Flag.
						//  If one (1) then the name is a GROUP NetBIOS name.
						//  If zero (0) then it is a UNIQUE NetBIOS name.
} NETBIOSNAMEFLAGS;

typedef struct
{
	char Name[15];		// uncompressed name
	BYTE BinVal;		// binary value
	WORD Flags;			// flags
} NETBIOSNAME, *PNETBIOSNAME;

#define RCODE_FMTERR	0x1
#define RCODE_SRVERR	0x2
#define RCODE_NAMERR	0x3
#define RCODE_IMPERR	0x4
#define RCODE_RFSERR	0x5
#define RCODE_ACTERR	0x6
#define RCODE_CFTERR	0x7

typedef struct 
{
	WORD Type;			// type of recource record
	WORD Class;			// class of resource record (always IN)
	DWORD TTL;			// Time to live
	WORD RDLength;		// length of following resource data
} RESOURCERECORDHEADER, *PRESOURCERECORDHEADER;

#define RRTYPE_A		0x0001
#define RRTYPE_NS		0x0002
#define RRTYPE_NULL		0x000A
#define RRTYPE_NB		0x0020
#define RRTYPE_NBSTAT	0x0021

#define RRCLASS_IN		0x0001

typedef struct 
{
	WORD RCode   : 4;			// response code
	WORD fNM_B   : 1;			// Broadcast flag
	WORD fNM_00  : 2;			// reserved, always 0
	WORD fNM_RA  : 1;			// Recursion Available flag
	WORD fNM_RD  : 1;			// Recursion Desired flag
	WORD fNM_TC  : 1;			// Truncation flag
	WORD fNM_AA  : 1;			// Authoratative answer flag
	WORD OpCode  : 4;			// Operation code
	WORD fResponse:1;			// Response flag
} OPCODEFLAGSRCODE;

typedef struct {
	WORD TransactionID;			// transaction id, responses match original packet, requests are random/sequential
	WORD OpcodeFlagsRcode;		// opcode, flags and rcode
	WORD QDCount;				// number of questions
	WORD ANCount;				// number of answer resource records
	WORD NSCount;				// number of name service resource records
	WORD ARCount;				// number of athoratative resource records
} NBNAMEHEADER, *PNBNAMEHEADER;

#define OPCODE_QUERY		0
#define OPCODE_REGISTRATION	5
#define OPCODE_RELEASE		6
#define OPCODE_WACK			7
#define OPCODE_REFRESH		8

typedef struct{
	BYTE Name[34];		// compressed name
	WORD Type;			// question type
	WORD Class;			// question class (always type IN - Internet)
} QUESTION, *PQUESTION;

#define QUESTION_TYPE_NB		0x0020	// general name request
#define QUESTION_TYPE_NBSTAT	0x0021	// stats request

#define QUESTION_CLASS_IN		0x0001	// internet class


// authentication values
#define SOCKS5AUTH_NONE      0x00
#define SOCKS5AUTH_GSSAPI    0x01
#define SOCKS5AUTH_USERPASS  0x02
#define SOCKS5AUTH_ERROR     0xFF


// proxy commands
#define SOCKS5CMD_CONNECT    0x01
#define SOCKS5CMD_BIND       0x02
#define SOCKS5CMD_UDPASSOC   0x03

// address types
#define SOCKS5ADRTYPE_IPV4ADDR    0x01 
#define SOCKS5ADRTYPE_DOMAINNAME  0x03
#define SOCKS5ADRTYPE_IPV6ADDR    0x04

// error values
#define SOCKS5ERROR_SUCCESS       0x00
#define SOCKS5ERROR_GENERAL       0x01
#define SOCKS5ERROR_NOTALLOWED    0x02
#define SOCKS5ERROR_NETWORKUNREACHABLE 0x03
#define SOCKS5ERROR_HOSTUNREACHABLE    0x04
#define SOCKS5ERROR_CONNECTIONREFUSED  0x06
#define SOCKS5ERROR_TTLEXPIRED         0x07
#define SOCKS5ERROR_COMMANDNOTSUPPORTED 0x08
#define SOCKS5ERROR_ADDRESSTYPENOTSUPPORTED 0x09

// timeout when waiting for responses
#define SOCKS5TIMEOUT 15	// 15 seconds

// sleep time on blocked call
#define SLEEPTIME 100

// socks proxy version
#define SOCKS5VER 5

// greeting structure, followed by nMethods bytes
typedef struct 
{
	BYTE Ver;
	BYTE nMethods;
} SOCKS5GREET, *PSOCKS5GREET;


// response structure, socks version (5) and status byte
typedef struct 
{
	BYTE Ver;
	BYTE Stat;
} SOCKS5RESPONSE, *PSOCKS5RESPONSE;

// IP4 request structure
typedef struct 
{
	BYTE Ver;
	BYTE Command;
	BYTE Reserved;
	BYTE AddressType;
	DWORD Address;
	WORD Port;
} SOCKS5IP4REQ, *PSOCKS5IP4REQ;

// UDP relay header
typedef struct 
{
	WORD Reserved;
	BYTE Frag;
	BYTE AddressType;
	DWORD Address;
	WORD Port;
} SOCKS5IP4UDPHEADER, *PSOCKS5IP4UDPHEADER;



unsigned char hexvals[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};


void PrintNetbiosName(unsigned char *name)
{
	BYTE BinVal;
	char PrintName[16];
	int x;

	memcpy(PrintName, name, 15);
	PrintName[15] = 0;

	BinVal = name[15];

	printf("%s", PrintName);

	for (x = 0; x < 16 - (int)strlen(PrintName); x++)
		printf(" ");
	
	printf("<%02x>", BinVal);
}

int NetbiosNameToString(char *dest, const BYTE *src, int PacketLeft)
{
	int y;
	static unsigned char Name[32];
	unsigned char UncompressedName[256];
	unsigned char hexbuf[3];
	char *ptr;
	BYTE len;

	// get length of string
	len = *src;

	if (len & 0xC0) // name pointer or other
	{
		len = 0;
		// just return last name read
	} 
	else 
	{
		if (len >= PacketLeft)
		{
			puts("[Short name, aborting]");
			return 0;
		}

		memset(UncompressedName, 0, sizeof(UncompressedName));

		memset(Name, ' ', sizeof(Name) );

		memcpy(UncompressedName, src+1, len);

		for (y = 0; y < 16; y++)
		{
			hexbuf[0] = hexvals[UncompressedName[y*2] - 'A'];
			hexbuf[1] = hexvals[UncompressedName[y*2+1] - 'A'];
			hexbuf[2] = 0;
			Name[y] = (BYTE)strtoul((char *)hexbuf, &ptr, 16);
		}
	}

	memcpy(dest, (const char *)Name , 16);

	return (int)(len+2);
}


void ParamToNetbiosName(char *dest, char *src)
{
	int x;
	char *tmpptr;
	char *BinValPtr = strchr(src, '\\');

	if (BinValPtr != NULL)
	{
		*BinValPtr = 0;
		tmpptr = BinValPtr - 1;
	} 
	else 
	{
		tmpptr = src + strlen(src) - 1;	// point to last char in string
	}

	while (tmpptr > src && *tmpptr == ' ')
	{
		*tmpptr = 0;
		tmpptr--;
	}

	int len = strlen(src);

	if (len > 15) len = 15;

	if (strcmp(src, WILDCARDNAME) == 0)
		memset(dest, 0, 15);
	else
		memset(dest, ' ', 15);

	memcpy(dest, src, len);

	if (BinValPtr != NULL)
	{
		dest[15] = (unsigned char)strtoul(BinValPtr+1, NULL, 16);
		*BinValPtr = '\\';
	}
	else 
		dest[15] = 0;

	// convert to upper case
	for (x = 0; x <15; x++)
		dest[x] = toupper(dest[x]);
	
}



int StringToNetbiosName(char *dest, const char *src, BYTE binval)
{
	int x, y;
	unsigned char Name[16];
	unsigned char UncompressedName[256];
	char hexbuf[2];

	
	if (strcmp(src, WILDCARDNAME) == 0)
	{
		// set name to all zeros
		// for some reason Windows seems to want wildcard names to be padded
		//   with zeros instead of spaces
		memset(Name, 0, sizeof(Name));
	} 
	else 
	{
		// set name to all spaces
		memset(Name, ' ', sizeof(Name));
	}

	// get length of name
	x = strlen(src);

	// truncate at 15th char
	if (x > 15) x = 15;

	// copy up to 15 chars leaving the rest space padded
	memcpy(Name, src, x);

	// uppercase the name
	Name[15] = 0;
	for (y = 0; y < 15; y++)
		Name[y] = toupper((int)Name[y]);

	// set 16th binary char
	Name[15] = binval;

	UncompressedName[0] = 32;

	// convert each char to hex
	for (x = 0; x < 16; x++)
		sprintf((char *)&UncompressedName[(x*2)+1], "%02X", (DWORD)Name[x] );

	// add 'A' to each char
	for (x = 1; x <= 32; x++)
	{
		char *ptr;

		hexbuf[0] = UncompressedName[x];
		hexbuf[1] = 0;
		UncompressedName[x] = 'A' + (BYTE)strtoul(hexbuf, &ptr, 16);;
	}

	UncompressedName[33] = 0;
#if 0
	// add SCOPE_ID 
	UncompressedName[33] = 7;
	memcpy((char *)&UncompressedName[34], "NETBIOS", 7);

	UncompressedName[41] = 3;
	memcpy((char *)&UncompressedName[42], "COM", 3);
#endif

	// set the length
	x = 34;

	memcpy(dest, UncompressedName, x);

	return x;
}


void PrintServiceDescription(char *Name, BOOL GroupName)
{
	switch ((unsigned char)Name[15])
	{
	case 0x0:
		if (GroupName )
			printf("Domain Name\n");
		else
		{
			if (memcmp(Name, "IS~", 3) == 0)
				printf("IIS\n");
			else
				printf("Workstation service (name)\n");
		}
		break;
	case 0x1:
		if (GroupName )
			printf("Master Browser\n");
		else
			printf("Messenger Service \n");
		break;
	case 0x3:
		if (!GroupName)
			printf("Messenger Service \n");
		break;
	case 0x6:
		if (!GroupName)
			printf("RAS Server Service \n");
		break;
	case 0x1B:
		if (!GroupName)
			printf("Domain Master Browser (PDC name)\n");
		break;
	case 0x1C:
		if (GroupName )
			if (memcmp(Name, "INet~", 5) == 0)
				printf("IIS\n");
			else
				printf("Domain Controller\n");
		break;
	case 0x1D:
		if (!GroupName)
			printf("Master Browser\n");
		break;
	case 0x1E:
		if (GroupName )
			printf("Browser Service Elections\n");
		break;
	case 0x1F:
		if (!GroupName)
			printf ("NetDDE Service \n");
		break;
	case 0x20:
		if (!GroupName)
			printf("File Server Service \n");
		break;
	case 0x21:
		if (!GroupName)
			printf("RAS Client Service \n");
		break;
	case 0x22:
		if (!GroupName)
			printf("Microsoft Exchange Interchange(MSMail Connector)\n");
		break;
	case 0x23:
		if (!GroupName)
			printf("Microsoft Exchange Store\n");
		break;
	case 0x24:
		if (!GroupName)
			printf("Microsoft Exchange Directory\n");
		break;
	case 0x2B:
		if (!GroupName)
			printf("Lotus Notes Server Service\n");
		break;
	case 0x2F:
		if (!GroupName && memcmp(Name, "IRISMULTICAST", 13) == 0)
			printf("Lotus Notes\n");
		break;
	case 0x30:
		if (!GroupName)
			printf("Modem Sharing Server Service\n");
		break;
	case 0x31:
		if (!GroupName)
			printf("Modem Sharing Client Service \n");
		break;
	case 0x33:
		if (!GroupName && memcmp(Name, "IRISNAMESERVER", 14) == 0)
			printf("Lotus Notes\n");
		break;
	case 0x43:
		if (!GroupName)
			printf("SMS Clients Remote Control\n");
		break;
	case 0x44:
		if (!GroupName)
			printf("SMS Administrators Remote Control Tool\n");
		break;
	case 0x45:
		if (!GroupName)
			printf("SMS Clients Remote Chat\n");
		break;
	case 0x46:
		if (!GroupName)
			printf("SMS Clients Remote Transfer\n");
		break;
	case 0x4C:
	case 0x52:
		if (!GroupName)
			printf("DEC Pathworks TCPIP service on Windows NT\n");
		break;
	case 0x6A:
		if (!GroupName)
			printf("Microsoft Exchange IMC\n");
		break;
	case 0x87:
		if (!GroupName)
			printf("Microsoft Exchange MTA\n");
		break;
	case 0xBE:
		if (!GroupName)
			printf("Network Monitor Agent\n");
		break;
	case 0xBF:
		if (!GroupName)
			printf("Network Monitor Application (utility)\n");
		break;
	}

}
			

// waits for a response block of BytesExpected with timeout
int GetResponse(SOCKET sock, int BytesExpected, char *buff, int buffsize)
{
	int x, nRead;
	BOOL b;
	DWORD  d;
	time_t TimerStart;

	// timer start
	TimerStart = time(NULL);

	// b is flag used as a dropout value, true while loop should continue
	b = TRUE;

	nRead = 0;

	do
	{
		x = recv(sock, buff + nRead, buffsize - nRead, 0);

		if (x == 0)
			// connection closed
			b = FALSE;
		else if (x == SOCKET_ERROR)
		{
			d = GETSOCKETERROR();

			// check if error is a blocking error
			if (d != SOCKETBLOCKINGERROR )
				b = FALSE;
			else
				// sleep to avoid heavy CPU usage
				SLEEP(SLEEPTIME);
		} 
		else 
		{
			nRead += x;
		}
	}
	while (	b && nRead < BytesExpected && time(NULL) - TimerStart < SOCKS5TIMEOUT);

	// check for error
	if (b == FALSE)
	{
		return SOCKET_ERROR;
	}

	if (nRead < sizeof(SOCKS5RESPONSE))
	{
		// timeout or error occured
		CLOSESOCKET(sock);
		return SOCKET_ERROR;
	}

	// return success
	return 0;
}


int socks5udpassociate(SOCKET sock, const struct sockaddr *  proxyname,  int namelen, DWORD destadr, WORD destport, char *username, char*password )
{
	int ret = 0;
	char buff[1024];
	PSOCKS5GREET pgreetstruct = (PSOCKS5GREET)buff;
	PSOCKS5RESPONSE presponsestruct; 
	PSOCKS5IP4REQ pIP4Req;
	char *ptr;
	unsigned long l;


	if (username == NULL)
		username = "";

	if (password == NULL)
		password = "";

	// connect to socks proxy
	ret = connect(sock, proxyname, namelen);

	if (ret == SOCKET_ERROR)
	{
		printf("Error %d connecting to proxy server\n", GETSOCKETERROR() );
		return SOCKET_ERROR;
	}

	// set non-blocking mode
	l = 1;
#ifdef WIN32
	ioctlsocket(sock, FIONBIO , &l);
#else
	fcntl(sock, F_SETFL, O_NONBLOCK);
#endif


	// fill in greet struct
	pgreetstruct->Ver = SOCKS5VER; // socks 5
	pgreetstruct->nMethods = 2; // currently only no auth or userpass plaintext

	ptr = buff + sizeof(SOCKS5GREET);

	*ptr = SOCKS5AUTH_NONE;	
	ptr++;
	*ptr = SOCKS5AUTH_USERPASS;

	// send greet
	if (send(sock, buff, sizeof(SOCKS5GREET) + pgreetstruct->nMethods, 0 ) == SOCKET_ERROR)
	{
		printf("Error %d sending greeting to proxy server\n", GETSOCKETERROR() );
		CLOSESOCKET(sock);
		return SOCKET_ERROR;
	}

	// wait for response
	ret = GetResponse(sock, sizeof(SOCKS5RESPONSE), buff, sizeof(buff));

	if (ret == SOCKET_ERROR)
	{
		printf("Error getting greeting response from proxy server\n");
		return SOCKET_ERROR;
	}

	presponsestruct = (PSOCKS5RESPONSE)buff;

	// check for appropriate packet
	if (presponsestruct->Ver != SOCKS5VER )
	{
		printf("Bad greeting response from proxy server\n");
		CLOSESOCKET(sock);
		return SOCKET_ERROR;
	}

	// process authentication type (currently only supports none or plaintext)
	switch (presponsestruct->Stat)
	{
	case SOCKS5AUTH_NONE:
		// nothing to be done...
		break;
	case SOCKS5AUTH_USERPASS:
		ptr = buff;
		// create authentication packet
		*ptr = SOCKS5AUTH_USERPASS;	// subnegotiation version
		ptr++;
		*ptr = strlen(username) + 1;	// length of username
		ptr++;
		strcpy(ptr, username);			// username
		ptr += strlen(username) + 1;
		*ptr = strlen(password) + 1;	// length of password
		ptr++;
		strcpy(ptr, password);			// password
		ptr += strlen(password) + 1;

		// send authentication packet
		if (send(sock, buff, ptr - buff, 0 ) == SOCKET_ERROR)
		{
			printf("Error %d sending authentication to proxy server\n", GETSOCKETERROR() );
			CLOSESOCKET(sock);
			return SOCKET_ERROR;
		}

		// get response
		ret = GetResponse(sock, sizeof(SOCKS5RESPONSE), buff, sizeof(buff));

		if (ret == SOCKET_ERROR)
		{
			printf("Error getting authentication response from proxy server\n");
			return SOCKET_ERROR;
		}

		presponsestruct = (PSOCKS5RESPONSE)buff;

		// check for proper header
		if (presponsestruct->Ver != SOCKS5VER)
		{
			printf("Bad authentication response from proxy server\n" );
			return SOCKET_ERROR;
		}

		// check for success
		if (presponsestruct->Stat != SOCKS5ERROR_SUCCESS)
		{
			printf("Proxy uthentication failed\n");
			return SOCKET_ERROR;
		}

		break;
	default:
		// unknown type returned or error
		printf("Error response durring subnegotiation from proxy\n");
		CLOSESOCKET(sock);
		return SOCKET_ERROR;
		break;
	}

	// form connect request packet
	pIP4Req = (PSOCKS5IP4REQ)buff;

	pIP4Req->Ver = SOCKS5VER;
	pIP4Req->Command = SOCKS5CMD_UDPASSOC;
	pIP4Req->Reserved = 0;
	pIP4Req->AddressType = SOCKS5ADRTYPE_IPV4ADDR;
	pIP4Req->Address = destadr;
	pIP4Req->Port = htons(destport);


	// send udp associate request
	if (send(sock, buff, sizeof(SOCKS5IP4REQ), 0 ) == SOCKET_ERROR)
	{
		printf("Error %d sending UDP association request to proxy server\n", GETSOCKETERROR() );
		CLOSESOCKET(sock);
		return SOCKET_ERROR;
	}

	// wait for response
	ret = GetResponse(sock, sizeof(SOCKS5IP4REQ), buff, sizeof(buff));

	if (ret == SOCKET_ERROR)
	{
		printf("Error getting response from udp associate request from proxy server\n");
		return SOCKET_ERROR;
	}

	// check response
	pIP4Req = (PSOCKS5IP4REQ)buff;

	// check for proper header
	if (pIP4Req->Ver != SOCKS5VER)
	{
		printf("Bad udp associate response from proxy server\n");
		CLOSESOCKET(sock);
		return SOCKET_ERROR;
	}

	// check success
	if (pIP4Req->Command != SOCKS5ERROR_SUCCESS)
	{
		printf("Error UDP associate response from proxy server\n");
		CLOSESOCKET(sock);
		return SOCKET_ERROR;
	}

	g_ProxyUDPPort = pIP4Req->Port;

	// return zero, success
	return 0;
}



int SendPacket(SOCKET sock, const char *buff, DWORD PacketLen, LPSOCKADDR_IN pdestaddr)
{
	char outbuff[6666];
	PSOCKS5IP4UDPHEADER pudpheader = (PSOCKS5IP4UDPHEADER)outbuff;
	SOCKADDR_IN sockaddr;
	DWORD SendSize = PacketLen;

	if (g_ProxyIP != 0)
	{
		pudpheader->Reserved = 0;
		pudpheader->AddressType = SOCKS5ADRTYPE_IPV4ADDR;
		pudpheader->Frag = 0;
		pudpheader->Address = pdestaddr->sin_addr.s_addr;
		pudpheader->Port = pdestaddr->sin_port;

		memcpy(outbuff + sizeof(SOCKS5IP4UDPHEADER), buff, PacketLen);

		SendSize += sizeof(SOCKS5IP4UDPHEADER);

		sockaddr.sin_family = AF_INET;
		sockaddr.sin_addr.s_addr = g_ProxyIP;
		sockaddr.sin_port = g_ProxyUDPPort;
	} 
	else 
	{
		memcpy(outbuff, buff, PacketLen);
		memcpy(&sockaddr, pdestaddr, sizeof(SOCKADDR_IN) );
	}


	return sendto(sock, outbuff, SendSize, 0, (LPSOCKADDR)&sockaddr, sizeof(SOCKADDR_IN) );
}

DWORD FormPacket(unsigned char *buff, WORD TranID, BYTE Opcode, char *QuestionName, WORD QuestionType, BOOL fResponse, BOOL fBroadcast, BOOL fTruncated, BOOL fRecursionAvailable, BOOL fRecursionDesired, BOOL fAuthoratativeAnswer, WORD RCode, WORD QDCount, WORD ANCount, WORD NSCount, WORD ARCount, DWORD TargetIP, BOOL fGroup, BYTE ONT)
{
	NBFLAGS nbflags;
	PNBNAMEHEADER pnbnameheader = (PNBNAMEHEADER)buff;
	OPCODEFLAGSRCODE Wcode;
	BYTE *ptr, *firstnameptr = NULL;
	DWORD d;
	WORD w;

	memset(pnbnameheader, 0, sizeof(NBNAMEHEADER) );

	pnbnameheader->TransactionID = TranID;	// Transaction ID

	Wcode.fResponse = fResponse;		// request not response
	Wcode.OpCode = Opcode;				// operation code (command)
	Wcode.fNM_00 = 0;					// always 0
	Wcode.fNM_B = fBroadcast;			// broadcast
	Wcode.fNM_RA = fRecursionAvailable;	// always 0 for requests
	Wcode.fNM_RD = fRecursionDesired;	// no recursion requested
	Wcode.fNM_TC = fTruncated;			// not truncated
	Wcode.fNM_AA = fAuthoratativeAnswer;// always 0 for requests
	Wcode.RCode = RCode;

	pnbnameheader->OpcodeFlagsRcode = htons(*((WORD*)&Wcode));

	pnbnameheader->QDCount = htons(QDCount);
	pnbnameheader->ANCount = htons(ANCount);
	pnbnameheader->ARCount = htons(ARCount);
	pnbnameheader->NSCount = htons(NSCount);

	ptr = (BYTE *)(pnbnameheader + 1);

	if (QDCount > 0)
	{
		PQUESTION pquestion = (PQUESTION)ptr;

		StringToNetbiosName((char *)pquestion->Name, QuestionName, QuestionName[15]);

		firstnameptr = pquestion->Name;

		pquestion->Type = htons(QuestionType);
		pquestion->Class = htons(QUESTION_CLASS_IN);
		
		ptr += sizeof(QUESTION);
	}

	if (ANCount > 0)
	{
		d = StringToNetbiosName((char *)ptr, QuestionName, QuestionName[15]);

		ptr += d;

		PRESOURCERECORDHEADER presrecordheader = (PRESOURCERECORDHEADER)ptr;

		presrecordheader->Class = htons(RRCLASS_IN);
		presrecordheader->RDLength = htons(6);
		presrecordheader->TTL = 0;
		presrecordheader->Type = htons(RRTYPE_NB);

		ptr += sizeof(RESOURCERECORDHEADER);

		nbflags.fGroup = fGroup;
		nbflags.Reserved = 0;
		nbflags.ONT = ONT;
		
		memcpy(&w, &nbflags, sizeof(WORD) );

		w = htons(w);

		memcpy(ptr, &w, sizeof(WORD));

		ptr += sizeof(WORD);

		*((DWORD *)ptr) = TargetIP;

		ptr += sizeof(DWORD);
	}

	if (ARCount > 0)
	{
		if (firstnameptr == NULL)
		{
			d = StringToNetbiosName((char *)ptr, QuestionName, QuestionName[15]);
			ptr += d;
		}
		else
		{
			*((WORD *)ptr) = htons(0xC000 | (firstnameptr - buff));
			ptr+=2;
		}

		PRESOURCERECORDHEADER presrecordheader = (PRESOURCERECORDHEADER)ptr;

		presrecordheader->Class = htons(RRCLASS_IN);
		presrecordheader->RDLength = htons(6);
		presrecordheader->TTL = 0;
		presrecordheader->Type = htons(RRTYPE_NB);

		ptr += sizeof(RESOURCERECORDHEADER);

		nbflags.fGroup = fGroup;
		nbflags.Reserved = 0;
		nbflags.ONT = ONT;
		
		memcpy(&w, &nbflags, sizeof(WORD) );

		w = htons(w);

		memcpy(ptr, &w, sizeof(WORD));

		ptr += sizeof(WORD);

		*((DWORD *)ptr) = TargetIP ;
		

		ptr += sizeof(DWORD);
	}

	return (DWORD)(ptr - buff);
}


DWORD FormNegativeQueryResponsePacket(unsigned char *buff, WORD TransactionID, char *NameBuff, WORD Rcode, DWORD RespondIP, BYTE ONT)
{
	return FormPacket(buff, TransactionID, OPCODE_REGISTRATION, NameBuff, QUESTION_TYPE_NB, TRUE, FALSE, FALSE, TRUE, TRUE, TRUE, Rcode, 0, 1, 0, 0, RespondIP , 0, ONT);
}


DWORD FormQueryResponsePacket(unsigned char *buff, WORD TransactionID, char *NameBuff, DWORD RespondIP, BYTE ONT )
{
	return FormPacket(buff, TransactionID, OPCODE_QUERY, NameBuff, QUESTION_TYPE_NB, TRUE, FALSE, FALSE, FALSE, TRUE, TRUE, 0, 0, 1, 0, 0, RespondIP, 0, ONT);
}


DWORD FormNameReleasePacket(unsigned char *buff, char *NameBuff, DWORD DestAddr, BOOL bGroupName, BYTE ONT)
{
	return FormPacket(buff, rand(), OPCODE_RELEASE, NameBuff, QUESTION_TYPE_NB, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, 0, 1, 0, 0, 1, DestAddr, bGroupName, ONT);
}


DWORD FormNameQueryPacket(unsigned char *buff, char *NameBuff, BOOL Broadcast)
{
	return FormPacket(buff, rand(), OPCODE_QUERY, NameBuff, QUESTION_TYPE_NB, FALSE, Broadcast, FALSE, FALSE, TRUE, FALSE, 0, 1, 0, 0, 0, 0, 0, ONT_BNODE);
}


DWORD FormNBSTATPacket(unsigned char *buff)
{
	return FormPacket(buff, rand(), OPCODE_QUERY, WILDCARDNAME, QUESTION_TYPE_NBSTAT, FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, 0, 1, 0, 0, 0, 0, 0, ONT_BNODE);
}


DWORD ProcessResourceRecord(PNBNAMEHEADER pnbnameheader, const BYTE *ptr, int Type, SOCKET sock, LPSOCKADDR_IN psockaddr, int PacketLeft)
{
	BYTE outbuff[1024];
	char NameBuff[256];
	WORD w, RRType, RRClass, RRRDLength, NameFlags;
	DWORD d, RRTTL;
	BYTE NumNames;
	BYTE BinVal;
	NETBIOSNAMEFLAGS NameFlagsStruct;
	NBFLAGS nbflags;
	int x;
	static DWORD LastOutIP = 0;
	static DWORD LastSpawnIP = 0;

	d = NetbiosNameToString(NameBuff, ptr, PacketLeft);

	if (d == 0) return 0;

	PrintNetbiosName((BYTE *)NameBuff);
	puts("");
	ptr += d;

	if (PacketLeft - d < sizeof(RESOURCERECORDHEADER) || PacketLeft - d < sizeof(RESOURCERECORDHEADER) + ntohs(((PRESOURCERECORDHEADER)ptr)->RDLength) )
	{
		puts("[Short record, aborting]");
		return 0;
	}

	PRESOURCERECORDHEADER presrecordheader = (PRESOURCERECORDHEADER)ptr;


	RRType = ntohs(presrecordheader->Type);
	RRClass = ntohs(presrecordheader->Class);
	RRTTL = ntohl(presrecordheader->TTL);
	RRRDLength = ntohs(presrecordheader->RDLength);

	ptr = (LPBYTE)(presrecordheader+1);


	switch (RRType)
	{
	case RRTYPE_A:
		printf("IP Address Resource Record:\n");
		break;
	case RRTYPE_NS:
		printf("Name Service Resource Record:\n");
		break;
	case RRTYPE_NULL:
		printf("NULL Resource Record:\n");
		break;
	case RRTYPE_NB	:
		printf("NetBIOS Name Service Resource Record:\n");
		break;
	}


	switch (RRType)
	{
	case RRTYPE_A:
	case RRTYPE_NS:
		break;
	case RRTYPE_NULL:
	case RRTYPE_NB	:

		for (x = 0; x < RRRDLength / 6; x++)
		{
			memcpy(&w, ptr, sizeof(w) );
			w = ntohs(w);
			memcpy(&nbflags, &w, sizeof(w) );
			ptr += sizeof(WORD);

			printf("Owner Node Type: ");
			switch (nbflags.ONT)
			{
			case ONT_BNODE:
				printf("B-NODE ");
				break;
			case ONT_PNODE:
				printf("P-NODE ");
				break;
			case ONT_MNODE:
				printf("M-NODE ");
				break;
			case ONT_HNODE:
				printf("H-NODE ");
			}

			printf("  ");

			if (nbflags.fGroup)
				printf("GROUP  ");
			else
				printf("UNIQUE ");

			printf("  -  ");

			printf("IP: %u.%u.%u.%u", *ptr, *(ptr+1), *(ptr+2),*(ptr+3));

			ptr+=4;

			puts("");

		}

		break;
	case RRTYPE_NBSTAT:
		{
			FILE *outfile = NULL;

			printf("Node Status Resource Record:\n");
			NumNames = *ptr;
			ptr++;
			PNETBIOSNAME pnetbiosname = (PNETBIOSNAME)ptr;

			if (g_ASOutFile != NULL)
			{
				outfile = fopen(g_ASOutFile, "at");
				if (outfile != NULL)
				{
					time_t curtime = time(NULL);
					fprintf(outfile, "ASTAT response from %s at %s", inet_ntoa(psockaddr->sin_addr), ctime(&curtime) );
				}
			}


			for (w = 0; w < NumNames; w++)
			{
				char *tptr;
				BinVal = pnetbiosname->BinVal;
				pnetbiosname->BinVal = 0;

				printf("%s <%02x>  ", pnetbiosname->Name, BinVal );

				if (outfile != NULL)
					fprintf(outfile, "%s <%02x>  ", pnetbiosname->Name, BinVal );

				pnetbiosname->BinVal = BinVal;

				NameFlags = ntohs(pnetbiosname->Flags);
				memcpy(&NameFlagsStruct, &NameFlags, sizeof(NameFlags) );
				if (NameFlagsStruct.fActive)
					tptr = "ACTIVE   ";
				else
					tptr = "INACTIVE ";

				printf("%s", tptr);
				if (outfile != NULL)
					fprintf(outfile, "%s", tptr);

				if (NameFlagsStruct.fGroupName)
					tptr = "GROUP  ";
				else
					tptr = "UNIQUE ";

				printf("%s", tptr);
				if (outfile != NULL)
					fprintf(outfile, "%s", tptr);

				if (NameFlagsStruct.fPermanent)
					tptr = "PERMANENT ";
				else
					tptr = "NOTPERM   ";

				printf("%s", tptr);
				if (outfile != NULL)
					fprintf(outfile, "%s", tptr);

				if (NameFlagsStruct.fConflict)
					tptr = "INCONFLICT ";
				else
					tptr = "NOCONFLICT ";

				printf("%s", tptr);
				if (outfile != NULL)
					fprintf(outfile, "%s", tptr);


				if (NameFlagsStruct.fDeregister)
					tptr = "DEREGISTERED ";
				else
					tptr = "NOTDEREGED   ";

				printf("%s", tptr);
				if (outfile != NULL)
					fprintf(outfile, "%s", tptr);


				switch (NameFlagsStruct.OwnerType)
				{
				case ONT_BNODE:
					tptr = "B-NODE ";
					break;
				case ONT_PNODE:
					tptr = "P-NODE ";
					break;
				case ONT_MNODE:
					tptr = "M-NODE ";
					break;
				case ONT_HNODE:
					tptr = "H-NODE ";
				}

				printf("%s\n", tptr);
				if (outfile != NULL)
					fprintf(outfile, "%s\n", tptr);

				pnetbiosname->BinVal = BinVal;

				if (g_SvcDesc)
					PrintServiceDescription(pnetbiosname->Name, NameFlagsStruct.fGroupName);


				if (!NameFlagsStruct.fGroupName && g_OutSvcFile != NULL && BinVal == g_OutSvcVal && LastOutIP != psockaddr->sin_addr.s_addr && memcmp(pnetbiosname->Name, "IS~", 3) != 0)
				{
					LastOutIP = psockaddr->sin_addr.s_addr;

					FILE *outfile2 = fopen(g_OutSvcFile, "at");

					if (outfile2 != NULL)
					{
						pnetbiosname->BinVal = 0;

						fprintf(outfile2, "%s %s\n", inet_ntoa(psockaddr->sin_addr), pnetbiosname->Name);

						pnetbiosname->BinVal = BinVal;

						fclose(outfile2);

						printf(" **** Machine added to %s\n", g_OutSvcFile );
					}
				}

				if (!NameFlagsStruct.fGroupName && g_OutSvcFile != NULL && BinVal == g_SpawnSvcVal && LastSpawnIP != psockaddr->sin_addr.s_addr && memcmp(pnetbiosname->Name, "IS~", 3) != 0)
				if (!NameFlagsStruct.fGroupName && BinVal == g_SpawnSvcVal )
				{
					LastSpawnIP = psockaddr->sin_addr.s_addr;

					if (g_SpawnCommand != NULL)
					{
						char buff[1024];

						pnetbiosname->BinVal = 0;

						sprintf(buff, "%s", inet_ntoa(psockaddr->sin_addr));
#ifdef WIN32

						if (_spawnlpe(_P_NOWAIT, g_SpawnCommand, g_SpawnCommand, g_SpawnArgs, pnetbiosname->Name, buff, NULL, NULL) == -1)
							printf(" *** Error spawning \"%s\"\n", g_SpawnCommand);
						else
						{
							printf(" **** Spawned \"%s\"\n", g_SpawnCommand);
						}
#else
						if (fork() == 0)
							if (execlp(g_SpawnCommand, g_SpawnCommand, g_SpawnArgs, pnetbiosname->Name, buff, NULL) == -1 )
							{
								printf(" *** Error spawning \"%s %s %s %s\"\n", g_SpawnCommand, g_SpawnArgs, pnetbiosname->Name, buff );
								exit(0);
							}
#endif

						pnetbiosname->BinVal = BinVal;
						SLEEP(20);
					}
				}

				
				if (g_Conflict && !NameFlagsStruct.fConflict )
				{
					d = FormNameReleasePacket(outbuff, pnetbiosname->Name, psockaddr->sin_addr.s_addr, NameFlagsStruct.fGroupName, NameFlagsStruct.OwnerType);

					SendPacket(sock, (const char *)outbuff, d, psockaddr);

					printf(" **** Name release sent to %s\n", inet_ntoa(psockaddr->sin_addr) );
				}

				pnetbiosname++;
			}


			PNETBIOSSTATS pnetbiosstats = (PNETBIOSSTATS)pnetbiosname;

			printf("MAC Address:             %02X-%02X-%02X-%02X-%02X-%02X\n", pnetbiosstats->UnitID[0], pnetbiosstats->UnitID[1], pnetbiosstats->UnitID[2], pnetbiosstats->UnitID[3], pnetbiosstats->UnitID[4], pnetbiosstats->UnitID[5] );
			if (outfile != NULL)
				fprintf(outfile, "MAC Address:             %02X-%02X-%02X-%02X-%02X-%02X\n\n", pnetbiosstats->UnitID[0], pnetbiosstats->UnitID[1], pnetbiosstats->UnitID[2], pnetbiosstats->UnitID[3], pnetbiosstats->UnitID[4], pnetbiosstats->UnitID[5] );

#ifdef STUFFTHATSUSUALLYALLZERO
			printf("\nStatistics:\n");
			printf("Jumpers:                 0x%02x\n", pnetbiosstats->Jumpers);
			printf("Test result:             0x%02x\n", pnetbiosstats->TestResult);
			printf("Version:                 %d.%d\n", HIBYTE(pnetbiosstats->Version), LOBYTE(pnetbiosstats->Version) );
			printf("Stats period:            0x%04x\n", ntohs(pnetbiosstats->StatsPeriod) );
			printf("Num CRCs:                %u\n", ntohs(pnetbiosstats->NumCRCs ) );
			printf("Num Alignment errs:      %u\n", ntohs(pnetbiosstats->NumAlignmentErrors ) );
			printf("Num Collisions:          %u\n", ntohs(pnetbiosstats->NumCollisions ) );
			printf("Num Send Aborts:         %u\n", ntohs(pnetbiosstats->NumSendAborts ) );
			printf("Num Good Sends:          %u\n", ntohl(pnetbiosstats->NumGoodSends ) );
			printf("Num Good Receives:       %u\n", ntohl(pnetbiosstats->NumGoodRcvs ) );
			printf("Num Retransmits:         %u\n", ntohs(pnetbiosstats->NumRetransmits ) );
			printf("Num Resource Conditions: %u\n", ntohs(pnetbiosstats->NumResourceConditions ) );
			printf("Free Command Blocks:     %u\n", ntohs(pnetbiosstats->NumFreeCommandBlocks ) );
			printf("Total Command Blocks:    %u\n", ntohs(pnetbiosstats->NumCommandBlocks ) );
			printf("Max Command Blocks       %u\n", ntohs(pnetbiosstats->NumMaxCommandBlocks ) );
			printf("Pending Sessions:        %u\n", ntohs(pnetbiosstats->NumPendingSessions ) );
			printf("Max Pending Sessions:    %u\n", ntohs(pnetbiosstats->NumMaxPendingSessions ) );
			printf("Max Total Sessions:      %u\n", ntohs(pnetbiosstats->NumMaxTotalSessions ) );
			printf("Session Data Packet Size:%u\n", ntohs(pnetbiosstats->SessionDataPacketSize ) );
#endif

			if (outfile != NULL)
			{
				fclose(outfile);
				outfile = NULL;
			}

		}
		break;
	default:
		printf("Unknown resource record type: 0x%04x\n", RRType);
		break;
	}

	{
		WORD w;
		OPCODEFLAGSRCODE Wcode;

		w = ntohs(pnbnameheader->OpcodeFlagsRcode);

		memcpy(&Wcode, &w, sizeof(w) );


		if (g_AstatBack && RRType == RRTYPE_NB && Wcode.OpCode == OPCODE_QUERY && Wcode.fResponse)
		{
			d = FormNBSTATPacket(outbuff);

			SendPacket(sock, (const char *)outbuff, d, psockaddr);

			printf(" **** NBSTAT request packet sent\n");
		}
	}


	return d + RRRDLength + sizeof(RESOURCERECORDHEADER);
}


DWORD ProcessPacket(char *buff, int packetsize, SOCKET sock, LPSOCKADDR_IN psockaddr)
{
	char NameBuff[256];
	PNBNAMEHEADER pnbnameheader = (PNBNAMEHEADER)buff;
	OPCODEFLAGSRCODE Wcode;
	WORD w, QDCount, ANCount, NSCount, ARCount, RCode, OPCode;
	BOOL fResponse, fBroadcast, fRecursionAvailable, fRecursionDesired, fTruncated, fAuthoratativeAnswer;
	const BYTE *ptr;
	DWORD d;

	if (packetsize < sizeof(NBNAMEHEADER) )
	{
		puts("[Short packet, aborting]");
		return 0;
	}

	QDCount = ntohs(pnbnameheader->QDCount);
	ANCount = ntohs(pnbnameheader->ANCount);
	ARCount = ntohs(pnbnameheader->ARCount);
	NSCount = ntohs(pnbnameheader->NSCount);

	w = ntohs(pnbnameheader->OpcodeFlagsRcode);

	memcpy(&Wcode, &w, sizeof(w) );

	RCode = Wcode.RCode;

	OPCode = Wcode.OpCode;

	fResponse = Wcode.fResponse;
	fBroadcast = Wcode.fNM_B;
	fRecursionAvailable = Wcode.fNM_RA;
	fRecursionDesired = Wcode.fNM_RD;
	fTruncated = Wcode.fNM_TC;
	fAuthoratativeAnswer = Wcode.fNM_AA;

	ptr = (const BYTE *)(pnbnameheader+1);

	if (RCode != 0)
	{
		printf("RCode: ");

		switch (RCode)
		{
		case RCODE_FMTERR:
			printf("Format Error: Request was invalidly formatted");
			break;
		case RCODE_SRVERR:
			printf("Server Failure: Problem with NBNS, cannot process name");
			break;
		case RCODE_NAMERR:
			printf("Name Error: The name requested does not exist.");
			break;
		case RCODE_IMPERR:
			printf("Unsupported Request Error");
			break;
		case RCODE_RFSERR:
			printf("Refused Error.  For policy reasons server will not register this name from this host.");
			break;
		case RCODE_ACTERR:
			printf("Active Error.  Name is owned by another node.");
			break;
		case RCODE_CFTERR:
			printf("Name in Conflict Error.  A UNIQUE name is owned by more than one node.");
			break;
		default:
			printf("Unknown RCODE! 0x%04x", RCode);
			break;
		}

		puts("");
	}


	printf("OPCode: ");
	switch (OPCode)
	{
	case OPCODE_QUERY:
		printf("QUERY");
		break;
	case OPCODE_REGISTRATION:
		printf("REGISTRATION");
		break;
	case OPCODE_RELEASE:
		printf("RELEASE");
		break;
	case OPCODE_WACK:
		printf("WACK");
		break;
	case OPCODE_REFRESH:
		printf("REFRESH");
		break;
	default:
		printf("Unknown OPCODE! 0x%04x", OPCode);
		break;
	}
	puts("");

	printf("Flags: ");
	if (fResponse)
		printf("Response ");

	if (fBroadcast)
		printf("Broadcast ");

	if (fRecursionAvailable)
		printf("RecursionAvailable ");

	if (fRecursionDesired)
		printf("RecursionDesired ");

	if (fTruncated)
		printf("Truncated ");

	if (fAuthoratativeAnswer)
		printf("AuthoratativeAnswer ");

	puts("");

	// all packets I've seen have no more than 1 of any type of record
	if (QDCount > 1 || ANCount > 1 || NSCount > 1 || ARCount > 1)
	{
		puts("[Invalid record count, aborting]");
		return 0;
	}

	for (w = 0; w < QDCount; w++)
	{
		printf("Question[%d]:\n", w);

		if (packetsize - (int)((char *)ptr - buff) < sizeof(QUESTION))
		{
			puts("[Short packet, aborting]");
			return 0;
		}

		PQUESTION pquestion = (PQUESTION)ptr;

		d = NetbiosNameToString(NameBuff, pquestion->Name, packetsize - ((char *)ptr - buff));

		ptr += sizeof(QUESTION);

		PrintNetbiosName((BYTE *)NameBuff);
		puts("");

		switch (ntohs(pquestion->Type))
		{
		case QUESTION_TYPE_NB:
			printf("General name request");
			break;
		case QUESTION_TYPE_NBSTAT:
			printf("Netbios Stats request");
			break;
		default:
			printf("Unknown query type:0x%04x", ntohs(pquestion->Type) );
			break;
		}

		puts("");

		if (ntohs(pquestion->Class) != QUESTION_CLASS_IN )
			printf("Class != TYPE INTERNET!\n");

		if (g_Reverse && !fResponse && ntohs(pquestion->Type) == QUESTION_TYPE_NBSTAT)
		{
			BYTE outbuff[1024];

			d = FormNBSTATPacket(outbuff);

			SendPacket(sock, (const char *)outbuff, d, psockaddr);

			printf(" **** NBSTAT QUERY packet sent to %s\n", inet_ntoa(psockaddr->sin_addr));
		}


		if (g_RespondName != NULL && !fResponse && OPCode == OPCODE_QUERY && ntohs(pquestion->Type) == QUESTION_TYPE_NB)
		{
			BYTE outbuff[1024];
			BOOL DoResponce = FALSE;
			char RespNameBuff[16];
			DWORD RespondIP = g_RespondIP;

			ParamToNetbiosName(RespNameBuff, g_RespondName);

			if ( strcmp(g_RespondName, "*") == 0 || memcmp(RespNameBuff, NameBuff, 16) == 0)
				DoResponce = TRUE;
			else if (access(g_RespondName, 3) == 0)
			{
				FILE *InFile = fopen(g_RespondName, "rt");

				if (InFile == NULL)
					printf("Unable to open %s\n", g_RespondName);
				else
				{
					char InBuff[1024];

					while (DoResponce == FALSE && fgets(InBuff, 1024, InFile) != NULL)
					{
						char *p = strchr(InBuff, '\n');
						if (p) *p = 0;
						p = strchr(InBuff, '#');
						if (p) *p = 0;

						if (inet_addr(InBuff) != INADDR_NONE)
						{
							RespondIP = inet_addr(InBuff);
							p = strchr(InBuff, ' ');

							if (p == NULL) 
								p = InBuff + strlen(InBuff);
						} 
						else 
						{
							p = InBuff;
						}

						ParamToNetbiosName(RespNameBuff, p);

						if (memcmp(RespNameBuff, NameBuff, 16) == 0)
							DoResponce = TRUE;
					}

					fclose(InFile);
				}
			}


			if (DoResponce)
			{
				d = FormQueryResponsePacket(outbuff, pnbnameheader->TransactionID, NameBuff, RespondIP, ONT_BNODE );

				SendPacket(sock, (const char *)outbuff, d, psockaddr);

				struct in_addr tmpadr;

				tmpadr.s_addr = RespondIP;

				printf(" **** QUERY responded to with address %s\n", inet_ntoa(tmpadr));
				puts("");
			}
		}



		if (g_AllowName != NULL || g_DenyName != NULL)
		{
			char AllowNameBuff[16];

			if (OPCode == OPCODE_REGISTRATION && ntohs(pquestion->Type) == QUESTION_TYPE_NB)
			{
				BOOL DoDeny = FALSE;

				if (g_DenyName != NULL)
				{
					DoDeny = TRUE;

					ParamToNetbiosName(AllowNameBuff, g_DenyName);

					if (strcmp(g_DenyName, "*") == 0 || memcmp(AllowNameBuff, NameBuff, 16) == 0)
						DoDeny = FALSE;
					else if (access(g_DenyName, 4) == 0)
					{
						FILE *InFile = fopen(g_DenyName, "rt");
						char namecheckbuff[1024];

						if (InFile == NULL)
						{
							printf(" **** Unable to open %s\n", g_DenyName);
							DoDeny = FALSE;
						}
						else
						{
							while (DoDeny == TRUE && fgets(namecheckbuff, 1024, InFile) != NULL)
							{
								char *p = strchr(namecheckbuff, '\n');
								if (p) *p = 0;

								ParamToNetbiosName(AllowNameBuff, namecheckbuff);

								if (memcmp(AllowNameBuff, NameBuff, 16) == 0)
									DoDeny = FALSE;
							}

							fclose(InFile);
						}
					}


				}

				if (g_AllowName != NULL)
				{
					DoDeny = FALSE;

					ParamToNetbiosName(AllowNameBuff, g_AllowName);

					if (memcmp(NameBuff, AllowNameBuff, 16) == 0)
						DoDeny = TRUE;
					else if (access(g_AllowName, 4) == 0)
					{
						FILE *InFile = fopen(g_AllowName, "rt");
						char namecheckbuff[1024];

						if (InFile == NULL)
							printf(" **** Unable to open %s\n", g_AllowName);
						else
						{
							while (DoDeny == FALSE && fgets(namecheckbuff, 1024, InFile) != NULL)
							{
								char *p = strchr(namecheckbuff, '\n');
								if (p) *p = 0;

								ParamToNetbiosName(AllowNameBuff, namecheckbuff);

								if (memcmp(AllowNameBuff, NameBuff, 16) == 0)
									DoDeny = TRUE;
							}

							fclose(InFile);
						}
					}
				}

				BYTE outbuff[1024];
				WORD Rcode;

				if (fRecursionDesired)
					Rcode = RCODE_CFTERR;
				else
					Rcode = RCODE_ACTERR;
					
				d = FormNegativeQueryResponsePacket(outbuff, pnbnameheader->TransactionID, NameBuff, Rcode, MAKELONG(rand(), rand()), ONT_BNODE);

				SendPacket(sock, (const char *)outbuff, d, psockaddr );

				printf(" **** DENY packet sent\n");

			}
		}
	}

	for (w = 0; w < ANCount; w++)
	{
		printf("Answer[%d]:\n", w);

		d = ProcessResourceRecord(pnbnameheader, ptr, 1, sock, psockaddr, packetsize - ((char *)ptr - buff));

		if (d == 0) return 0;

		ptr+=d;
	}

	for (w = 0; w < NSCount; w++)
	{
		printf("Authority record[%d]:\n", w);

		d = ProcessResourceRecord(pnbnameheader, ptr, 2, sock, psockaddr, packetsize - ((char *)ptr - buff));

		if (d == 0) return 0;

		ptr+=d;
	}

	for (w = 0; w < ARCount; w++)
	{
		printf("Additional record[%d]:\n", w);

		d = ProcessResourceRecord(pnbnameheader, ptr, 3, sock, psockaddr, packetsize - ((char *)ptr - buff));

		if (d == 0) return 0;

		ptr+=d;
	}


	return 0;
}


#ifdef WIN32
void __cdecl ScanLoopThread(void *parg)
#else
void *ScanLoopThread(void *parg)
#endif
{
	FILE *infile = NULL;
	SOCKADDR_IN sockaddr;
	SOCKET udpsock = *((SOCKET *)parg);
	char buff[1024];
	unsigned char outbuff[1024];
	DWORD d;
	int retry;

	infile = fopen(g_ScanFile, "rt");

	if (infile == NULL)
	{
		printf(" ***** Error opening %s, scan aborted.\n", g_ScanFile);
	} 
	else 
	{
		d = FormNBSTATPacket(outbuff);

		sockaddr.sin_family = AF_INET;
		sockaddr.sin_port = htons(g_DestPort);



		while (fgets(buff, 1024, infile) != NULL)
		{
			if (strlen(buff))
			{
				char *p = strchr(buff, '\n');
				if (p) *p = 0;

				sockaddr.sin_addr.s_addr = inet_addr(buff) ;
			
				if (sockaddr.sin_addr.s_addr != INADDR_NONE)
				{
					retry = 0;

					while ( retry < g_Retries && SendPacket(udpsock, (const char *)outbuff, d, &sockaddr ) == SOCKET_ERROR )
					{
						retry++;
						printf("Error %u sending to %s, Resending...\n", GETSOCKETERROR(), inet_ntoa(sockaddr.sin_addr) );
						SLEEP(500);
					}

					if (g_PacketDelay)
						if (g_DelayDrift)
							SLEEP(g_PacketDelay + (((DWORD)rand()*(DWORD)rand())%g_DelayDrift));
						else
							SLEEP(g_PacketDelay);
				} 
				else 
				{
					printf("Bad IP address: \"%s\"\n", buff);
				}
			}
		}

		printf(" **** Scan done\n");

		fclose(infile);
	}

#ifdef WIN32
	EXITTHREAD();
#else
	return NULL;
#endif
}



#ifdef WIN32
void __cdecl SweepLoopThread(void *parg)
#else
void *SweepLoopThread(void *parg)
#endif
{
	DWORD CurrentIP = g_SweepStartIP;
	DWORD d;
	unsigned char outbuff[1024];
	SOCKADDR_IN sockaddr;
	SOCKET udpsock = *((SOCKET *)parg);
	int retry;
	char checkips[256];
	char zeroblock[256];
	int x;

	memset(zeroblock, 0, sizeof(zeroblock));

	d = FormNBSTATPacket(outbuff);

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(g_DestPort);
	
	while (ntohl(CurrentIP) <= ntohl(g_SweepEndIP))
	{
		memset(checkips, 1, sizeof(checkips));

		if ( (ntohl(g_SweepStartIP) & 0xFFFFFF00) == (ntohl(CurrentIP) & 0xFFFFFF00) ) 
			for (x = 0; x < (int)((ntohl(g_SweepStartIP) & 0x000000FF)); x++)
				checkips[x] = 0;

		if ( (ntohl(g_SweepEndIP) & 0xFFFFFF00) == (ntohl(CurrentIP) & 0xFFFFFF00) )
			for ( x = (ntohl(g_SweepEndIP) & 0x000000FF) + 1; x < sizeof(checkips); x++)
				checkips[x] = 0;

		while (memcmp(checkips, zeroblock, sizeof(checkips)) != 0)
		{
			x = 0;

			if (g_RandSweep)
			{
				x = rand()%sizeof(checkips);
				while (checkips[x] == 0)
					x = rand()%sizeof(checkips);
			} 
			else 
			{
				for (x = 0; checkips[x] == 0 && x < sizeof(checkips); x++);
			}

			checkips[x] = 0;

			sockaddr.sin_addr.s_addr = htonl((ntohl(CurrentIP)&0xFFFFFF00) | x);

			retry = 0;

			while ( retry < g_Retries && SendPacket(udpsock, (const char *)outbuff, d, &sockaddr ) == SOCKET_ERROR )
			{
				retry++;
				printf("Error %u sending to %s, Resending...\n", GETSOCKETERROR(), inet_ntoa(sockaddr.sin_addr) );
				SLEEP(500);
			}

			if (g_PacketDelay)
				if (g_DelayDrift)
					SLEEP(g_PacketDelay + (((DWORD)rand()*(DWORD)rand())%g_DelayDrift));
				else
					SLEEP(g_PacketDelay);

		}

		CurrentIP = htonl((ntohl(CurrentIP) & 0xFFFFFF00) + 0x00000100); // increment IP by 1 class C
	} ;

	printf(" **** Sweep done\n");

	g_SweepEndIP = 0;

#ifdef WIN32
	EXITTHREAD();
#else
	return NULL;
#endif
}


DWORD DoLoop()
{
	BYTE buff[2046];
	BYTE inbuff[4096];
	SOCKADDR_IN sockaddr;
	HOSTENT *phostent;
	int x;
	BOOL b;
	DWORD d;
	unsigned char outbuff[1024];
	

	SOCKET udpsock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (udpsock == INVALID_SOCKET)
	{
		printf("Error %d creating socket\n", GETSOCKETERROR() );
		return 0;
	}


	b = TRUE;
	if (setsockopt(udpsock, SOL_SOCKET, SO_REUSEADDR, (const char *)&b, sizeof(b) ) == SOCKET_ERROR)
	{
		printf("Error %d setting socket option SO_REUSEADDR\n", GETSOCKETERROR() );
		CLOSESOCKET(udpsock);
		return 0;
	}

	b = TRUE;
	if (setsockopt(udpsock, SOL_SOCKET, SO_BROADCAST, (const char *)&b, sizeof(b) ) == SOCKET_ERROR)
	{
		printf("Error %d setting socket option SO_BROADCAST\n", GETSOCKETERROR() );
		CLOSESOCKET(udpsock);
		return 0;
	}


	if (g_ReceiveTimeout)
	{
#ifdef WIN32
		if (setsockopt(udpsock, SOL_SOCKET, SO_RCVTIMEO, (const char *)&g_ReceiveTimeout, sizeof(g_ReceiveTimeout) ) == SOCKET_ERROR)
#else
		struct timeval tvstruct;
		tvstruct.tv_sec = g_ReceiveTimeout/1000;
		tvstruct.tv_usec = (g_ReceiveTimeout%1000)*1000;
		if (setsockopt(udpsock, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tvstruct, sizeof(tvstruct) ) == SOCKET_ERROR)
#endif
		{
			printf("Error %d setting timeout to %d milliseconds\n", GETSOCKETERROR(), g_ReceiveTimeout );
		}
	}


	if (g_LocalIP == 0)
	{
		if (gethostname((char *)buff, sizeof(buff) ) == SOCKET_ERROR)
		{
			printf("Error %d getting local host name\n", GETSOCKETERROR() );
			CLOSESOCKET(udpsock);
			return 0;
		}

		phostent = gethostbyname((char *)buff);

		if (phostent == NULL)
		{
			printf("Error %d getting local address for name %s\n", GETSOCKETERROR(), buff );
			CLOSESOCKET(udpsock);
			return 0;
		}
		g_LocalIP = ((struct in_addr *) phostent->h_addr)->s_addr;
	}

	sockaddr.sin_addr.s_addr = g_LocalIP;
	sockaddr.sin_port = htons(g_LocalPort);
	sockaddr.sin_family = AF_INET;

	if (bind(udpsock, (LPSOCKADDR)&sockaddr, sizeof(sockaddr) ) == SOCKET_ERROR)
	{
		d = GETSOCKETERROR();
		printf("Error %u binding to port %d at address %s\n", d, g_LocalPort, inet_ntoa(sockaddr.sin_addr) );
		CLOSESOCKET(udpsock);
		return 0;
	} 
	else 
	{
		printf("Bound to port %d on address %s\n", g_LocalPort, inet_ntoa(sockaddr.sin_addr) );
	}

#ifdef WINSOCK2 
	INTERFACE_INFO ifaceinfo[500];

	if (WSAIoctl(udpsock, SIO_GET_INTERFACE_LIST, NULL, 0, &ifaceinfo, sizeof(ifaceinfo) * sizeof(INTERFACE_INFO), &d, NULL, NULL ) == SOCKET_ERROR )
	{
		printf("Error %u getting interface list, using INADDR_BROADCAST\n", WSAGetLastError() );
	} 
	else 
	{
		for (x = 0; x < (int)(d / sizeof(INTERFACE_INFO)); x++)
		{
			if (g_LocalIP == ifaceinfo[x].iiAddress.AddressIn.sin_addr.s_addr )
			{
				if (g_BroadcastIP == INADDR_BROADCAST)
					g_BroadcastIP = g_LocalIP | ~ifaceinfo[x].iiNetmask.AddressIn.sin_addr.s_addr;
				if (g_NetmaskIP == 0)
					g_NetmaskIP = ifaceinfo[x].iiNetmask.AddressIn.sin_addr.s_addr;
				break;
			}
		}
		if (x == (int)(d / sizeof(INTERFACE_INFO)))
		{
			printf("Unable to find interface %s, using INADDR_BROADCAST\n", inet_ntoa(sockaddr.sin_addr) );
		}
	}
#endif

	if (g_NetmaskIP == 0)
		g_NetmaskIP = MAKELONG(MAKEWORD(255, 255), MAKEWORD(255, 0) );
	
	if (g_RespondIP == 0)
		g_RespondIP = g_LocalIP;

	if (g_QueryIP == 0)
		g_QueryIP = g_BroadcastIP;

	{
		struct in_addr bcastadr, nmaskadr;

		bcastadr.s_addr = g_BroadcastIP;
		nmaskadr.s_addr = g_NetmaskIP;

		printf("Broadcast address: %s        ", inet_ntoa(bcastadr));
		printf("Netmask: %s\n", inet_ntoa(nmaskadr) );
	}
	
	SOCKET proxysock = INVALID_SOCKET;

	if (g_ProxyIP != 0)
	{
		proxysock = socket(AF_INET, SOCK_STREAM, 0);

		if (proxysock == INVALID_SOCKET)
		{
			printf("Error %d creating socket for proxy\n", GETSOCKETERROR());
			return 0;
		}
		else
		{
			SOCKADDR_IN proxyaddr;

			memset(&proxyaddr, 0, sizeof(proxyaddr) );

			proxyaddr.sin_family = AF_INET;
			proxyaddr.sin_addr.s_addr = g_ProxyIP;
			proxyaddr.sin_port = htons(g_ProxyPort);

			if (socks5udpassociate(proxysock, (SOCKADDR *)&proxyaddr, sizeof(proxyaddr), g_LocalIP, g_LocalPort, g_ProxyUser, g_ProxyPass) == SOCKET_ERROR)
			{
				printf("Error connecting to proxy at address %s port %d\n", inet_ntoa(proxyaddr.sin_addr), g_ProxyPort);
				return 0;
			} 
			else
			{
				printf("Relaying UDP through %s port %d\n", inet_ntoa(proxyaddr.sin_addr), ntohs(g_ProxyUDPPort));
			}
		}
	}

	if (g_AstatIP != 0)
	{
		d = FormNBSTATPacket(outbuff);

		sockaddr.sin_addr.s_addr = g_AstatIP ;
		sockaddr.sin_port = htons(g_DestPort);

		SendPacket(udpsock, (const char *)outbuff, d, &sockaddr );

		printf(" **** NBSTAT QUERY packet sent to %s\n", inet_ntoa(sockaddr.sin_addr));
	}


	if (g_QueryName)
	{
		char NameBuff[16];
		sockaddr.sin_addr.s_addr = g_QueryIP;	
		sockaddr.sin_port = htons(g_DestPort);

		ParamToNetbiosName(NameBuff, g_QueryName);

		d = FormNameQueryPacket(outbuff, NameBuff, g_QueryIP == g_BroadcastIP);

		SendPacket(udpsock, (const char *)outbuff, d, &sockaddr );

		printf(" **** NB QUERY packet for name %s sent to %s\n", g_QueryName, inet_ntoa(sockaddr.sin_addr));
	}


	if (ntohl(g_SweepEndIP) >= ntohl(g_SweepStartIP) && g_SweepStartIP != 0 && g_SweepEndIP != 0)
	{
		printf(" **** Beginning sweep...\n");

#ifdef WIN32
		CREATETHREAD(SweepLoopThread, &udpsock);
#else
		if (fork() == 0)
		{
			SweepLoopThread(&udpsock);
			exit(0);
		}
#endif
	}

	if (g_ScanFile != NULL )
	{
		if (access(g_ScanFile, 4) != 0)
		{
			printf("Unable to access %s\n", g_ScanFile);
		} 
		else 
		{
			printf(" **** Beginning scan of IPs in %s...\n", g_ScanFile);

#ifdef WIN32
			CREATETHREAD(ScanLoopThread, &udpsock);
#else
			if (fork() == 0)
			{
				ScanLoopThread(&udpsock);
				exit(0);
			}
#endif
		}

	}

	puts("");

	puts("Waiting for packets...");

	puts("");

	do
	{
		socklen_t size = sizeof(sockaddr);
		x = recvfrom(udpsock, (char *)inbuff, sizeof(inbuff), 0, (LPSOCKADDR)&sockaddr, &size);
		if (x > 0)
		{
			if ((sockaddr.sin_addr.s_addr == g_ProxyIP && sockaddr.sin_port == g_ProxyUDPPort) || (!(g_NoLocal && sockaddr.sin_addr.s_addr == g_LocalIP)  && !(g_NoLocalNet && (sockaddr.sin_addr.s_addr & g_NetmaskIP) == (g_LocalIP & g_NetmaskIP)) ))
			{
				int PacketOffset = 0;
				PSOCKS5IP4UDPHEADER pudpheader = (PSOCKS5IP4UDPHEADER)inbuff;

				if (sockaddr.sin_addr.s_addr == g_ProxyIP && sockaddr.sin_port == g_ProxyUDPPort && pudpheader->Reserved == 0)
				{
					sockaddr.sin_addr.s_addr = pudpheader->Address;
					sockaddr.sin_port = pudpheader->Port;

					PacketOffset = sizeof(SOCKS5IP4UDPHEADER);
				}

				time_t curtime = time(NULL);
				printf("**  Received %d bytes from %s:%d at %s", x - PacketOffset, inet_ntoa(sockaddr.sin_addr), ntohs(sockaddr.sin_port), ctime(&curtime) );

				ProcessPacket((char *)inbuff + PacketOffset, x - PacketOffset, udpsock, &sockaddr);
				puts("");
			}
		}
	} while (g_SweepEndIP != 0 || x > 0);

	CLOSESOCKET(udpsock);

	if (proxysock != INVALID_SOCKET)
		CLOSESOCKET(proxysock);

	puts("Exiting");

	return 0;
}


void Usage()
{
	puts(" Usage: NBName  [/CONFLICT] [/REVERSE] [/NOLOCAL|/NOLOCALNET] [/ASTATBACK]");
	puts("         [/ASTAT TargetIP] [/SWEEP StartIP EndIP] [/SCAN IPList] [/SVCDESC]");
	puts("         [/TO ms] [/DELAY ms] [/PORT Port] [/RETRY Trys] [/QUERY Name IP]");
	puts("         [/LOCALIP LocalIP] [/NETMASK Netmask] [/EXAMPLES] [/ASOUT Outfile]");
	puts("         [/ALLOW|/DENY NameOrFile] [/RESPOND NameOrFile] [/RESPONDIP RespIP]");
	puts("         [/OUTSVC SvcNum OutFile] [/SPAWN SvcNum CmdExe \"Args\"]");
	puts("         [/DESTPORT Port] [/PROXYIP ProxyIP] [/PROXYPORT ProxyPort]");
	puts("         [/PROXYUSER Username] [/PROXYPASS Password] [/BCASTIP BcastIP]");
	puts("   /LOCALIP will bind to LocalIP instead of the default system IP");
	puts("   /NETMASK will use Netmask to determine local net addresses");
	puts("   /BCASTIP will use BcastIP as the destination for broadcast packets");
	puts("   /PORT will bind to Port instead of 137");
	puts("   /DESTPORT will send packets to Port instead of 137");
	puts("   /PROXYIP will use the SOCKS 5 proxy at address ProxyIP to route UDP packets");
	puts("   /PROXYPORT will connect to tcp port ProxyPort rather than 1080");
	puts("   /PROXYUSER and /PROXYPASS let you supply authentication info to the proxy");
	puts("   /QUERY will cause a name query for Name to be broadcast");
	puts("   /ASTAT will send an adapter status (astat) request to TargetIP");
	puts("   /ASTATBACK will send astat requests to nodes that respond to queries");
	puts("   /SWEEP will send adapter status requests to all IPs from StartIP to EndIP");
	puts("   /SCAN will send adapter status requests to first IP listed in on each");
	puts("      line of IPList");
	puts("   /DELAY will pause for ms milliseconds between each packet sent durring a");
	puts("      scan or sweep, default 100 ms (10 packets per second)");
	puts("   /REVERSE will send an astat request in response to astat requests");
	puts("   /ASOUT will output received adapter status responses' contents to Outfile");
	puts("   /OUTSVC will output machines that respond to an adapter status request");
	puts("      and have service SvcNum running to OutFile in the format of lmhosts");
	puts("   /SVCDESC will display a description of each known service in astat responses");
	puts("   /SPAWN will spawn CmdExe with the commandline: CmdExe Args SrvrIP SrvrName");
	puts("      when an astat response is received with service SvcNum running");
	puts("   /NOLOCAL will prevent packets from the local host from being processed");
	puts("   /NOLOCALNET will prevent packets from the local subnet from being processed");
	puts("   /TO causes NBName to exit if no packets are received for ms milliseconds");
	puts("   /RETRY changes the number of times failed packets are resent from 3 to Trys");
	puts("   /CONFLICT* will send name release packets for each name in the remote name ");
	puts("      table of machines who respond to adapter status requests ");
	puts("   /RESPOND* will respond to name queries for NameOrFile");
	puts("   /RESPONDIP will return RespIP for queries responded to if /RESPOND is");
	puts("      used with a name or wildcard.  Defaults to LocalIP");
	puts("   /DENY* will cause the name(s) specified by NameOrFile to be denied if a");
	puts("      node tries to register it (them)");
	puts("   /ALLOW* will deny all names _except_ NameOrFile");
	puts("      NameOrFile can be a single name, the path to a file containing a list of");
	puts("      names or * for all names (/ALLOW * is not valid).. Names can include a");
	puts("      service value by adding a backslash followed by the hex service value");
	puts("  *  These options may be damaging to network stability, use with caution!");
	puts("  Clowns are evil, legacy protocols are a problem, Las Vegas is run by gnomes");
	puts(" --====[  CULT OF THE DEAD COW  ]-|-[  Everything You Need Since 1984  ]====--");
	puts("                         www.cultdeadcow.com");
	puts("    cDc - Bow to the Cow - cDc - Bow to the Cow - cDc - Bow to the Cow - cDc");
	puts("  ___    _   _    ___     _   _    ___       _   _      ___    _   _      ___");
	puts(" |___heal_the_sick___raise_the_dead___cleanse_the_lepers___cast_out_demons___|");
}

void Examples()
{
	puts("  /ALLOW and /DENY will effectively keep machines from being able to join the");
	puts("	  NetBIOS network because they will always think their machine name is");
	puts("    in use");
	puts("  /CONFLICT will cause machines to stop responding to their NetBIOS names, ");
	puts("    which will become in conflict and the NetBIOS networking will stop working");
	puts("  NBNAME /QUERY * /ASTATBACK /CONFLICT /DENY * will disable the entire local");
	puts("    network and prevent machines from reaccessing the NetBIOS network");
	puts("  NBNAME /NOLOCAL /REVERSE /CONFLICT will release the names of any machine that");
	puts("    requests adapter status from your machine");
	puts("  NBNAME /SWEEP 10.10.10.1 10.10.12.255 /DELAY 3 /NOLOCALNET /OUTSERVS lmhosts");
	puts("    will sweep three class C networks with astat requests and machines ");
	puts("    that respond and have the server service running will be added to lmhosts");
}


int main(int argc, char* argv[])
{
	int x;

	puts("NBName v2.4 - Decodes and displays NetBIOS Name traffic (UDP 137), with options");
	puts(" Copyright 2000: Sir Dystic, Cult of the Dead Cow  -:|:-  New Hack City");
	puts(" Send complaints, ideas and donations to sd@cultdeadcow.com|sd@newhackcity.net\n");


	for (x = 1; x < argc; x++)
	{
		if (argv[x][0] == '/')
		{
			if (STRICMP(argv[x], "/CONFLICT") == 0)
				g_Conflict = TRUE;
			else if (STRICMP(argv[x], "/ASTATBACK") == 0)
				g_AstatBack = TRUE;
			else if (STRICMP(argv[x], "/NOLOCAL") == 0)
				g_NoLocal = TRUE;
			else if (STRICMP(argv[x], "/REVERSE") == 0)
				g_Reverse = TRUE;
			else if (STRICMP(argv[x], "/NOLOCALNET") == 0)
				g_NoLocalNet = TRUE;
			else if (STRICMP(argv[x], "/SVCDESC") == 0)
				g_SvcDesc = TRUE;
			else if (STRICMP(argv[x], "/RANDSWEEP") == 0)
				g_RandSweep = TRUE;
			else if (STRICMP(argv[x], "/ASTAT") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /ASTAT\n");
					Usage();
					return 0;
				}
				x++;
				g_AstatIP = inet_addr(argv[x]);

				if (g_AstatIP == INADDR_NONE)
				{
					printf("Bad IP: \"%s\"\n", argv[x]);
					Usage();
					return 0;
				}
			}
			else if (STRICMP(argv[x], "/SPAWN") == 0)
			{
				if (x > argc - 4)
				{
					printf("Missing argument for /SPAWN\n");
					Usage();
					return 0;
				}
				x++;
				g_SpawnSvcVal = (BYTE)strtoul(argv[x], NULL, 16);
				x++;
				g_SpawnCommand = argv[x];
				x++;
				g_SpawnArgs = argv[x];
			}
			else if (STRICMP(argv[x], "/ASOUT") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /ASOUT\n");
					Usage();
					return 0;
				}
				x++;
				g_ASOutFile = argv[x];
			}
			else if (STRICMP(argv[x], "/ALLOW") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /ALLOW\n");
					Usage();
					return 0;
				}
				x++;
				g_AllowName = argv[x];
			}
			else if (STRICMP(argv[x], "/DENY") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /DENY\n");
					Usage();
					return 0;
				}
				x++;
				g_DenyName = argv[x];
			}
			else if (STRICMP(argv[x], "/RESPOND") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /RESPOND\n");
					Usage();
					return 0;
				}
				x++;
				g_RespondName = argv[x];
			}
			else if (STRICMP(argv[x], "/RESPONDIP") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /RESPONDIP\n");
					Usage();
					return 0;
				}
				x++;
				g_RespondIP = inet_addr(argv[x]);

				if (g_RespondIP == INADDR_NONE)
				{
					printf("Bad IP: \"%s\"\n", argv[x]);
					Usage();
					return 0;
				}
			}
			else if (STRICMP(argv[x], "/SCAN") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /SCAN\n");
					Usage();
					return 0;
				}
				x++;
				g_ScanFile = argv[x];
			}
			else if (STRICMP(argv[x], "/TO") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /TO\n");
					Usage();
					return 0;
				}
				x++;
				g_ReceiveTimeout = atoi(argv[x]);
			}
			else if (STRICMP(argv[x], "/DRIFT") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /DRIFT\n");
					Usage();
					return 0;
				}
				x++;
				g_DelayDrift = atoi(argv[x]);
			}
			else if (STRICMP(argv[x], "/RETRY") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /RETRY\n");
					Usage();
					return 0;
				}
				x++;
				g_Retries = atoi(argv[x]);
			}
			else if (STRICMP(argv[x], "/DELAY") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /DELAY\n");
					Usage();
					return 0;
				}
				x++;
				g_PacketDelay = atoi(argv[x]);
			}
			else if (STRICMP(argv[x], "/QUERY") == 0)
			{
				if (x > argc - 3)
				{
					printf("Missing argument for /QUERY\n");
					Usage();
					return 0;
				}
				x++;
				g_QueryName = argv[x];
				x++;
				if (strcmp(argv[x], "*") != 0)
				{
					g_QueryIP = inet_addr(argv[x]);
					if (g_QueryIP == INADDR_NONE)
					{
						printf("Bad IP: \"%s\"\n", argv[x]);
						Usage();
						return 0;
					}
				}
			}
			else if (STRICMP(argv[x], "/PORT") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /PORT\n");
					Usage();
					return 0;
				}
				x++;
				g_LocalPort = atoi(argv[x]);
			}
			else if (STRICMP(argv[x], "/DESTPORT") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /DESTPORT\n");
					Usage();
					return 0;
				}
				x++;
				g_DestPort = atoi(argv[x]);
			}
			else if (STRICMP(argv[x], "/PROXYPORT") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /PROXYPORT\n");
					Usage();
					return 0;
				}
				x++;
				g_ProxyPort = atoi(argv[x]);
			}
			else if (STRICMP(argv[x], "/PROXYUSER") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /PROXYUSER\n");
					Usage();
					return 0;
				}
				x++;
				g_ProxyUser = argv[x];
			}
			else if (STRICMP(argv[x], "/PROXYPASS") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /PROXYPASS\n");
					Usage();
					return 0;
				}
				x++;
				g_ProxyPass = argv[x];
			}
			else if (STRICMP(argv[x], "/OUTSVC") == 0)
			{
				if (x > argc - 3)
				{
					printf("Missing argument for /OUTSVC\n");
					Usage();
					return 0;
				}
				x++;
				g_OutSvcVal = (BYTE)strtoul(argv[x], NULL, 16);
				x++;
				g_OutSvcFile = argv[x];
			}
			else if (STRICMP(argv[x], "/SWEEP") == 0)
			{
				if (x > argc - 3)
				{
					printf("Missing argument for /SWEEP\n");
					Usage();
					return 0;
				}
				x++;
				g_SweepStartIP = inet_addr(argv[x]);

				if (g_SweepStartIP == INADDR_NONE)
				{
					printf("Bad IP: \"%s\"\n", argv[x]);
					Usage();
					return 0;
				}

				x++;
				g_SweepEndIP = inet_addr(argv[x]);

				if (g_SweepEndIP == INADDR_NONE)
				{
					printf("Bad IP: \"%s\"\n", argv[x]);
					Usage();
					return 0;
				}

			}
			else if (STRICMP(argv[x], "/EXAMPLES") == 0)
			{
				Examples();
				return 0;
			}
			else if (STRICMP(argv[x], "/LOCALIP") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /LOCALIP\n");
					Usage();
					return 0;
				}
				x++;
				g_LocalIP = inet_addr(argv[x]);

				if (g_LocalIP == INADDR_NONE)
				{
					printf("Bad IP: \"%s\"\n", argv[x]);
					Usage();
					return 0;
				}

			}
			else if (STRICMP(argv[x], "/BCASTIP") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /BCASTIP\n");
					Usage();
					return 0;
				}
				x++;
				g_BroadcastIP = inet_addr(argv[x]);

				if (g_BroadcastIP == INADDR_NONE)
				{
					printf("Bad IP: \"%s\"\n", argv[x]);
					Usage();
					return 0;
				}

			}
			else if (STRICMP(argv[x], "/PROXYIP") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /PROXYIP\n");
					Usage();
					return 0;
				}
				x++;
				g_ProxyIP = inet_addr(argv[x]);

				if (g_ProxyIP == INADDR_NONE)
				{
					printf("Bad IP: \"%s\"\n", argv[x]);
					Usage();
					return 0;
				}

			}
			else if (STRICMP(argv[x], "/NETMASK") == 0)
			{
				if (x > argc - 2)
				{
					printf("Missing argument for /NETMASK\n");
					Usage();
					return 0;
				}
				x++;
				g_NetmaskIP = inet_addr(argv[x]);

				if (g_NetmaskIP == INADDR_NONE)
				{
					printf("Bad IP: \"%s\"\n", argv[x]);
					Usage();
					return 0;
				}

			}
			else if (STRICMP(argv[x], "/?") == 0)
			{
				Usage();
				return 0;
			}
			else
			{
				printf("Bad option: \"%s\"\n", argv[x] );
				Usage();
				return 0;
			}
		}
		else
		{
			printf("Bad argument: \"%s\"\n", argv[x] );
			Usage();
			return 0;
		}
	}

#ifdef WIN32
	WSADATA wsadata;

#ifdef WINSOCK2
	WSAStartup(MAKEWORD(2,0), &wsadata);
#else
	WSAStartup(MAKEWORD(1,1), &wsadata);
#endif

	printf("WinSock v%d.%d (v%d.%d)  %s\n", LOBYTE(wsadata.wVersion), HIBYTE(wsadata.wVersion), LOBYTE(wsadata.wHighVersion), HIBYTE(wsadata.wHighVersion), wsadata.szDescription );


	if (strlen(wsadata.szSystemStatus))
		printf("WinSock status:  %s\n", wsadata.szSystemStatus);
#endif

	srand(GETRANDSEED());

	DoLoop();

#ifdef WIN32
	WSACleanup();
#endif
	return 0;
}
