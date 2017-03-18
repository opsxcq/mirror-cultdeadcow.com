// nete.cpp : Enumerates information remotely available via netbios.
//  Copyright 2000 Sir Dystic - Cult of the Dead Cow - sirdystic@cultdeadcow.com
//
// Must be linked with netapi32.lib 
#pragma comment( lib, "netapi32.lib" )
#pragma comment( lib, "rassapi.lib")

#include <windows.h>
#include <lmcons.h>		// constants needed for other lm*.h includes
#include <lmserver.h>	// for NerServerEnum
#include <lmshare.h>	// for NetEnumShares
#include <lmerr.h>		// for error constants
#include <lmremutl.h>	// for RemoteTOD
#include <lmapibuf.h>	// for NetApiBufferFree
#include <lmmsg.h>		// for NetMessageNameEnum
#include <lmrepl.h>		// for NetReplExportDirEnum
#include <lmat.h>		// for NetScheduleJobEnum
#include <lmstats.h>	// for NetStatisticsGet
#include <lmaccess.h>	// for NetUserEnum and others
#include <lmuse.h>		// for NetUseEnum
#include <lmsvc.h>		// for NetServiceEnum
#include <winsvc.h>		// for service APIs OpenSCManager and EnumServiceStatus
#include <winspool.h>	// for EnumPorts
#include <rassapi.h>	// for RasAdminPortEnum

#include <stdio.h>
#include <time.h>
#include <signal.h>


DWORD g_PlatformID = 0;
DWORD g_Support = 0;
BOOL g_bAll = FALSE;
BOOL g_bNULL = FALSE;

const char *StrError(DWORD err)
{
	static char retbuff[1024];

	if (err == 0)
		strcpy(retbuff, "\n");
	else
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, err, 0, retbuff, 1024, NULL);

	if (strlen(retbuff) == 0)
		strcpy(retbuff, "\n");


	return retbuff;
}

const char *YesNo(BOOL b)
{
	static char Yes[] = "YES";
	static char No[] =  "NO ";

	if (b)
		return Yes;
	else
		return No;
}




DWORD DoNetServerGetInfo(LPWORD wRemoteName, DWORD Level)
{
	DWORD netapistatus;
	LPBYTE ptb;
	char *ptr;
	char buff[64];


	printf("NetServerGetInfo() Level %u:\n", Level);

	netapistatus = NetServerGetInfo((char *)wRemoteName, Level, &ptb);

	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d getting system info: %s", netapistatus, StrError(netapistatus) );
	} else {

		if (Level >= 500)
		{
			SERVER_INFO_503 *pserverinfo503 = (SERVER_INFO_503 *)ptb;

			printf(" Forced Logoff:%s  Reliable times:%s  LANMan back compat:%s  LM Announce:%s\n", YesNo(pserverinfo503->sv503_enableforcedlogoff ) , YesNo(pserverinfo503->sv503_timesource ) , YesNo(pserverinfo503->sv503_acceptdownlevelapis) , YesNo(pserverinfo503->sv503_lmannounce) );
			printf(" Max files per session:      %8u \tMax virtual circuits/client:  %8u\n" , pserverinfo503->sv503_sessopens, pserverinfo503->sv503_sessvcs );
			printf(" Max simultaneous searches:  %8u \tSize of server buffer:        %8u\n", pserverinfo503->sv503_opensearch, pserverinfo503->sv503_sizreqbuf  );
			printf(" Initial receive buffers:    %8u \tMax receive buffers:          %8u\n", pserverinfo503->sv503_initworkitems, pserverinfo503->sv503_maxworkitems  );
			printf(" Raw work items:             %8u \tIRP stack locations:          %8u\n", pserverinfo503->sv503_rawworkitems , pserverinfo503->sv503_irpstacksize  );
			printf(" Max raw mode buffer size:   %7uk\tUsers per virtual circuit:    %8u\n", pserverinfo503->sv503_maxrawbuflen/1024 , pserverinfo503->sv503_sessusers  );
			printf(" Max trees per vcircuit:     %8u \t\n", pserverinfo503->sv503_sessconns );
			printf(" Max paged mem usage:        %7uk\tMax nonpaged mem usage:       %7uk\n", pserverinfo503->sv503_maxpagedmemoryusage/1024, pserverinfo503->sv503_maxnonpagedmemoryusage /1024 );
				
			if (Level > 502)
			{
				printf(" Search TO:                  %8u \tScavenger TO:                 %8u\n", pserverinfo503->sv503_maxkeepsearch, pserverinfo503->sv503_scavtimeout );
				printf(" Min rcv queue:              %8u \tMin free work items:          %8u\n", pserverinfo503->sv503_minrcvqueue, pserverinfo503->sv503_minfreeworkitems );
				printf(" Server memory region size:  %7uk\tServer thead priority:        %8u\n", pserverinfo503->sv503_xactmemsize/1024, pserverinfo503->sv503_threadpriority );
				printf(" Max simultaneous requests:  %8u \tOportunistic locks:           %8s\n", pserverinfo503->sv503_maxmpxct, YesNo(pserverinfo503->sv503_enableoplocks ) );
				printf(" Op lock break req TO:       %8u \tOp lock break resp TO:        %8u\n", pserverinfo503->sv503_oplockbreakwait, pserverinfo503->sv503_oplockbreakresponsewait );
				printf(" FCB Opens:%s   Raw SMBs:%s   Shared net drives:%s  Free conns min/max:%u/%u\n", YesNo(pserverinfo503->sv503_enablefcbopens ), YesNo(pserverinfo503->sv503_enableraw), YesNo(pserverinfo503->sv503_enablesharednetdrives), pserverinfo503->sv503_minfreeconnections, pserverinfo503->sv503_maxfreeconnections );
				printf(" Domain:\"%S\"\n", pserverinfo503->sv503_domain );
			}

		} else if (Level >= 400) {
			SERVER_INFO_403 *pserverinfo403 = (SERVER_INFO_403 *)ptb;

			printf("(Not yet implemented)\n");

			if (Level > 402)
			{

			}
			
		} else {
			SERVER_INFO_102 *pserverinfo102 = (SERVER_INFO_102 *)ptb;

			switch (pserverinfo102->sv102_platform_id)
			{
			case PLATFORM_ID_DOS:
				ptr = "DOS";
				break;
			case PLATFORM_ID_OS2:
				ptr = "OS2/9x";
				break;
			case PLATFORM_ID_NT:
				ptr = "NT";
				break;
			case PLATFORM_ID_OSF:
				ptr = "OSF";
				break;
			case PLATFORM_ID_VMS:
				ptr = "VMS";
				break;
			default:
				ptr = buff;
				sprintf(buff, "Unknown (%u)", pserverinfo102->sv102_platform_id );
				break;
			}

			g_PlatformID = pserverinfo102->sv102_platform_id ;

			printf("Name:\"%S\"  OS: %s ", pserverinfo102->sv102_name, ptr);

			if (Level > 100)
			{
				printf("v%d.%d  Comment:\"%S\"\nType flags: ", MAJOR_VERSION_MASK & pserverinfo102->sv102_version_major, pserverinfo102->sv102_version_minor, pserverinfo102->sv102_comment );

				if (pserverinfo102->sv102_type & SV_TYPE_WORKSTATION)
					printf("WORKSTATION ");

				if (pserverinfo102->sv102_type & SV_TYPE_SERVER)
					printf("SERVER ");

				if (pserverinfo102->sv102_type & SV_TYPE_DOMAIN_CTRL)
					printf("DOMAIN_CTRL ");

				if (pserverinfo102->sv102_type & SV_TYPE_DOMAIN_BAKCTRL)
					printf("DOMAIN_BAKCTRL ");

				if (pserverinfo102->sv102_type & SV_TYPE_TIME_SOURCE)
					printf("TIME_SOURCE ");

				if (pserverinfo102->sv102_type & SV_TYPE_AFP)
					printf("AFP ");

				if (pserverinfo102->sv102_type & SV_TYPE_NOVELL)
					printf("NOVELL ");

				if (pserverinfo102->sv102_type & SV_TYPE_DOMAIN_MEMBER)
					printf("DOMAIN_MEMBER ");

				if (pserverinfo102->sv102_type & SV_TYPE_LOCAL_LIST_ONLY)
					printf("LOCAL_LIST_ONLY ");

				if (pserverinfo102->sv102_type & SV_TYPE_PRINTQ_SERVER)
					printf("PRINTQ_SERVER ");

				if (pserverinfo102->sv102_type & SV_TYPE_DIALIN_SERVER)
					printf("DIALIN_SERVER ");

				if (pserverinfo102->sv102_type & SV_TYPE_SERVER_UNIX)
					printf("SERVER_UNIX ");

				if (pserverinfo102->sv102_type & SV_TYPE_SERVER_MFPN)
					printf("SERVER_MFPN ");

				if (pserverinfo102->sv102_type & SV_TYPE_WINDOWS )
					printf("WINDOWS ");

				if (pserverinfo102->sv102_type & SV_TYPE_SERVER_NT)
					printf("SERVER_NT ");

				if (pserverinfo102->sv102_type & SV_TYPE_WFW)
					printf("WFW ");

				if (pserverinfo102->sv102_type & SV_TYPE_POTENTIAL_BROWSER)
					printf("POTENTIAL_BROWSER ");

				if (pserverinfo102->sv102_type & SV_TYPE_BACKUP_BROWSER )
					printf("BACKUP_BROWSER ");

				if (pserverinfo102->sv102_type & SV_TYPE_MASTER_BROWSER )
					printf("MASTER_BROWSER ");

				if (pserverinfo102->sv102_type & SV_TYPE_DOMAIN_MASTER )
					printf("DOMAIN_MASTER ");

				if (pserverinfo102->sv102_type & SV_TYPE_SERVER_OSF )
					printf("SERVER_OSF ");

				if (pserverinfo102->sv102_type & SV_TYPE_SERVER_VMS )
					printf("SERVER_VMS ");

				if (pserverinfo102->sv102_type & SV_TYPE_DFS )
					printf("DFS ");

				if (pserverinfo102->sv102_type & SV_TYPE_CLUSTER_NT )
					printf("CLUSTER_NT ");

				if (pserverinfo102->sv102_type & SV_TYPE_DCE )
					printf("DCE ");

				if (pserverinfo102->sv102_type & SV_TYPE_ALTERNATE_XPORT )
					printf("ALTERNATE_XPORT ");

				if (pserverinfo102->sv102_type & SV_TYPE_LOCAL_LIST_ONLY )
					printf("LOCAL_LIST_ONLY ");

				if (pserverinfo102->sv102_type & SV_TYPE_DOMAIN_ENUM)
					printf("DOMAIN_ENUM ");
			}

			puts("");

			if (Level > 101)
			{
				printf("Users/licenses:%u/%u  Disconnect:%d mins  Visible:%s  Announce/delta:%u/%u\n",
					pserverinfo102->sv102_users, pserverinfo102->sv102_licenses , pserverinfo102->sv102_disc, YesNo(pserverinfo102->sv102_hidden), pserverinfo102->sv102_announce, pserverinfo102->sv102_anndelta);

				if (wcslen((LPWSTR)pserverinfo102->sv102_userpath) )
					printf("Path to user dirs: %ls\n", pserverinfo102->sv102_userpath );
			}
		}

		NetApiBufferFree(ptb);
	}

	return netapistatus;
}


DWORD DoNetRemoteTOD(LPWSTR RemoteName)
{
	TIME_OF_DAY_INFO *ptimeofday;
	NET_API_STATUS netapistatus;
	LPBYTE ptb;
	DWORD d, days, hours, mins, secs;


	puts("NetRemoteTOD():");

	netapistatus = NetRemoteTOD(RemoteName, &ptb);

	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d getting system time: %s", netapistatus, StrError(netapistatus) );
	} else {
		ptimeofday = (TIME_OF_DAY_INFO *)ptb;

		d = ptimeofday->tod_msecs ;
		days = d / 86400000;
		d =   d % 86400000;
		hours = d / 3600000;
		d =   d % 3600000;
		mins = d / 60000;
		d =   d % 60000;
		secs = d / 1000;
		d = d % 1000;


		printf("%02d-%02d-%d   %02d:%d:%d GMT - %d   Uptime at least: %ud %uh %um %us %ums\n", ptimeofday->tod_month, ptimeofday->tod_day, ptimeofday->tod_year, ptimeofday->tod_hours, ptimeofday->tod_mins, ptimeofday->tod_secs, ptimeofday->tod_timezone/60, days, hours, mins, secs, d);
		NetApiBufferFree(ptb);

		puts("");
	}


	return netapistatus;
}


DWORD DoNetTransportEnum(LPWSTR RemoteName, DWORD Level)
{
	NET_API_STATUS netapistatus;
	DWORD d, dw1, dw2;
	LPBYTE ptb;

	printf("NetServerTransportEnum() Level %u:\n", Level);

	dw1 = dw2 =  0;

	netapistatus = NetServerTransportEnum((char *)RemoteName, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating transports: %s", netapistatus, StrError(netapistatus) );
	} else {
		SERVER_TRANSPORT_INFO_2 *pservertransportinfo2 = (SERVER_TRANSPORT_INFO_2 *)ptb;

		for (d = 0; d < dw1; d++)
		{
			printf("%S:%S  %d clients\n", pservertransportinfo2->svti2_transportname, pservertransportinfo2->svti2_networkaddress, pservertransportinfo2->svti2_numberofvcs);

			if (Level > 0)
			{
				printf(" Domain: %S\n", pservertransportinfo2->svti2_domain );


			}
			if (Level > 1)
			{
				printf(" Flags: 0x%08X\n", pservertransportinfo2->svti2_flags );

			}
			switch (Level)
			{
			case 0:
				pservertransportinfo2 = (SERVER_TRANSPORT_INFO_2 *)((char *)pservertransportinfo2 + sizeof(SERVER_TRANSPORT_INFO_0));
				break;
			case 1:
				pservertransportinfo2 = (SERVER_TRANSPORT_INFO_2 *)((char *)pservertransportinfo2 + sizeof(SERVER_TRANSPORT_INFO_1));
				break;
			case 2:
				pservertransportinfo2 = (SERVER_TRANSPORT_INFO_2 *)((char *)pservertransportinfo2 + sizeof(SERVER_TRANSPORT_INFO_2));
				break;
			}

		}

		puts("");

		NetApiBufferFree(ptb);
	}

	return netapistatus;
}




DWORD DoNetConnectionEnum(LPWSTR RemoteName, LPWSTR ShareName, DWORD Level)
{
	NET_API_STATUS netapistatus;
	DWORD d, dw1, dw2;
	LPBYTE ptb;

	dw1 = dw2 = 0;

	netapistatus = NetConnectionEnum((char *)RemoteName, (char *)ShareName, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating connections at level %u: %s", netapistatus, Level, StrError(netapistatus) );

	} else {
		CONNECTION_INFO_1 *pconnectioninfo1 = (CONNECTION_INFO_1 *)ptb;

		for (d = 0; d < dw1; d++)
		{
			printf("  0x%08x ", pconnectioninfo1->coni1_id);

			if (Level > 0)
			{
				switch ( pconnectioninfo1->coni1_type )
				{
				case STYPE_DISKTREE:
					printf("DISK   ");
					break;
				case STYPE_PRINTQ:
					printf("PRINT  ");
					break;
				case STYPE_DEVICE:
					printf("DEVICE ");
					break;
				case STYPE_IPC:
					printf("IPC$   ");
					break;
				default:
					printf("?%06X", pconnectioninfo1->coni1_type );
					break;
				}

				printf(" Opens:%03u  Users:%03u  Connected %u mins %u secs\n", pconnectioninfo1->coni1_num_opens, pconnectioninfo1->coni1_num_users, pconnectioninfo1->coni1_time / 60, pconnectioninfo1->coni1_time % 60 );
				printf("  %S\\%S\n", pconnectioninfo1->coni1_netname, pconnectioninfo1->coni1_username );

			}

			switch (Level)
			{
			case 0:
				pconnectioninfo1 = (CONNECTION_INFO_1 *)((char *)pconnectioninfo1 + sizeof(CONNECTION_INFO_0) );
				break;
			case 1:
				pconnectioninfo1 = (CONNECTION_INFO_1 *)((char *)pconnectioninfo1 + sizeof(CONNECTION_INFO_1) );
				break;
			}
		}

		NetApiBufferFree(ptb);
	}

	return netapistatus;
}




DWORD DisplaySecurityDescriptorInfo(LPCWSTR RemoteName, PSECURITY_DESCRIPTOR psecdesc, BOOL Unicode)
{
	DWORD d;
	SECURITY_DESCRIPTOR_CONTROL secdesccontrol;
	PACL pacl = NULL;
	BOOL bAclPresent, bDefault;
	int x;

	if (GetSecurityDescriptorControl(psecdesc, &secdesccontrol, &d) == 0)
	{
		d = GetLastError();
		printf("Error %d getting security descriptor control: %s", d, StrError(d) );
		return d;
	} else {

		if (GetSecurityDescriptorSacl(psecdesc, &bAclPresent, &pacl, &bDefault) == 0)
		{
			d = GetLastError();
			printf("Error %d getting system ACL: %s", d, StrError(d) );
			return d;
		} else {
			if (bAclPresent)
			{


			}

		}

		if (GetSecurityDescriptorDacl(psecdesc, &bAclPresent, &pacl, &bDefault) == 0)
		{
			d = GetLastError();
			printf("Error %d getting discretionary ACL: %s", d, StrError(d) );
			return d;
		} else {
			if (bAclPresent)
			{
				if (IsValidAcl(pacl) )
				{
					LPVOID lpv;

					for (x = 0; x < pacl->AceCount; x++)
					{
						if (GetAce(pacl, x, &lpv) != 0)
						{
							ACCESS_MASK accessmask;
							ACE_HEADER *paceheader = (ACE_HEADER *)lpv;
							switch (paceheader->AceType)
							{
							case ACCESS_ALLOWED_ACE_TYPE:
								printf(" Allowed:");
								break;
							case ACCESS_DENIED_ACE_TYPE:
								printf(" Denied:");
								break;
							case SYSTEM_AUDIT_ACE_TYPE:
								printf(" Audit:");
								break;
							case ACCESS_ALLOWED_OBJECT_ACE_TYPE:
								printf(" Object allowed:");
								break;
							case ACCESS_DENIED_OBJECT_ACE_TYPE:
								printf(" Object denied:");
								break;
							case SYSTEM_AUDIT_OBJECT_ACE_TYPE:
								printf(" Object audit:");
								break;
							}


							switch (paceheader->AceType)
							{
							case ACCESS_ALLOWED_ACE_TYPE:
							case ACCESS_DENIED_ACE_TYPE:
							case SYSTEM_AUDIT_ACE_TYPE:
								{
									ACCESS_ALLOWED_ACE *paccessallowedace = (ACCESS_ALLOWED_ACE *)lpv;

									if (IsValidSid(&paccessallowedace->SidStart) )
									{
										SID_NAME_USE sidnameuse;
										WORD nameW[1024];
										WORD domainW[1024];
										char nameA[1024];
										char domainA[1024];


										if (Unicode)
										{
											DWORD d1 = sizeof(nameW);
											DWORD d2 = sizeof(domainW);
											if (LookupAccountSidW(RemoteName, &paccessallowedace->SidStart, nameW, &d1, domainW, &d2, &sidnameuse) != 0)
												printf(" %S\\%S ", domainW, nameW);
										} else {
											DWORD d1 = sizeof(nameA);
											DWORD d2 = sizeof(domainA);
											if (LookupAccountSidA((char *)RemoteName, &paccessallowedace->SidStart, nameA, &d1, domainA, &d2, &sidnameuse) != 0)
												printf(" %s\\%s ", domainA, nameA);
										}
									}
									accessmask = paccessallowedace->Mask;
								}
								
								break;
							case ACCESS_ALLOWED_OBJECT_ACE_TYPE:
							case ACCESS_DENIED_OBJECT_ACE_TYPE:
							case SYSTEM_AUDIT_OBJECT_ACE_TYPE:
								{
									ACCESS_ALLOWED_OBJECT_ACE *paccessallowedace = (ACCESS_ALLOWED_OBJECT_ACE *)lpv;

									if (IsValidSid(&paccessallowedace->SidStart) )
									{
										SID_NAME_USE sidnameuse;
										WORD name[1024];
										WORD domain[1024];
										DWORD d1 = sizeof(name);
										DWORD d2 = sizeof(domain);

										if (LookupAccountSidW(RemoteName, &paccessallowedace->SidStart, name, &d1, domain, &d2, &sidnameuse) != 0)
											printf(" %S\\%S ", domain, name);
									}
									accessmask = paccessallowedace->Mask;
								}
								break;
							}

							printf(" 0x%04x", accessmask & SPECIFIC_RIGHTS_ALL);

							if (accessmask & GENERIC_READ)
								printf(" READ");

							if (accessmask & GENERIC_WRITE)
								printf(" WRITE");

							if (accessmask & GENERIC_EXECUTE)
								printf(" EXECUTE");

							if (accessmask & GENERIC_ALL)
								printf(" ALL");

							if (accessmask & MAXIMUM_ALLOWED)
								printf(" MAXALLOWED");

							if (accessmask & ACCESS_SYSTEM_SECURITY)
								printf(" ACCESS_SYSTEM_SECURITY");

							if (accessmask & DELETE)
								printf(" DELETE");

							if (accessmask & READ_CONTROL)
								printf(" READ_CONTROL");

							if (accessmask & WRITE_DAC)
								printf(" WRITE_DAC");

							if (accessmask & WRITE_OWNER)
								printf(" WRITE_OWNER");

							if (accessmask & SYNCHRONIZE)
								printf(" SYNCHRONIZE");



						}

						puts("");
					}
				}
			}
		}
	}
	

	return 0;
}


DWORD DoNetShareEnum(LPWSTR RemoteName, DWORD Level)
{
	DWORD NetConnectionEnumLevels[8] = {1, 0, -1};
	DWORD d, dw1, dw2;
	NET_API_STATUS netapistatus;
	LPBYTE ptb;
	int x;
	DWORD ret;

	printf("NetShareEnum() Level %u:\n", Level);

	dw1 = dw2 =  0;

	netapistatus = NetShareEnum((char *)RemoteName, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);

	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating shares: %s", netapistatus, StrError(netapistatus) );
	} else {
		if (Level > 500)
		{
			SHARE_INFO_502 *pshareinfo502 = (SHARE_INFO_502 *)ptb;

			for (d = 0; d < dw1; d++)
			{
				printf("Name: \"%S\"  ", pshareinfo502->shi502_netname);

				switch (pshareinfo502->shi502_type & 0xFFFFFFF)
				{
				case STYPE_DISKTREE:
					printf("DISK  - ");
					break;
				case STYPE_PRINTQ:
					printf("PRINT - ");
					break;
				case STYPE_DEVICE:
					printf("COMM  - ");
					break;
				case STYPE_IPC:
					printf("IPC   - ");
					break;
				default:
					printf("Unknown?");
					break;
				}

				printf(" %S",  pshareinfo502->shi502_remark);
					
				if (pshareinfo502->shi502_type & 0x80000000)
					puts(" (System)");
				else
					puts("");


				if (Level > 501)
				{
					printf(" Users cur/max:%u/%u  Permissions:", pshareinfo502->shi502_current_uses, pshareinfo502->shi502_max_uses );

					if (pshareinfo502->shi502_permissions & ACCESS_READ)
						printf("READ ");

					if (pshareinfo502->shi502_permissions & ACCESS_WRITE)
						printf("WRITE ");

					if (pshareinfo502->shi502_permissions & ACCESS_CREATE)
						printf("CREATE ");

					if (pshareinfo502->shi502_permissions & ACCESS_EXEC)
						printf("EXEC ");

					if (pshareinfo502->shi502_permissions & ACCESS_DELETE)
						printf("DELETE ");

					if (pshareinfo502->shi502_permissions & ACCESS_ATRIB)
						printf("ATRIB ");

					if (pshareinfo502->shi502_permissions & ACCESS_PERM)
						printf("PERM ");

					puts("");

					if (pshareinfo502->shi502_path != NULL && wcslen((LPWSTR)pshareinfo502->shi502_path))
						printf(" Path: \"%S\"\n", pshareinfo502->shi502_path );

					if (pshareinfo502->shi502_passwd != NULL && wcslen((LPWSTR)pshareinfo502->shi502_passwd))
						printf(" Passwd: \"%S\"\n", pshareinfo502->shi502_passwd );

					if (IsValidSecurityDescriptor(pshareinfo502->shi502_security_descriptor) )
					{
						DisplaySecurityDescriptorInfo(RemoteName, pshareinfo502->shi502_security_descriptor, TRUE);

					}
				}

				x = 0;
				do
				{
					ret = DoNetConnectionEnum(RemoteName, (LPWSTR)pshareinfo502->shi502_netname, NetConnectionEnumLevels[x]);
					x++;
				} while ( ret != NERR_Success && NetConnectionEnumLevels[x] != -1 );

				switch (Level)
				{
				case 501:
					pshareinfo502 = (SHARE_INFO_502 *)((char *)pshareinfo502 + sizeof(SHARE_INFO_501));
					break;
				case 502:
					pshareinfo502 = (SHARE_INFO_502 *)((char *)pshareinfo502 + sizeof(SHARE_INFO_502));
					break;
				}
			}

		} else {
			SHARE_INFO_2 *pshareinfo2 = (SHARE_INFO_2 *)ptb;

			for (d = 0; d < dw1; d++)
			{
				printf("Name: \"%S\"  ", pshareinfo2->shi2_netname);

				if (Level > 0)
				{
					switch (pshareinfo2->shi2_type & 0xFFFFFFF)
					{
					case STYPE_DISKTREE:
						printf("DISK  - ");
						break;
					case STYPE_PRINTQ:
						printf("PRINT - ");
						break;
					case STYPE_DEVICE:
						printf("COMM  - ");
						break;
					case STYPE_IPC:
						printf("IPC   - ");
						break;
					default:
						printf("Unknown?");
						break;
					}

					printf(" %S",  pshareinfo2->shi2_remark);
					
					if (pshareinfo2->shi2_type & 0x80000000)
						puts(" (System)");
					else
						puts("");
				} else {
					puts("");
				}

				if (Level > 1)
				{
					printf("Users cur/max:%u/%u  Permissions:", pshareinfo2->shi2_current_uses, pshareinfo2->shi2_max_uses );

					if (pshareinfo2->shi2_permissions & ACCESS_READ)
						printf("READ ");

					if (pshareinfo2->shi2_permissions & ACCESS_WRITE)
						printf("WRITE ");

					if (pshareinfo2->shi2_permissions & ACCESS_CREATE)
						printf("CREATE ");

					if (pshareinfo2->shi2_permissions & ACCESS_EXEC)
						printf("EXEC ");

					if (pshareinfo2->shi2_permissions & ACCESS_DELETE)
						printf("DELETE ");

					if (pshareinfo2->shi2_permissions & ACCESS_ATRIB)
						printf("ATRIB ");

					if (pshareinfo2->shi2_permissions & ACCESS_PERM)
						printf("PERM ");

					puts("");
					if (pshareinfo2->shi2_path != NULL && wcslen((LPWSTR)pshareinfo2->shi2_path))
						printf(" Path: \"%S\"\n", pshareinfo2->shi2_path );

					if (pshareinfo2->shi2_passwd!= NULL && wcslen((LPWSTR)pshareinfo2->shi2_passwd))
						printf(" Path: \"%S\"\n", pshareinfo2->shi2_passwd );

				}

				if ((g_PlatformID == PLATFORM_ID_NT || g_PlatformID == 0) && g_bAll)
				{
					x = 0;
					do
					{
						ret = DoNetConnectionEnum(RemoteName, (LPWSTR)pshareinfo2->shi2_netname, NetConnectionEnumLevels[x]);
						x++;
					} while ( ret != NERR_Success && NetConnectionEnumLevels[x] != -1 );
				}

				switch (Level)
				{
				case 0:
					pshareinfo2 = (SHARE_INFO_2 *)((char *)pshareinfo2 + sizeof(SHARE_INFO_0));
					break;
				case 1:
					pshareinfo2 = (SHARE_INFO_2 *)((char *)pshareinfo2 + sizeof(SHARE_INFO_1));
					break;
				case 2:
					pshareinfo2 = (SHARE_INFO_2 *)((char *)pshareinfo2 + sizeof(SHARE_INFO_2));
					break;
				}
			}
		}

		puts("");

		NetApiBufferFree(ptb);
	}

	return netapistatus;
}


DWORD DoNetSessionEnum(LPWSTR RemoteName, DWORD Level)
{
	DWORD d, dw1, dw2;
	NET_API_STATUS netapistatus;
	LPBYTE ptb;

	printf("NetSessionEnum() Level %u:\n", Level);

	dw1 = dw2 =  0;

	netapistatus = NetSessionEnum((char *)RemoteName, NULL, NULL, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);

	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating sessions: %s", netapistatus, StrError(netapistatus) );
	} else {
		if (Level >= 500)
		{
			SESSION_INFO_502 *psessioninfo502 = (SESSION_INFO_502 *)ptb;

			for (d = 0; d < dw1; d++)
			{
				printf("%S\\%S Active %u mins %u secs  Idle %u mins %u secs  Opens: %u ", psessioninfo502->sesi502_cname, psessioninfo502->sesi502_username, psessioninfo502->sesi502_time/60, psessioninfo502->sesi502_time%60, psessioninfo502->sesi502_idle_time/60, psessioninfo502->sesi502_idle_time/60,  psessioninfo502->sesi502_num_opens);

				if (psessioninfo502->sesi502_user_flags & SESS_GUEST)
					printf("GUEST ");
				if (psessioninfo502->sesi502_user_flags & SESS_NOENCRYPTION)
					printf("PLAINTEXTPW ");

				puts("");

				if (psessioninfo502->sesi502_cltype_name != NULL && wcslen((LPWORD)psessioninfo502->sesi502_cltype_name))
					printf(" Type: %S\n", psessioninfo502->sesi502_cltype_name);

				if (psessioninfo502->sesi502_transport != NULL && wcslen((LPWORD)psessioninfo502->sesi502_transport))
					printf(" Transport: %S\n", psessioninfo502->sesi502_transport);

				psessioninfo502++; // only 502 is valid
			}

		} else if (Level >= 10) {
			SESSION_INFO_10 *psessioninfo10 = (SESSION_INFO_10 *)ptb;

			for (d = 0; d < dw1; d++)
			{
				printf("%S\\%S Active %u secs  Idle %u secs\n", psessioninfo10->sesi10_cname, psessioninfo10->sesi10_username, psessioninfo10->sesi10_time, psessioninfo10->sesi10_idle_time);

				psessioninfo10++;	// only 10 is valid
			}
		} else {	// else less than 10
			SESSION_INFO_2 *psessioninfo2 = (SESSION_INFO_2 *)ptb;

			for (d = 0; d < dw1; d++)
			{
				printf("%S", psessioninfo2->sesi2_cname );

				if (Level > 0)
				{
					printf("\\%S  %S  %u opens  Active %u secs  Idle %u secs  ", psessioninfo2->sesi2_username, psessioninfo2->sesi2_cltype_name, psessioninfo2->sesi2_num_opens, psessioninfo2->sesi2_time, psessioninfo2->sesi2_idle_time);

					if (psessioninfo2->sesi2_user_flags & SESS_GUEST)
						printf("GUEST  ");
					if (psessioninfo2->sesi2_user_flags & SESS_NOENCRYPTION)
						printf("PLAINTEXTPW ");
				}

				puts("");

				if (Level > 1)
				{
					if (psessioninfo2->sesi2_cltype_name != NULL && wcslen((LPWORD)psessioninfo2->sesi2_cltype_name))
						printf(" Type: %S\n", psessioninfo2->sesi2_cltype_name);
				}

				switch (Level)
				{
				case 0:
					psessioninfo2 = (SESSION_INFO_2 *)((char *)psessioninfo2 + sizeof(SESSION_INFO_0));
					break;
				case 1:
					psessioninfo2 = (SESSION_INFO_2 *)((char *)psessioninfo2 + sizeof(SESSION_INFO_1));
					break;
				case 2:
					psessioninfo2 = (SESSION_INFO_2 *)((char *)psessioninfo2 + sizeof(SESSION_INFO_2));
					break;
				}
					
			}


		}

		NetApiBufferFree(ptb);
	}


	return netapistatus;
}


DWORD DoNetUseEnum(LPWSTR RemoteName, DWORD Level)
{
	NET_API_STATUS netapistatus;
	LPBYTE ptb;
	DWORD d, dw1, dw2;
	const char *StatusNames[] = { "OK", "Paused", "Disconnected", "NetErr", "Connected", "Reconnected", "Error" };
	const char *AsgNames[] = { "???", "Disk", "Print", "Device", "IPC$" };


	printf("NetUseEnum() Level %u:\n", Level);

	dw1 = dw2 =  0;
	netapistatus = NetUseEnum((char *)RemoteName, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating uses: %s", netapistatus, StrError(netapistatus) );
	} else {
		USE_INFO_2 *puseinfo2 = (USE_INFO_2 *)ptb;

		for (d = 0; d < dw1; d++)
		{
			printf("Local name:%16S  Remote name:%16S\n", puseinfo2->ui2_local, puseinfo2->ui2_remote );

			if (Level > 0)
			{
				if (puseinfo2->ui2_password != NULL && wcslen((LPCWSTR)puseinfo2->ui2_password) )
					printf(" Password: \"%S\"\n", puseinfo2->ui2_password);

				printf(" Status:%s    Type:%s    Ref count:%u    Use count:%u\n", StatusNames[puseinfo2->ui2_status], AsgNames[puseinfo2->ui2_asg_type], puseinfo2->ui2_refcount, puseinfo2->ui2_usecount );
			}

			if (Level > 1)
			{
				if (puseinfo2->ui2_username != NULL && wcslen((LPCWSTR)puseinfo2->ui2_username) )
					printf(" Username: \"%S\"\n", puseinfo2->ui2_username);

				if (puseinfo2->ui2_domainname != NULL && wcslen((LPCWSTR)puseinfo2->ui2_domainname) )
					printf(" Domain name: \"%S\"\n", puseinfo2->ui2_domainname);
			}

			switch (Level)
			{
			case 0:
				puseinfo2 = (USE_INFO_2 *)((char *)puseinfo2 + sizeof(USE_INFO_0) );
				break;
			case 1:
				puseinfo2 = (USE_INFO_2 *)((char *)puseinfo2 + sizeof(USE_INFO_1) );
				break;
			case 2:
				puseinfo2 = (USE_INFO_2 *)((char *)puseinfo2 + sizeof(USE_INFO_2) );
				break;
			}

		}


		NetApiBufferFree(ptb);
	}

	return netapistatus;
}




DWORD DoNetServerEnum(LPWSTR RemoteName, DWORD Level)
{
	NET_API_STATUS netapistatus;
	LPBYTE ptb;
	DWORD d, dw1, dw2;
	char *ptr;
	char buff[64];


	printf("NetServerEnum() Level %u:\n", Level );


	dw1 = dw2 =  0;
	netapistatus = NetServerEnum((const char *)RemoteName, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, SV_TYPE_ALL, NULL, NULL);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating machines: %s", netapistatus, StrError(netapistatus) );
	} else {
		if (Level >= 500)
		{
			SERVER_INFO_503 *pserverinfo503 = (SERVER_INFO_503 *)ptb;

		} else if (Level >= 400) {
			SERVER_INFO_403 *pserverinfo403 = (SERVER_INFO_403 *)ptb;

		} else {
			SERVER_INFO_102 *pserverinfo102 = (SERVER_INFO_102 *)ptb;

			for (d = 0; d < dw1; d++)
			{
				switch (pserverinfo102->sv102_platform_id)
				{
				case PLATFORM_ID_DOS:
					ptr = "DOS";
					break;
				case PLATFORM_ID_OS2:
					ptr = "OS2/9x";
					break;
				case PLATFORM_ID_NT:
					ptr = "NT";
					break;
				case PLATFORM_ID_OSF:
					ptr = "OSF";
					break;
				case PLATFORM_ID_VMS:
					ptr = "VMS";
					break;
				default:
					ptr = buff;
					sprintf(buff, "Unknown (%u)", pserverinfo102->sv102_platform_id );
					break;
				}


				printf("Name:\"%S\"  OS: %s ", pserverinfo102->sv102_name, ptr );
					
				if (Level > 100)
				{
					printf("v%d.%d  Comment:\"%S\"\n Type flags: ", MAJOR_VERSION_MASK & pserverinfo102->sv102_version_major, pserverinfo102->sv102_version_minor, pserverinfo102->sv102_comment );

					if (pserverinfo102->sv102_type & SV_TYPE_WORKSTATION)
						printf("WORKSTATION ");

					if (pserverinfo102->sv102_type & SV_TYPE_SERVER)
						printf("SERVER ");

					if (pserverinfo102->sv102_type & SV_TYPE_DOMAIN_CTRL)
						printf("DOMAIN_CTRL ");

					if (pserverinfo102->sv102_type & SV_TYPE_DOMAIN_BAKCTRL)
						printf("DOMAIN_BAKCTRL ");

					if (pserverinfo102->sv102_type & SV_TYPE_TIME_SOURCE)
						printf("TIME_SOURCE ");

					if (pserverinfo102->sv102_type & SV_TYPE_AFP)
						printf("AFP ");

					if (pserverinfo102->sv102_type & SV_TYPE_NOVELL)
						printf("NOVELL ");

					if (pserverinfo102->sv102_type & SV_TYPE_DOMAIN_MEMBER)
						printf("DOMAIN_MEMBER ");

					if (pserverinfo102->sv102_type & SV_TYPE_LOCAL_LIST_ONLY)
						printf("LOCAL_LIST_ONLY ");

					if (pserverinfo102->sv102_type & SV_TYPE_PRINTQ_SERVER)
						printf("PRINTQ_SERVER ");

					if (pserverinfo102->sv102_type & SV_TYPE_DIALIN_SERVER)
						printf("DIALIN_SERVER ");

					if (pserverinfo102->sv102_type & SV_TYPE_SERVER_UNIX)
						printf("SERVER_UNIX ");

					if (pserverinfo102->sv102_type & SV_TYPE_SERVER_MFPN)
						printf("SERVER_MFPN ");

					if (pserverinfo102->sv102_type & SV_TYPE_WINDOWS )
						printf("WINDOWS ");

					if (pserverinfo102->sv102_type & SV_TYPE_SERVER_NT)
						printf("SERVER_NT ");

					if (pserverinfo102->sv102_type & SV_TYPE_WFW)
						printf("WFW ");

					if (pserverinfo102->sv102_type & SV_TYPE_SERVER_NT)
						printf("SERVER_NT ");

					if (pserverinfo102->sv102_type & SV_TYPE_POTENTIAL_BROWSER)
						printf("POTENTIAL_BROWSER ");

					if (pserverinfo102->sv102_type & SV_TYPE_BACKUP_BROWSER )
						printf("BACKUP_BROWSER ");

					if (pserverinfo102->sv102_type & SV_TYPE_MASTER_BROWSER )
						printf("MASTER_BROWSER ");

					if (pserverinfo102->sv102_type & SV_TYPE_DOMAIN_MASTER )
						printf("DOMAIN_MASTER ");

					if (pserverinfo102->sv102_type & SV_TYPE_SERVER_OSF )
						printf("SERVER_OSF ");

					if (pserverinfo102->sv102_type & SV_TYPE_SERVER_VMS )
						printf("SERVER_VMS ");

					if (pserverinfo102->sv102_type & SV_TYPE_DFS )
						printf("DFS ");

					if (pserverinfo102->sv102_type & SV_TYPE_CLUSTER_NT )
						printf("CLUSTER_NT ");

					if (pserverinfo102->sv102_type & SV_TYPE_DCE )
						printf("DCE ");

					if (pserverinfo102->sv102_type & SV_TYPE_ALTERNATE_XPORT )
						printf("ALTERNATE_XPORT ");

					if (pserverinfo102->sv102_type & SV_TYPE_LOCAL_LIST_ONLY )
						printf("LOCAL_LIST_ONLY ");

					if (pserverinfo102->sv102_type & SV_TYPE_DOMAIN_ENUM)
						printf("DOMAIN_ENUM ");

					puts("");
				}

				if (Level > 101)
				{
					printf("Users/licenses:%u/%u  Disconnect:%d mins  Visible:%s  Announce/delta:%u/%u\n",
						pserverinfo102->sv102_users, pserverinfo102->sv102_licenses , pserverinfo102->sv102_disc, YesNo(pserverinfo102->sv102_hidden), pserverinfo102->sv102_announce, pserverinfo102->sv102_anndelta);

					if (wcslen((LPWSTR)pserverinfo102->sv102_userpath) )
						printf("Path to user dirs: %ls\n", pserverinfo102->sv102_userpath );

				}

				switch (Level)
				{
				case 100:
					pserverinfo102 = (SERVER_INFO_102 *)((char *)pserverinfo102  + sizeof(SERVER_INFO_100));
					break;
				case 101:
					pserverinfo102 = (SERVER_INFO_102 *)((char *)pserverinfo102  + sizeof(SERVER_INFO_101));
					break;
				case 102:
					pserverinfo102 = (SERVER_INFO_102 *)((char *)pserverinfo102  + sizeof(SERVER_INFO_102));
					break;
				}
			}
		}

		puts("");

		NetApiBufferFree(ptb);
	}

	return netapistatus;
}



DWORD DoNetUserEnum(LPWSTR RemoteName, DWORD Level)
{
	NET_API_STATUS netapistatus;
	LPBYTE ptb;
	DWORD d, dw1, dw2;
	DWORD days, hours, mins, secs;
	struct tm *ptm;


	printf("NetUserEnum() Level %u:\n", Level );

	dw1 = dw2 =  0;

	netapistatus = NetUserEnum(RemoteName, Level, 0, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating users: %s", netapistatus, StrError(netapistatus) );
	} else {
		if (Level >= 20)
		{
			USER_INFO_20 *puserinfo20 = (USER_INFO_20 *)ptb;

			for (d = 0; d < dw1; d++)
			{

				printf("0x%08x:%S - %S\n", puserinfo20->usri20_user_id, puserinfo20->usri20_name, puserinfo20->usri20_comment );
				
				if (puserinfo20->usri20_flags)
				{
					printf(" Flags: ");

					if (puserinfo20->usri20_flags & UF_SCRIPT)
						printf("SCRIPT ");

					if (puserinfo20->usri20_flags & UF_ACCOUNTDISABLE)
						printf("ACCOUNTDISABLE ");

					if (puserinfo20->usri20_flags & UF_HOMEDIR_REQUIRED)
						printf("HOMEDIR_REQUIRED ");

					if (puserinfo20->usri20_flags & UF_HOMEDIR_REQUIRED)
						printf("HOMEDIR_REQUIRED ");

					if (puserinfo20->usri20_flags & UF_PASSWD_NOTREQD)
						printf("PASSWD_NOTREQD ");

					if (puserinfo20->usri20_flags & UF_PASSWD_CANT_CHANGE )
						printf("PASSWD_CANT_CHANGE ");

					if (puserinfo20->usri20_flags & UF_LOCKOUT )
						printf("LOCKOUT ");

					if (puserinfo20->usri20_flags & UF_DONT_EXPIRE_PASSWD )
						printf("DONT_EXPIRE_PASSWD ");

					printf("\n Account type: ");

					if (puserinfo20->usri20_flags & UF_NORMAL_ACCOUNT )
						printf("NORMAL ");

					if (puserinfo20->usri20_flags & UF_TEMP_DUPLICATE_ACCOUNT )
						printf("TEMP_DUPLICATE ");

					if (puserinfo20->usri20_flags & UF_WORKSTATION_TRUST_ACCOUNT)
						printf("WORKSTATION_TRUST ");

					if (puserinfo20->usri20_flags & UF_SERVER_TRUST_ACCOUNT)
						printf("SERVER_TRUST ");

					if (puserinfo20->usri20_flags & UF_INTERDOMAIN_TRUST_ACCOUNT)
						printf("INTERDOMAIN_TRUST ");

					puts("");
				}

				if (puserinfo20->usri20_full_name != NULL && !IsBadStringPtrW(puserinfo20->usri20_full_name, -1) && wcslen(puserinfo20->usri20_full_name) )
					printf(" Full name: \"%S\"\n", puserinfo20->usri20_full_name );

				puserinfo20++;	// only 20 is valid here
			}

		} else if (Level >= 10) {
			USER_INFO_11 *puserinfo11 = (USER_INFO_11 *)ptb;


			for (d = 0; d < dw1; d++)
			{
				printf("%S - %S\n", puserinfo11->usri11_name, puserinfo11->usri11_comment );

				if (puserinfo11->usri11_full_name != NULL && !IsBadStringPtrW(puserinfo11->usri11_full_name, -1) && wcslen(puserinfo11->usri11_full_name) )
					printf(" Full name: \"%S\"\n", puserinfo11->usri11_full_name );

				if (puserinfo11->usri11_usr_comment != NULL && !IsBadStringPtrW(puserinfo11->usri11_usr_comment, -1) && wcslen(puserinfo11->usri11_usr_comment) )
					printf(" User comment: \"%S\"\n", puserinfo11->usri11_usr_comment );

				if (Level > 10)
				{

					if (puserinfo11->usri11_home_dir != NULL && !IsBadStringPtrW(puserinfo11->usri11_home_dir, -1)  && wcslen(puserinfo11->usri11_home_dir) )
						printf(" Home dir:     %S\n", puserinfo11->usri11_home_dir );

#if 0
					if (puserinfo11->usri11_parms != NULL  && !IsBadStringPtrW(puserinfo11->usri11_parms, -1) && wcslen(puserinfo11->usri11_parms) )
						printf(" Parms:        %S\n", puserinfo11->usri11_parms  );
#endif

					if (puserinfo11->usri11_logon_server != NULL && !IsBadStringPtrW(puserinfo11->usri11_logon_server, -1)  && wcslen(puserinfo11->usri11_logon_server)  && wcscmp(puserinfo11->usri11_logon_server, L"\\\\*") != 0)
						printf(" Logon server: %S\n", puserinfo11->usri11_logon_server );

					if (puserinfo11->usri11_workstations != NULL && !IsBadStringPtrW(puserinfo11->usri11_workstations, -1 )  && wcslen(puserinfo11->usri11_workstations ) )
						printf(" Workstations: %S\n", puserinfo11->usri11_workstations );

					switch (puserinfo11->usri11_priv )
					{
					case USER_PRIV_GUEST:
						printf(" GUEST - ");
						break;
					case USER_PRIV_USER:
						printf(" USER  - ");
						break;
					case USER_PRIV_ADMIN:
						printf(" ADMIN - ");
						break;
					default: 
						printf(" ???   - ");
					}

					dw2 = puserinfo11->usri11_password_age;
					days = dw2 / 86400;
					dw2 = dw2 % 86400;
					hours = dw2 / 3600;
					dw2 = dw2 % 3600;
					mins = dw2 / 60;
					dw2 = dw2 % 60;
					secs = dw2;

					printf("Password age: %ud %uh %um %us   ", days, hours, mins, secs );

					printf("Bad pw count: %u   ", puserinfo11->usri11_bad_pw_count);

					printf("# logins: %u   ", puserinfo11->usri11_num_logons );
				
					puts("");

					if (puserinfo11->usri11_last_logon != 0)
					{
						ptm = gmtime((const time_t *)&puserinfo11->usri11_last_logon );
						printf(" Last logon: GMT %s", asctime(ptm) );

					}

					if (puserinfo11->usri11_last_logoff != 0)
					{
						ptm = gmtime((const time_t *)&puserinfo11->usri11_last_logoff );
						printf(" Last logoff: GMT %s", asctime(ptm) );
					}

					if (puserinfo11->usri11_auth_flags)
					{
						printf(" Auth privs: ");

						if (puserinfo11->usri11_auth_flags & AF_OP_PRINT)
							printf("PRINT ");

						if (puserinfo11->usri11_auth_flags & AF_OP_COMM)
							printf("COMM ");

						if (puserinfo11->usri11_auth_flags & AF_OP_SERVER)
							printf("SERVER ");

						if (puserinfo11->usri11_auth_flags & AF_OP_ACCOUNTS)
							printf("ACCOUNTS ");

						puts("");
					}
				}

				switch (Level)
				{
				case 10:
					puserinfo11 = (USER_INFO_11 *)((char *)puserinfo11 + sizeof(USER_INFO_10) );
					break;
				case 11:
					puserinfo11 = (USER_INFO_11 *)((char *)puserinfo11 + sizeof(USER_INFO_11) );
					break;
				}
			}

		} else {
			USER_INFO_3 *puserinfo3 = (USER_INFO_3 *)ptb;

			for (d = 0; d < dw1; d++)
			{
				if (Level == 0)
				{
					printf("\"%S\"\n", puserinfo3->usri3_name);
				} else {
					printf("%S - %S\n", puserinfo3->usri3_name, puserinfo3->usri3_comment );
				}
				
				if (Level > 0)
				{
					if (puserinfo3->usri3_password != NULL && !IsBadStringPtrW(puserinfo3->usri3_password, -1) && wcslen(puserinfo3->usri3_password) )
						printf(" Password: \"%S\"\n", puserinfo3->usri3_password );

					dw2 = puserinfo3->usri3_password_age;
					days = dw2 / 86400;
					dw2 = dw2 % 86400;
					hours = dw2 / 3600;
					dw2 = dw2 % 3600;
					mins = dw2 / 60;
					dw2 = dw2 % 60;
					secs = dw2;

					printf("Password age: %ud %uh %um %us   ", days, hours, mins, secs );

					switch (puserinfo3->usri3_priv )
					{
					case USER_PRIV_GUEST:
						printf(" GUEST - ");
						break;
					case USER_PRIV_USER:
						printf(" USER  - ");
						break;
					case USER_PRIV_ADMIN:
						printf(" ADMIN - ");
						break;
					default: 
						printf(" ???   - ");
					}

					puts("");

 					if (puserinfo3->usri3_home_dir != NULL && !IsBadStringPtrW(puserinfo3->usri3_home_dir, -1)  && wcslen(puserinfo3->usri3_home_dir) )
						printf(" Home dir:     %S\n", puserinfo3->usri3_home_dir );

 					if (puserinfo3->usri3_script_path != NULL && !IsBadStringPtrW(puserinfo3->usri3_script_path, -1)  && wcslen(puserinfo3->usri3_script_path) )
						printf(" Script path:  %S\n", puserinfo3->usri3_script_path );
				}

				if (Level > 1)
				{

					if (puserinfo3->usri3_auth_flags)
					{
						printf(" Auth privs: ");

						if (puserinfo3->usri3_auth_flags & AF_OP_PRINT)
							printf("PRINT ");

						if (puserinfo3->usri3_auth_flags & AF_OP_COMM)
							printf("COMM ");

						if (puserinfo3->usri3_auth_flags & AF_OP_SERVER)
							printf("SERVER ");

						if (puserinfo3->usri3_auth_flags & AF_OP_ACCOUNTS)
							printf("ACCOUNTS ");

						puts("");
					}

					if (puserinfo3->usri3_full_name != NULL && !IsBadStringPtrW(puserinfo3->usri3_full_name, -1) && wcslen(puserinfo3->usri3_full_name) )
						printf(" Full name: \"%S\"\n", puserinfo3->usri3_full_name );

					if (puserinfo3->usri3_usr_comment != NULL && !IsBadStringPtrW(puserinfo3->usri3_usr_comment, -1) && wcslen(puserinfo3->usri3_usr_comment) )
						printf(" User comment: \"%S\"\n", puserinfo3->usri3_usr_comment );

#if 0
					if (puserinfo3->usri3_parms != NULL  && !IsBadStringPtrW(puserinfo3->usri3_parms, -1) && wcslen(puserinfo3->usri3_parms) )
						printf(" Parms:        %S\n", puserinfo3->usri3_parms  );
#endif

					if (puserinfo3->usri3_workstations != NULL && !IsBadStringPtrW(puserinfo3->usri3_workstations, -1 )  && wcslen(puserinfo3->usri3_workstations ) )
						printf(" Workstations: %S\n", puserinfo3->usri3_workstations );

					if (puserinfo3->usri3_last_logon != 0)
					{
						ptm = gmtime((const time_t *)&puserinfo3->usri3_last_logon );
						printf(" Last logon: GMT %s", asctime(ptm) );

					}

					if (puserinfo3->usri3_last_logoff != 0)
					{
						ptm = gmtime((const time_t *)&puserinfo3->usri3_last_logoff );
						printf(" Last logoff: GMT %s", asctime(ptm) );
					}

					printf("Bad pw count: %u   ", puserinfo3->usri3_bad_pw_count);

					printf("# logins: %u   ", puserinfo3->usri3_num_logons );
				
					puts("");

					if (puserinfo3->usri3_profile != NULL && !IsBadStringPtrW(puserinfo3->usri3_profile, -1)  && wcslen(puserinfo3->usri3_profile)  )
						printf(" Profile:      %S\n", puserinfo3->usri3_profile );

					if (puserinfo3->usri3_home_dir_drive != NULL && !IsBadStringPtrW(puserinfo3->usri3_home_dir_drive, -1)  && wcslen(puserinfo3->usri3_home_dir_drive)  )
						printf(" Homedir drive:%S\n", puserinfo3->usri3_home_dir_drive);


				}

				if (Level > 2)
				{
					printf("User ID:  0x%08x    Group ID: 0x%08x\n", puserinfo3->usri3_user_id, puserinfo3->usri3_primary_group_id );

					if (puserinfo3->usri3_logon_server != NULL && !IsBadStringPtrW(puserinfo3->usri3_logon_server, -1)  && wcslen(puserinfo3->usri3_logon_server)  && wcscmp(puserinfo3->usri3_logon_server, L"\\\\*") != 0)
						printf(" Logon server: %S\n", puserinfo3->usri3_logon_server );

				}

				switch (Level)
				{
				case 0:
					puserinfo3 = (USER_INFO_3 *)((char *)puserinfo3 + sizeof(USER_INFO_0) );
					break;
				case 1:
					puserinfo3 = (USER_INFO_3 *)((char *)puserinfo3 + sizeof(USER_INFO_1) );
					break;
				case 2:
					puserinfo3 = (USER_INFO_3 *)((char *)puserinfo3 + sizeof(USER_INFO_2) );
					break;
				case 3:
					puserinfo3 = (USER_INFO_3 *)((char *)puserinfo3 + sizeof(USER_INFO_3) );
					break;
				}

			}
		}

		puts("");

		NetApiBufferFree(ptb);
	}


	return netapistatus;
}


DWORD DoNetLocalGroupGetMembers(LPWSTR RemoteName, LPWSTR GroupName, DWORD Level)
{
	NET_API_STATUS netapistatus;
	DWORD d, dw1, dw2;
	LPBYTE ptb;

	netapistatus = NetLocalGroupGetMembers(RemoteName, GroupName, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);

	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating local group members: %s", netapistatus, StrError(netapistatus) );
	} else {
		LOCALGROUP_MEMBERS_INFO_2 *plocalgroupmembersinfo2 = (LOCALGROUP_MEMBERS_INFO_2 *)ptb;

		for (d = 0; d < dw1; d++)
		{
			printf(" %S - ", plocalgroupmembersinfo2->lgrmi2_domainandname );
			switch (plocalgroupmembersinfo2->lgrmi2_sidusage)
			{
			case SidTypeUser:
				printf("User account");
				break;
			case SidTypeGroup:
				printf("Global group account");
				break;
			case SidTypeWellKnownGroup:
				printf("Well-Known group account");
				break;
			case SidTypeDeletedAccount:
				printf("Deleted account");
				break;
			case SidTypeUnknown:
				printf("Unknown SID type");
				break;
			}

			puts("");

			switch (Level)
			{
			case 0:
				plocalgroupmembersinfo2 = (LOCALGROUP_MEMBERS_INFO_2 *)((char *)plocalgroupmembersinfo2 + sizeof(LOCALGROUP_MEMBERS_INFO_0) );
				break;
			case 1:
				plocalgroupmembersinfo2 = (LOCALGROUP_MEMBERS_INFO_2 *)((char *)plocalgroupmembersinfo2 + sizeof(LOCALGROUP_MEMBERS_INFO_1) );
				break;
			case 2:
				plocalgroupmembersinfo2 = (LOCALGROUP_MEMBERS_INFO_2 *)((char *)plocalgroupmembersinfo2 + sizeof(LOCALGROUP_MEMBERS_INFO_2) );
				break;
			}
		}

		NetApiBufferFree(ptb);
	}


	return netapistatus;
}

DWORD DoNetLocalGroupEnum(LPWSTR RemoteName, DWORD Level)
{
	NET_API_STATUS netapistatus;
	DWORD d, dw1, dw2;
	LPBYTE ptb;
	dw1 = dw2 =  0;

	printf("NetLocalGroupEnum() Level %u:\n", Level );

	netapistatus = NetLocalGroupEnum(RemoteName, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating local groups: %s", netapistatus, StrError(netapistatus) );
	} else {
		LOCALGROUP_INFO_1 *plocalgroupinfo1 = (LOCALGROUP_INFO_1 *)ptb;

		for (d = 0; d < dw1; d++)
		{
			printf("%S - %S\n", plocalgroupinfo1->lgrpi1_name,  plocalgroupinfo1->lgrpi1_comment );

			if (DoNetLocalGroupGetMembers(RemoteName, plocalgroupinfo1->lgrpi1_name, 2 ) != NERR_Success )
				DoNetLocalGroupGetMembers(RemoteName, plocalgroupinfo1->lgrpi1_name, 1 ) ;

			switch (Level)
			{
			case 0:
				plocalgroupinfo1 = (LOCALGROUP_INFO_1 *)((char *)plocalgroupinfo1 + sizeof(LOCALGROUP_INFO_0) );
				break;
			case 1:
				plocalgroupinfo1 = (LOCALGROUP_INFO_1 *)((char *)plocalgroupinfo1 + sizeof(LOCALGROUP_INFO_1) );
				break;
			}
		}

		puts("");

		NetApiBufferFree(ptb);
	}

	return netapistatus;
}



DWORD DoNetGroupGetUsers(LPWSTR RemoteName, LPWSTR GroupName, DWORD Level)
{
	NET_API_STATUS netapistatus;
	DWORD d, dw1, dw2;
	LPBYTE ptb;

	netapistatus = NetGroupGetUsers(RemoteName, GroupName, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating global group members: %s", netapistatus, StrError(netapistatus) );
	} else {
		GROUP_USERS_INFO_1 *pgroupusersinfo1 = (GROUP_USERS_INFO_1 *)ptb;

		for (d = 0; d < dw1; d++)
		{
			printf("  %S", pgroupusersinfo1->grui1_name);

			if (Level > 0)
			{
				printf("(0x%08X)", pgroupusersinfo1->grui1_attributes );
			}
			switch (Level)
			{
			case 0:
				pgroupusersinfo1 = (GROUP_USERS_INFO_1 *)((char *)pgroupusersinfo1 + sizeof(GROUP_USERS_INFO_0) );
				break;
			case 1:
				pgroupusersinfo1 = (GROUP_USERS_INFO_1 *)((char *)pgroupusersinfo1 + sizeof(GROUP_USERS_INFO_1) );
				break;
			}
		}
		puts("");

		NetApiBufferFree(ptb);
	}

	return netapistatus;
}



DWORD DoNetGroupEnum(LPWSTR RemoteName, DWORD Level)
{
	NET_API_STATUS netapistatus;
	DWORD d, dw1, dw2;
	LPBYTE ptb;

	dw1 = dw2 =  0;

	printf("NetGroupEnum() Level %u:\n", Level );

	netapistatus = NetGroupEnum(RemoteName, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating global groups: %s", netapistatus, StrError(netapistatus) );
	} else {
		GROUP_INFO_2 *pgroupinfo2 = (GROUP_INFO_2 *)ptb;

		for (d = 0; d < dw1; d++)
		{
			printf("%08X - %S - %S\n", pgroupinfo2->grpi2_group_id, pgroupinfo2->grpi2_name, pgroupinfo2->grpi2_comment);

			if (DoNetGroupGetUsers(RemoteName, pgroupinfo2->grpi2_name, 1 ) != NERR_Success )
				DoNetGroupGetUsers(RemoteName, pgroupinfo2->grpi2_name, 0 ) ;


			switch (Level)
			{
			case 0:
				pgroupinfo2 = (GROUP_INFO_2 *)((char *)pgroupinfo2 + sizeof(GROUP_INFO_0) );
				break;
			case 1:
				pgroupinfo2 = (GROUP_INFO_2 *)((char *)pgroupinfo2 + sizeof(GROUP_INFO_1) );
				break;
			case 2:
				pgroupinfo2 = (GROUP_INFO_2 *)((char *)pgroupinfo2 + sizeof(GROUP_INFO_2) );
				break;
			}
		}

		puts("");

		NetApiBufferFree(ptb);
	}

	return netapistatus;
}




DWORD DoNetFileEnum(LPWSTR RemoteName, DWORD Level)
{
	NET_API_STATUS netapistatus;
	DWORD d, dw1, dw2;
	LPBYTE ptb;

	printf("NetFileEnum() Level %u:\n", Level );

	dw1 = dw2 =  0;
	netapistatus = NetFileEnum((char *)RemoteName, NULL, NULL, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating open files: %s", netapistatus, StrError(netapistatus) );
	} else {
		FILE_INFO_3 *pfileinfo3 = (FILE_INFO_3 *)ptb;
		
		for (d = 0; d < dw1; d++)
		{
			printf("File ID: 0x%08X  ", pfileinfo3->fi3_id );

			if (Level > 2)
			{
				printf("Locks: %u  Permissions:", pfileinfo3->fi3_num_locks);

				if (pfileinfo3->fi3_permissions & PERM_FILE_READ)
					printf("READ ");

				if (pfileinfo3->fi3_permissions & PERM_FILE_WRITE)
					printf("WRITE ");

				if (pfileinfo3->fi3_permissions & PERM_FILE_CREATE)
					printf("CREATE ");

				puts("");

				if (pfileinfo3->fi3_username != NULL && wcslen((LPWORD)pfileinfo3->fi3_username) )
					printf(" Username: %S\n", pfileinfo3->fi3_username );
					
				if (pfileinfo3->fi3_pathname != NULL && wcslen((LPWORD)pfileinfo3->fi3_pathname) )
					printf(" Pathname: %S\n", pfileinfo3->fi3_pathname );


			} else {
				puts("");
			}

			switch (Level)
			{
			case 2:
				pfileinfo3 = (FILE_INFO_3 *)((char *)pfileinfo3 + sizeof(FILE_INFO_2) );
				break;
			case 3:
				pfileinfo3 = (FILE_INFO_3 *)((char *)pfileinfo3 + sizeof(FILE_INFO_3) );
				break;
			}
		}


		puts("");

		NetApiBufferFree(ptb);
	}


	return netapistatus;
}


DWORD DoNetMessageNameEnum(LPWSTR RemoteName, DWORD Level)
{
	NET_API_STATUS netapistatus;
	DWORD d, dw1, dw2;
	LPBYTE ptb;

	printf("NetMessageNameEnum() Level %u:\n", Level );

	dw1 = dw2 =  0;

	netapistatus = NetMessageNameEnum(RemoteName, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating message names: %s", netapistatus, StrError(netapistatus) );
	} else {
		MSG_INFO_1 *pmsginfo1 = (MSG_INFO_1 *)ptb;

		for (d = 0; d < dw1; d++)
		{
			printf("Name: \"%S\" ", pmsginfo1->msgi1_name);

			if (Level > 0)
			{
				if (pmsginfo1->msgi1_forward_flag != MSGNAME_NOT_FORWARDED )
				{
					if (pmsginfo1->msgi1_forward_flag & MSGNAME_FORWARDED_TO)
						printf("FORWARDED_TO ");

					if (pmsginfo1->msgi1_forward_flag & MSGNAME_FORWARDED_FROM)
						printf("FORWARDED_FROM ");

					if (pmsginfo1->msgi1_forward != NULL && wcslen(pmsginfo1->msgi1_forward ) )
						printf("\"%S\"", pmsginfo1->msgi1_forward );
				}
			}

			puts("");


			switch (Level)
			{
			case 0:
				pmsginfo1 = (MSG_INFO_1 *)((char *)pmsginfo1 + sizeof(MSG_INFO_0) );
				break;
			case 1:
				pmsginfo1 = (MSG_INFO_1 *)((char *)pmsginfo1 + sizeof(MSG_INFO_1) );
				break;
			}
		}

		puts("");

		NetApiBufferFree(ptb);
	}


	return netapistatus;
}



DWORD DoNetReplExportDirEnum(LPWSTR RemoteName, DWORD Level)
{
	NET_API_STATUS netapistatus;
	DWORD d, dw1, dw2;
	LPBYTE ptb;

	printf("NetReplExportDirEnum() Level %u:\n", Level );

	dw1 = dw2 =  0;

	netapistatus = NetReplExportDirEnum(RemoteName, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating replicated exports: %s", netapistatus, StrError(netapistatus) );
	} else {
		REPL_EDIR_INFO_2 *prepledirinfo2 = (REPL_EDIR_INFO_2 *)ptb;

		for (d = 0; d < dw1; d++)
		{
			printf("Name: \"%S\"  ", prepledirinfo2->rped2_dirname);

			if (Level > 0)
			{
				printf("Integrity: ");
				if (prepledirinfo2->rped2_integrity == REPL_INTEGRITY_TREE)
					printf("TREE ");
				else if (prepledirinfo2->rped2_integrity == REPL_INTEGRITY_FILE)
					printf("FILE ");
				else
					printf("NONE ");

				printf(" Extent: ");
				if (prepledirinfo2->rped2_extent == REPL_EXTENT_FILE)
					printf("FILE ");
				else if (prepledirinfo2->rped2_extent == REPL_EXTENT_TREE)
					printf("TREE ");
				else
					printf("NONE ");

				puts("");
			}

			if (Level > 1)
			{
				printf(" Lock count: %u   Lock time: %u secs since 1970\n", prepledirinfo2->rped2_lockcount, prepledirinfo2->rped2_locktime );
			}


			switch (Level)
			{
			case 0:
				prepledirinfo2 = (REPL_EDIR_INFO_2 *)((char *)prepledirinfo2 + sizeof(REPL_EDIR_INFO_0) );
				break;
			case 1:
				prepledirinfo2 = (REPL_EDIR_INFO_2 *)((char *)prepledirinfo2 + sizeof(REPL_EDIR_INFO_1) );
				break;
			case 2:
				prepledirinfo2 = (REPL_EDIR_INFO_2 *)((char *)prepledirinfo2 + sizeof(REPL_EDIR_INFO_2) );
				break;
			}

		}

		puts("");

		NetApiBufferFree(ptb);

	}
	return netapistatus;
}


DWORD DoNetServiceEnum(LPWSTR RemoteName, DWORD Level)
{
	NET_API_STATUS netapistatus;
	DWORD d, dw1, dw2;
	LPBYTE ptb;

	printf("NetServiceEnum() Level %u:\n", Level );

	dw1 = dw2 =  0;

	netapistatus = NetServiceEnum(RemoteName, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating services: %s", netapistatus, StrError(netapistatus) );
	} else {
		SERVICE_INFO_2 *pserviceinfo2 = (SERVICE_INFO_2 *)((char *)ptb);

		for (d = 0; d < dw1; d++)
		{
			printf("\"%S\"  ", pserviceinfo2->svci2_name );

			if (Level > 0)
			{
				printf("Status:0x%08X  Code:0x%08x  PID:0x%08x", pserviceinfo2->svci2_status, pserviceinfo2->svci2_code, pserviceinfo2->svci2_pid );
			}

			puts("");

			if (Level > 1)
			{
				if (pserviceinfo2->svci2_text != NULL)
					printf(" %S\n", pserviceinfo2->svci2_text );

				if (pserviceinfo2->svci2_display_name != NULL)
					printf(" %S\n", pserviceinfo2->svci2_display_name );
			}

			switch (Level)
			{
			case 0:
				pserviceinfo2 = (SERVICE_INFO_2 *)((char *)pserviceinfo2 + sizeof(SERVICE_INFO_0) );
				break;
			case 1:
				pserviceinfo2 = (SERVICE_INFO_2 *)((char *)pserviceinfo2 + sizeof(SERVICE_INFO_1) );
				break;
			case 2:
				pserviceinfo2 = (SERVICE_INFO_2 *)((char *)pserviceinfo2 + sizeof(SERVICE_INFO_2) );
				break;
			}
		}

		NetApiBufferFree(ptb);
	}

	return netapistatus;
}

DWORD DoNetReplImportDirEnum(LPWSTR RemoteName, DWORD Level)
{
	NET_API_STATUS netapistatus;
	DWORD d, dw1, dw2;
	LPBYTE ptb;

	printf("NetReplImportDirEnum() Level %u:\n", Level );

	dw1 = dw2 =  0;

	netapistatus = NetReplImportDirEnum(RemoteName, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating replicated imports: %s", netapistatus, StrError(netapistatus) );
	} else {
		REPL_IDIR_INFO_1 *preplidirinfo1 = (REPL_IDIR_INFO_1 *)ptb;

		for (d = 0; d < dw1; d++)
		{
			printf("Directory: %S  ", preplidirinfo1->rpid1_dirname );

			if (Level > 0)
			{
				printf("Master name: \"%S\"  Lock count: %u\n", preplidirinfo1->rpid1_mastername, preplidirinfo1->rpid1_lockcount);

			}

			switch (Level)
			{
			case 0:
				preplidirinfo1 = (REPL_IDIR_INFO_1 *)((char *)preplidirinfo1 + sizeof(REPL_IDIR_INFO_0) );
				break;
			case 1:
				preplidirinfo1 = (REPL_IDIR_INFO_1 *)((char *)preplidirinfo1 + sizeof(REPL_IDIR_INFO_1) );
				break;
			}
		}
		puts("");

		NetApiBufferFree(ptb);

	}
	return netapistatus;
}


DWORD DoNetScheduleJobEnum(LPWSTR RemoteName)
{
	NET_API_STATUS netapistatus;
	DWORD d, dw1, dw2;
	LPBYTE ptb;

	printf("NetScheduleJobEnum():\n");

	dw1 = dw2 = 0;

	netapistatus = NetScheduleJobEnum(RemoteName, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating scheduled jobs: %s", netapistatus, StrError(netapistatus) );

	} else {
		AT_ENUM *patenum = (AT_ENUM *)ptb;

		for (d = 0; d < dw1; d++)
		{
			printf("0x%08X:\"%S\"\n", patenum->JobId, patenum->Command );
			patenum++;
		}

		puts("");

		NetApiBufferFree(ptb);
	}


	return netapistatus;
}


DWORD DoNetServerDiskEnum(LPCWSTR RemoteName, DWORD Level)
{
	NET_API_STATUS netapistatus;
	DWORD d, dw1, dw2;
	LPBYTE ptb;
	

	printf("NetServerDiskEnum() Level %u:\n", Level);

	dw1 = dw2 = 0;

	netapistatus = NetServerDiskEnum((char *)RemoteName, Level, &ptb, MAX_PREFERRED_LENGTH, &dw1, &dw2, NULL);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d enumerating server disks: %s", netapistatus, StrError(netapistatus) );
	} else {
		LPWSTR ptr = (LPWSTR)ptb;

		for (d = 0; d < dw1; d++)
		{
			printf(" %S", ptr);
			ptr += 3;
		}

		puts("");

		NetApiBufferFree(ptb);

	}

	return netapistatus;
}



DWORD DoServiceEnum(LPCTSTR RemoteName )
{
	DWORD z, d, dw1, dw2;
	ENUM_SERVICE_STATUS *pservicestatus;
	SC_HANDLE schandle;
	char buff[102400];

	printf("EnumServiceStatus():\n");

	schandle = OpenSCManager(RemoteName, NULL, SC_MANAGER_ENUMERATE_SERVICE );

	if (schandle == NULL)
	{
		d = GetLastError();
		printf("Error %d opening service manager: %s\n\n", d, StrError(d) );
	} else {
		d = dw1 = dw2 = 0;

		if (EnumServicesStatus(schandle, SERVICE_WIN32|SERVICE_DRIVER, SERVICE_STATE_ALL, (ENUM_SERVICE_STATUS *)buff, sizeof(buff), &dw1, &dw2, &d) != 0)
		{
			pservicestatus = (ENUM_SERVICE_STATUS *)buff;
			for (z = 0; z < dw2; z++)
			{
				printf("\"%s\":\"%s\"\n", pservicestatus[z].lpDisplayName, pservicestatus[z].lpServiceName);

				if (pservicestatus[z].ServiceStatus.dwServiceType )
					printf(" Type:");
				if (pservicestatus[z].ServiceStatus.dwServiceType & SERVICE_WIN32_OWN_PROCESS)
					printf(" WIN32_OWN_PROCESS");
				if (pservicestatus[z].ServiceStatus.dwServiceType & SERVICE_WIN32_SHARE_PROCESS)
					printf(" WIN32_SHARE_PROCESS");
				if (pservicestatus[z].ServiceStatus.dwServiceType & SERVICE_KERNEL_DRIVER)
					printf(" KERNEL_DRIVER");
				if (pservicestatus[z].ServiceStatus.dwServiceType & SERVICE_FILE_SYSTEM_DRIVER)
					printf(" FILE_SYSTEM_DRIVER");
				if (pservicestatus[z].ServiceStatus.dwServiceType & SERVICE_INTERACTIVE_PROCESS )
					printf(" INTERACTIVE_PROCESS");

				puts("");

				printf(" Current state: ");
				switch (pservicestatus[z].ServiceStatus.dwCurrentState)
				{
				case SERVICE_STOPPED:
					printf("The service is not running");
					break;
					break;
				case SERVICE_START_PENDING:
					printf("The service is starting");
					break;
				case SERVICE_STOP_PENDING:
					printf("The service is stopping");
					break;
				case SERVICE_RUNNING:
					printf("The service is running");
					break;
				case SERVICE_CONTINUE_PENDING:
					printf("The service continue is pending");
					break;
				case SERVICE_PAUSE_PENDING:
					printf("The service pause is pending");
					break;
				case SERVICE_PAUSED:
					printf("The service is paused");
					break;
				}
				puts("");

				if (pservicestatus[z].ServiceStatus.dwControlsAccepted )
				{
					printf(" Controls accepted: ");
					if ( pservicestatus[z].ServiceStatus.dwControlsAccepted & SERVICE_ACCEPT_STOP)
						printf("STOP ");
					if ( pservicestatus[z].ServiceStatus.dwControlsAccepted & SERVICE_ACCEPT_PAUSE_CONTINUE)
						printf("PAUSE_CONTINUE ");
					if ( pservicestatus[z].ServiceStatus.dwControlsAccepted & SERVICE_ACCEPT_SHUTDOWN)
						printf("SHUTDOWN ");

					puts("");
				}
				
				if (pservicestatus[z].ServiceStatus.dwWin32ExitCode && pservicestatus[z].ServiceStatus.dwWin32ExitCode != 1077)
					printf(" Win32 error: %u:%s", pservicestatus[z].ServiceStatus.dwWin32ExitCode, StrError(pservicestatus[z].ServiceStatus.dwWin32ExitCode) );

			}
		}

		CloseServiceHandle(schandle);
	}

	return 0;
}




DWORD DoNetStatisticsGet(LPWSTR RemoteName, LPWSTR ServiceName, DWORD Level )
{
	NET_API_STATUS netapistatus;
	LPBYTE ptb;

	printf("NetStatisticsGet(%S) Level %u:\n", ServiceName, Level);

	netapistatus = NetStatisticsGet((char *)RemoteName, (char *)ServiceName, Level, 0, &ptb);
	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d getting statistics: %s", netapistatus, StrError(netapistatus) );
	} else {
		if (wcscmp(ServiceName, L"SERVER") == 0)
		{
			STAT_SERVER_0 *pstatserver0 = (STAT_SERVER_0 *)ptb;

		} else if (wcscmp(ServiceName, L"WORKSTATION") == 0) {
			STAT_WORKSTATION_0 *pstatworkstation0 = (STAT_WORKSTATION_0 *)ptb;

		}

		puts("Not yet implemented");

		NetApiBufferFree(ptb);
	}

	return netapistatus;
}


DWORD DoNetEnumerateTrustedDomains(LPWSTR RemoteName)
{
	NET_API_STATUS netapistatus;
	LPWSTR lptr;
	LPWSTR pNames;

	printf("NetEnumerateTrustedDomains():\n");

	netapistatus = NetEnumerateTrustedDomains(RemoteName, &pNames);
	if (netapistatus != NERR_Success || pNames == NULL)
	{
		printf("Error 0x%X getting trusted domains: %s", netapistatus, StrError(netapistatus) );
	} else {

		lptr = (LPWSTR)pNames;

		while (*lptr != 0)
		{
			printf("%S\n", lptr );
			lptr += wcslen(lptr) + 1;
		}

		NetApiBufferFree(pNames);
	}


	return netapistatus;
}



DWORD DoNetRemoteComputerSupports(LPWSTR RemoteName)
{
	NET_API_STATUS netapistatus;
	DWORD d = 0;

	puts("NetRemoteComputerSupports():");

	netapistatus = NetRemoteComputerSupports(RemoteName, SUPPORTS_ANY, &d);

	if (netapistatus != NERR_Success)
	{
		printf("Error 0x%X calling NetRemoteComputerSupports: %s", netapistatus, StrError(netapistatus) );
	} else {

		g_Support = d;

		if (d & SUPPORTS_REMOTE_ADMIN_PROTOCOL)
			puts(" Remote Admin Protocol");

		if (d & SUPPORTS_RPC)
			puts(" Remote Procedure Protocol");

		if (d & SUPPORTS_SAM_PROTOCOL)
			puts(" SAM Protocol");

		if (d & SUPPORTS_UNICODE)
			puts(" Unicode");

		if (d & SUPPORTS_LOCAL)
			puts(" Local");

		if (d & 0x1)
			printf(" 0x00000001");

		if (d & 0x00000040)
			printf(" 0x00000040");

		if (d & 0x00000080)
			printf(" 0x00000080");

		if (d & 0x000000A0)
			printf(" 0x000000A0");

		puts("");
			
	}

	return netapistatus;
}


DWORD DoEnumPorts(char *RemoteName, DWORD Level)
{
	BOOL ret;
	DWORD d, dw1, dw2;
	unsigned char buff[65536];

	printf("EnumPorts() Level %u:\n", Level );

	dw1 = dw2 =  0;

	ret = EnumPorts(RemoteName, Level, buff, 65536, &dw1, &dw2);
	if (ret == 0)
	{
		d = GetLastError();
		printf("Error %d enumerating printer ports: %s", d, StrError(d) );
	} else {
		LPPORT_INFO_2 pportinfo2 = (LPPORT_INFO_2)buff;

		for (d = 0; d < dw2; d++)
		{
			printf("%s ", pportinfo2->pPortName);

			if (Level > 1)
			{
				printf("\"%s\"  Monitor: \"%s\" ", pportinfo2->pDescription, pportinfo2->pMonitorName); 

				if (pportinfo2->fPortType & PORT_TYPE_READ)
					printf("READ ");

				if (pportinfo2->fPortType & PORT_TYPE_WRITE)
					printf("WRITE ");

				if (pportinfo2->fPortType & PORT_TYPE_REDIRECTED)
					printf("REDIRECTED ");

				if (pportinfo2->fPortType & PORT_TYPE_NET_ATTACHED)
					printf("NETATTACHED ");
			}

			puts("");

			switch (Level)
			{
			case 1:
				pportinfo2 = (LPPORT_INFO_2)((char *)pportinfo2 + sizeof(PORT_INFO_1) );
				break;
			case 2:
				pportinfo2 = (LPPORT_INFO_2)((char *)pportinfo2 + sizeof(PORT_INFO_2) );
				break;

			}
		}
	}

	return ret;
}

DWORD DoEnumMonitors(char *RemoteName, DWORD Level)
{
	BOOL ret;
	DWORD d, dw1, dw2;
	unsigned char buff[65536];

	printf("EnumMonitors() Level %u:\n", Level );

	dw1 = dw2 =  0;

	ret = EnumMonitors(RemoteName, Level, buff, 65536, &dw1, &dw2);
	if (ret == 0)
	{
		d = GetLastError();
		printf("Error %d enumerating printer monitors: %s", d, StrError(d) );
	} else {
		LPMONITOR_INFO_2 pmonitorinfo2 = (LPMONITOR_INFO_2)buff;


		for (d = 0; d < dw2; d++)
		{
			printf("%s ", pmonitorinfo2->pName);

			if (Level > 1)
				printf("%s %s", pmonitorinfo2->pEnvironment, pmonitorinfo2->pDLLName);

			puts("");

			switch (Level)
			{
			case 1:
				pmonitorinfo2 = (LPMONITOR_INFO_2)((char *)pmonitorinfo2 + sizeof(MONITOR_INFO_1) );
				break;
			case 2:
				pmonitorinfo2 = (LPMONITOR_INFO_2)((char *)pmonitorinfo2 + sizeof(MONITOR_INFO_2) );
				break;

			}
		}
	}
	return ret;
}


DWORD DoEnumPrinterDrivers(char *RemoteName, DWORD Level)
{
	BOOL ret;
	DWORD d, dw1, dw2;
	unsigned char buff[65536];

	printf("EnumPrinterDrivers() Level %u:\n", Level );

	dw1 = dw2 =  0;

	ret = EnumPrinterDrivers(RemoteName, NULL, Level, buff, 65536, &dw1, &dw2);
	if (ret == 0)
	{
		d = GetLastError();
		printf("Error %d enumerating printer drivers: %s", d, StrError(d) );
	} else {
		LPDRIVER_INFO_3 pdriverinfo3= (LPDRIVER_INFO_3)buff;


		for (d = 0; d < dw2; d++)
		{
			if (Level == 1)
				printf("%s\n", *(LPSTR)pdriverinfo3);
			else
				printf("%s  ", pdriverinfo3->pName);

			if (Level > 1)
			{
				printf("%s  %s\n", pdriverinfo3->pEnvironment, pdriverinfo3->pDriverPath);
				printf(" %s  %s\n", pdriverinfo3->pDataFile , pdriverinfo3->pConfigFile );
			}

			if (Level > 2)
			{
				printf( " %s  %s\n", pdriverinfo3->pHelpFile, pdriverinfo3->pDependentFiles );
				printf( " %s  %s\n", pdriverinfo3->pMonitorName, pdriverinfo3->pDefaultDataType);
			}

			

			switch (Level)
			{
			case 1:
				pdriverinfo3= (LPDRIVER_INFO_3 )((char *)pdriverinfo3 + sizeof(DRIVER_INFO_1) );
				break;
			case 2:
				pdriverinfo3= (LPDRIVER_INFO_3 )((char *)pdriverinfo3 + sizeof(DRIVER_INFO_2) );
				break;
			case 3:
				pdriverinfo3= (LPDRIVER_INFO_3 )((char *)pdriverinfo3 + sizeof(DRIVER_INFO_3) );
				break;
			}
		}
	}
	return ret;
}


DWORD DoEnumPrinters(char *RemoteName, DWORD Level)
{
	DWORD ret = 0;
	unsigned char buff[65536];
	DWORD d, bytesneeded, structs;

	printf("EnumPrinters() Level %d:\n", Level);

	ret = EnumPrinters(PRINTER_ENUM_NAME, RemoteName, Level, buff, sizeof(buff), &bytesneeded, &structs) ;
	if ( ret == 0)
	{
		d = GetLastError();
		printf("Error %d enumerating printers: %s", d, StrError(d) );
	} else {
		switch (Level)
		{
		case 1:
			{
				LPPRINTER_INFO_1 pprinterinfo1 = (LPPRINTER_INFO_1)buff;
				for (d = 0; d < structs; d++)
				{
					printf("%s - %s\n", pprinterinfo1->pName, pprinterinfo1->pDescription);

					if (strlen(pprinterinfo1->pComment))
						printf(" Comment: \"%s\"\n", pprinterinfo1->pComment);

					printf(" Flags: ");

					if (pprinterinfo1->Flags & PRINTER_ENUM_EXPAND)
						printf("EXPAND ");

					if (pprinterinfo1->Flags & PRINTER_ENUM_CONTAINER)
						printf("CONTAINER ");

					if (pprinterinfo1->Flags & PRINTER_ENUM_ICON1)
						printf("ICON1 ");

					if (pprinterinfo1->Flags & PRINTER_ENUM_ICON2)
						printf("ICON2 ");

					if (pprinterinfo1->Flags & PRINTER_ENUM_ICON3)
						printf("ICON3 ");

					if (pprinterinfo1->Flags & PRINTER_ENUM_ICON4)
						printf("ICON4 ");

					if (pprinterinfo1->Flags & PRINTER_ENUM_ICON5)
						printf("ICON5 ");

					if (pprinterinfo1->Flags & PRINTER_ENUM_ICON6)
						printf("ICON6 ");

					if (pprinterinfo1->Flags & PRINTER_ENUM_ICON7)
						printf("ICON7 ");

					if (pprinterinfo1->Flags & PRINTER_ENUM_ICON8)
						printf("ICON8 ");

					puts("");

					pprinterinfo1++;
				}
			}
			break;
		case 2:
			{
				LPPRINTER_INFO_2 pprinterinfo2 = (LPPRINTER_INFO_2)buff;
				for (d = 0; d < structs; d++)
				{
					printf("Name:\"%s\"  Server:\"%s\"\n", pprinterinfo2->pPrinterName, pprinterinfo2->pServerName);
					printf(" Port:\"%s\"  Share:\"%s\"\n", pprinterinfo2->pPortName, pprinterinfo2->pShareName);
					printf(" Driver:\"%s\"  Comment:\"%s\"\n", pprinterinfo2->pDriverName, pprinterinfo2->pComment);
					printf(" Location:\"%s\"  Separator file:\"%s\"\n", pprinterinfo2->pLocation, pprinterinfo2->pSepFile);
					printf(" Processor:\"%s\"  Data type:\"%s\"\n", pprinterinfo2->pPrintProcessor, pprinterinfo2->pDatatype );
					printf(" Paramaters:\"%s\" \n", pprinterinfo2->pParameters);
					if (IsValidSecurityDescriptor(pprinterinfo2->pSecurityDescriptor) )
						DisplaySecurityDescriptorInfo((LPWSTR)RemoteName, pprinterinfo2->pSecurityDescriptor, FALSE);

					pprinterinfo2++;
				}
			}
			break;
		case 5:
			{
				LPPRINTER_INFO_5 pprinterinfo5 = (LPPRINTER_INFO_5)buff;
				for (d = 0; d < structs; d++)
				{
					printf("Name:\"%s\"  Port:\"%s\"\n", pprinterinfo5->pPrinterName, pprinterinfo5->pPortName);
					printf(" Attributes: ");

					if (pprinterinfo5->Attributes & PRINTER_ATTRIBUTE_DEFAULT)
						printf("DEFAULT ");

					if (pprinterinfo5->Attributes & PRINTER_ATTRIBUTE_DIRECT)
						printf("DIRECT ");

					if (pprinterinfo5->Attributes & PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST)
						printf("DO_COMPLETE_FIRST ");

					if (pprinterinfo5->Attributes & PRINTER_ATTRIBUTE_ENABLE_BIDI)
						printf("ENABLE_BIDI ");

					if (pprinterinfo5->Attributes & PRINTER_ATTRIBUTE_ENABLE_DEVQ)
						printf("ENABLE_DEVQ ");

					if (pprinterinfo5->Attributes & PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS)
						printf("KEEPPRINTEDJOBS ");

					if (pprinterinfo5->Attributes & PRINTER_ATTRIBUTE_QUEUED)
						printf("QUEUED ");

					if (pprinterinfo5->Attributes & PRINTER_ATTRIBUTE_SHARED)
						printf("SHARED ");
					
					if (pprinterinfo5->Attributes & PRINTER_ATTRIBUTE_WORK_OFFLINE)
						printf("WORK_OFFLINE ");

					if (pprinterinfo5->Attributes & PRINTER_ATTRIBUTE_PUBLISHED)
						printf("PUBLISHED ");

					if (pprinterinfo5->Attributes & PRINTER_ATTRIBUTE_NETWORK)
						printf("NETWORK ");

					if (pprinterinfo5->Attributes & PRINTER_ATTRIBUTE_HIDDEN)
						printf("HIDDEN ");

					if (pprinterinfo5->Attributes & PRINTER_ATTRIBUTE_LOCAL)
						printf("LOCAL ");

					if (pprinterinfo5->Attributes & PRINTER_ATTRIBUTE_RAW_ONLY)
						printf("RAW_ONLY ");
					
					puts("");

					pprinterinfo5++;
				}
			}
			break;
		}
	}

	return ret;
}


DWORD DoRasAdminGetUserAccountServer(const WCHAR *RemoteName)
{
	DWORD ret;
	WCHAR namebuff[UNCLEN + 1];

	printf("RasAdminGetUserAccountServer():\n");

	ret = RasAdminGetUserAccountServer(NULL, RemoteName, namebuff);
	if (ret != ERROR_SUCCESS)
	{
		printf("Error %d getting ras user account server: %s", ret, StrError(ret) );
	} else {
		printf("%S\n", namebuff);
	}

	return ret;
}

DWORD DoRasAdminServerGetInfo(const WCHAR *RemoteName)
{
	DWORD ret;
	RAS_SERVER_0 rasserver0;
	

	printf("RasAdminServerGetInfo():\n");

	ret = RasAdminServerGetInfo(RemoteName, &rasserver0);
	if (ret != ERROR_SUCCESS)
	{
		printf("Error %d getting ras server info: %s", ret, StrError(ret) );
	} else {
		printf("Ports (Available/In use) %su/%su  Version: ", rasserver0.TotalPorts, rasserver0.PortsInUse);

		switch(rasserver0.RasVersion)
		{
		case RASDOWNLEVEL:
			puts("Lanman 1.0 compatible");
			break;
		case RASADMIN_35:
			puts("NT 3.5x");
			break;
		case RASADMIN_CURRENT:
			puts("NT 4 or higher");
			break;
		default:
			printf("Unknown: 0x%08x\n", rasserver0.RasVersion);
			break;
		}
	}
	return ret;
}

typedef RAS_PORT_0 *LPRAS_PORT_0 ;

DWORD DoRasAdminPortEnum(const WCHAR *RemoteName)
{
	DWORD ret;
	WORD w, structs;
	LPVOID ptb;
	

	printf("RasAdminPortEnum():\n");

	ret = RasAdminPortEnum(RemoteName, (LPRAS_PORT_0 *)&ptb, &structs);
	if (ret != ERROR_SUCCESS || ptb == NULL)
	{
		printf("Error %d enumerating RAS ports: %s", ret, StrError(ret) );
	} else {
		LPRAS_PORT_0 prasport0= (LPRAS_PORT_0)ptb;

		for (w = 0; w < structs; w++)
		{
			printf("%S  %S  %S  %S\n", prasport0->wszPortName, prasport0->wszDeviceType, prasport0->wszDeviceName, prasport0->wszMediaName   );

			printf(" Flags: ");

			if (prasport0->Flags & GATEWAY_ACTIVE)
				printf("GATEWAY_ACTIVE ");

			if (prasport0->Flags & MESSENGER_PRESENT)
				printf("MESSENGER_PRESENT ");

			if (prasport0->Flags & PORT_MULTILINKED)
				printf("PORT_MULTILINKED ");

			if (prasport0->Flags & PPP_CLIENT)
				printf("PPP_CLIENT ");

			if (prasport0->Flags & REMOTE_LISTEN)
				printf("REMOTE_LISTEN ");

			if (prasport0->Flags & USER_AUTHENTICATED)
				printf("USER_AUTHENTICATED ");

			puts("");

			if (wcslen(prasport0->wszUserName ))
				printf(" User logged in as: \\\\%S\\%S Domain:%S\n", prasport0->wszComputer, prasport0->wszUserName, prasport0->wszLogonDomain );

			if (prasport0->fAdvancedServer)
				printf(" Advanced Server\n");

			prasport0++;
		}

		RasAdminFreeBuffer(ptb);
	}

	return ret;
}



DWORD DoRegConnectRegistry(char *RemoteName, HKEY Root)
{
	LONG l;
	HKEY basekey;

	printf("RegConnectRegistry(");

	switch ((DWORD)Root)
	{
	case HKEY_LOCAL_MACHINE:
		printf("HKEY_LOCAL_MACHINE");
		break;
	case HKEY_USERS:
		printf("HKEY_USERS");
		break;
	case HKEY_PERFORMANCE_DATA:
		printf("HKEY_PERFORMANCE_DATA");
		break;
	case HKEY_DYN_DATA:
		printf("HKEY_DYN_DATA");
		break;
	case HKEY_CURRENT_CONFIG:
		printf("HKEY_CURRENT_CONFIG");
		break;
	default:
		printf("UNKNOWN?");
		break;
	}
	printf("):\n");


	l = RegConnectRegistry(RemoteName, Root, &basekey);

	if (l != ERROR_SUCCESS)
	{
		printf("Error %d connecting to remote registry: %s", l, StrError(l) );
	} else {
		puts("Connected");
		RegCloseKey(basekey);
	}

	return l;
}


DWORD DoNetGetDCName(LPWSTR RemoteName)
{
	NET_API_STATUS netapistatus;
	LPBYTE ptb;

	printf("NetGetDCName():\n");

	netapistatus = NetGetDCName(RemoteName, NULL, &ptb);

	if (netapistatus != NERR_Success || ptb == NULL)
	{
		printf("Error %d getting PDC name: %s", netapistatus, StrError(netapistatus) );
	} else {
		printf("%S\n", ptb);

		NetApiBufferFree(ptb);
	}

	return netapistatus;
}


void SignalProc(int Reason)
{
	puts("Ctrl-C detected");

	raise(SIGTERM);

	exit(0);
}

void Usage()
{
	puts("Usage: NetE [Options] \\\\MachinenameOrIP" );
	puts(" Options: ");
	puts(" /0 - All NULL session operations");
	puts(" /A - All operations");
	puts(" /B - Get PDC name");
	puts(" /C - Connections");
	puts(" /D - Date and time");
	puts(" /E - Exports");
	puts(" /F - Files");
	puts(" /G - Groups");
	puts(" /I - Statistics");
	puts(" /J - Scheduled jobs");
	puts(" /K - Disks");
	puts(" /L - Local groups");
	puts(" /M - Machines");
	puts(" /N - Message names");
	puts(" /Q - Platform specific info");
	puts(" /P - Printer ports and info");
	puts(" /R - Replicated directories");
	puts(" /S - Sessions");
	puts(" /T - Transports");
	puts(" /U - Users");
	puts(" /V - Services");
	puts(" /W - RAS ports");
	puts(" /X - Uses");
	puts(" /Y - Remote registry trees");
	puts(" /Z - Trusted domains");
	puts("Connect to a machine with NULL session privs with:");
	puts(" net use /user: \\\\MachineOrIP \"\"");

}

int main(int argc, char* argv[])
{
	DWORD ret;
	int x;
	char *RemoteName = NULL;
	USHORT wRemoteName[64];;
	DWORD NetServerGetInfoLevels[8] = {102, 101, 100, -1};
	DWORD NetServerGetInfoNTLevels[8] = {503, 502, -1};
	DWORD NetServerGetInfo9xLevels[8] = {403, 402, -1};
	DWORD NetTransportEnumLevels[8] = {2, 1, 0, -1};
	DWORD NetShareEnumLevels[8] = {2, 1, 0, -1};
	DWORD NetShareEnumNTLevels[8] = {502, 501, -1};
	DWORD NetSessionEnumLevels[8] = {2, 1, 10, 0, -1};
	DWORD NetSessionEnumNTLevels[8] = {502, -1};
	DWORD NetServerEnumLevels[8] = {102, 101, 100, -1};
	DWORD NetUserEnumLevels[8] = {20, 11, 3, 2, 1, 0, -1 };
	DWORD NetLocalGroupEnumLevels[8] = {1, 0, -1};
	DWORD NetGroupEnumLevels[8] = {2, 1, 0, -1};
	DWORD NetFileEnumLevels[8] = {3, 2, -1 };
	DWORD NetMessageNameEnumLevels[8] = {1, 0, -1};
	DWORD NetReplExportDirEnumLevels[8] = {2, 1, 0, -1};
	DWORD NetReplImportDirEnumLevels[8] = {1, 0, -1};
	DWORD NetUseEnumLevels[8] = {2, 1, 0, -1};
	DWORD NetServiceEnumLevels[8] = {2, 1, 0, -1};
	DWORD EnumPortsLevels[8] = {2, 1, -1};
	DWORD EnumMonitors[8] = {2, 1, -1};
	DWORD EnumPrintersLevels[8] = {5, 2, 1, -1};
	DWORD EnumPrinterDriverLevels[8] = {3, 2, 1, -1};
	BOOL bConnections = FALSE;
	BOOL bTOD = FALSE;
	BOOL bShares = FALSE;
	BOOL bFiles = FALSE;
	BOOL bGroups = FALSE;
	BOOL bStatistics = FALSE;
	BOOL bJobs = FALSE;
	BOOL bLocalGroups = FALSE;
	BOOL bMachines = FALSE;
	BOOL bNames = FALSE;
	BOOL bPlatformInfo = FALSE;
	BOOL bReplications = FALSE;
	BOOL bSessions = FALSE;
	BOOL bTransports = FALSE;
	BOOL bUsers = FALSE;
	BOOL bServices = FALSE;
	BOOL bUses = FALSE;
	BOOL bTrustedDomains = FALSE;
	BOOL bDisks = FALSE;
	BOOL bPrinters = FALSE;
	BOOL bRASPorts = FALSE;
	BOOL bReg = FALSE;
	BOOL bPDC = FALSE;


	printf("NetE v.98  Questions, comments, bitches and bugs to sirdystic@cultdeadcow.com\n\n", argv[0]);

	if (argc < 2 )
	{
		Usage();
		return 0;
	}

	for (x = 1; x < argc; x++)
	{
		if (argv[x][0] == '/')
		{
			switch (toupper(argv[x][1]))
			{
			case '0':
				g_bNULL = TRUE;
				break;
			case 'A':
				g_bAll = TRUE;
				break;
			case 'B':
				bPDC = TRUE;
				break;
			case 'C':
				bConnections = TRUE;
				break;
			case 'D':
				bTOD = TRUE;
				break;
			case 'E':
				bShares = TRUE;
				break;
			case 'F':
				bFiles = TRUE;
				break;
			case 'G':
				bGroups = TRUE;
				break;
			case 'I':
				bStatistics = TRUE;
				break;
			case 'J':
				bJobs = TRUE;
				break;
			case 'K':
				bDisks = TRUE;
				break;
			case 'L':
				bLocalGroups = TRUE;
				break;
			case 'M':
				bMachines = TRUE;
				break;
			case 'N':
				bNames = TRUE;
				break;
			case 'P':
				bPrinters = TRUE;
				break;
			case 'Q':
				bPlatformInfo = TRUE;
				break;
			case 'R':
				bReplications = TRUE;
				break;
			case 'S':
				bSessions = TRUE;
				break;
			case 'T':
				bTransports = TRUE;
				break;
			case 'U':
				bUsers = TRUE;
				break;
			case 'V':
				bServices = TRUE;
				break;
			case 'W':
				bRASPorts = TRUE;
				break;
			case 'X':
				bUses = TRUE;
				break;
			case 'Y':
				bReg = TRUE;
				break;
			case 'Z':
				bTrustedDomains = TRUE;
				break;
			default:
				printf("Unknown option: %s\n", argv[x] );
				Usage();
				return 0;
				break;
			}
		} else {
			if (RemoteName == NULL && argv[x][0] == '\\' && argv[x][1] == '\\')
				RemoteName = argv[x];
			else
			{
				printf("Invalid argument: %s\n", argv[x] );
				Usage();
				return 0;
			}
		}
	}

	if (RemoteName == NULL)
	{
		Usage();
		return 0;
	}

	signal(SIGINT, SignalProc);

	// convert username to unicode
	MultiByteToWideChar(CP_ACP, 0, RemoteName, -1, wRemoteName, sizeof(wRemoteName) );


	DoNetRemoteComputerSupports(wRemoteName );

	puts("");
	
	x = 0;
	do
	{
		ret = DoNetServerGetInfo(wRemoteName, NetServerGetInfoLevels[x]);
		x++;
	} while (ret != NERR_Success && NetServerGetInfoLevels[x] != -1 );

	puts("");

	if (g_bAll || bPlatformInfo)
	{
		if (g_PlatformID == PLATFORM_ID_NT || g_PlatformID == 0)
		{
			x = 0;
			do
			{
				ret = DoNetServerGetInfo(wRemoteName, NetServerGetInfoNTLevels[x]);
				x++;
			} while (ret != NERR_Success && NetServerGetInfoNTLevels[x] != -1 );
		}

		puts("");

		if (g_PlatformID == PLATFORM_ID_OS2 || g_PlatformID == 0)
		{
			x = 0;
			do
			{
				ret = DoNetServerGetInfo(wRemoteName, NetServerGetInfo9xLevels[x]);
				x++;
			} while (ret != NERR_Success && NetServerGetInfo9xLevels[x] != -1 );
		}

		puts("");
	}

	if (g_bAll || g_bNULL || bTOD)
	{
		DoNetRemoteTOD(wRemoteName);
		puts("");
	}

	if (g_bAll || g_bNULL || bTrustedDomains)
	{
		DoNetEnumerateTrustedDomains(wRemoteName);
		puts("");
	}


	if (g_bAll || g_bNULL || bTransports)
	{
		x = 0;
		do
		{
			ret = DoNetTransportEnum(wRemoteName, NetTransportEnumLevels[x]);
			x++;
		} while (ret != NERR_Success && NetTransportEnumLevels[x] != -1 );

		puts("");
	}


	if (g_bAll || bDisks)
	{
		ret = DoNetServerDiskEnum(wRemoteName, 0);

		puts("");
	}


	if (g_bAll || bShares )
	{
		if (g_PlatformID == PLATFORM_ID_NT || g_PlatformID == 0)
		{
			x = 0;
			do
			{
				ret = DoNetShareEnum(wRemoteName, NetShareEnumNTLevels[x]);
				x++;
			} while (ret != NERR_Success && NetShareEnumNTLevels[x] != -1 );
		}
		puts("");
	}

	if (g_bAll || g_bNULL || bShares )
	{
		x = 0;
		do
		{
			ret = DoNetShareEnum(wRemoteName, NetShareEnumLevels[x]);
			x++;
		} while (ret != NERR_Success && NetShareEnumLevels[x] != -1 );

		puts("");
	}


	if (g_bAll || bSessions)
	{
		if (g_PlatformID == PLATFORM_ID_NT || g_PlatformID == 0)
		{
			x = 0;
			do
			{
				ret = DoNetSessionEnum(wRemoteName, NetSessionEnumNTLevels[x]);
				x++;
			} while (ret != NERR_Success && NetSessionEnumNTLevels[x] != -1 );
			puts("");
		}
	}

	if (g_bAll || g_bNULL || bSessions)
	{
		x = 0;
		do
		{
			ret = DoNetSessionEnum(wRemoteName, NetSessionEnumLevels[x]);
			x++;
		} while (ret != NERR_Success && NetSessionEnumLevels[x] != -1 );
		puts("");
	}



	if (g_bAll || g_bNULL || bMachines)
	{
		x = 0;
		do
		{
			ret = DoNetServerEnum(wRemoteName, NetServerEnumLevels[x]);
			x++;
		} while (ret != NERR_Success && NetServerEnumLevels[x] != -1 );

		puts("");
	}

	if (g_bAll || g_bNULL || bUsers)
	{
		x = 0;
		do
		{
			ret = DoNetUserEnum(wRemoteName, NetUserEnumLevels[x]);
			x++;
		} while ((ret != NERR_Success || NetUserEnumLevels[x] > 2 ) && NetUserEnumLevels[x] != -1 );

		puts("");
	}


	if (g_bAll || g_bNULL || bLocalGroups)
	{
		x = 0;
		do
		{
			ret = DoNetLocalGroupEnum(wRemoteName, NetLocalGroupEnumLevels[x]);
			x++;
		} while (ret != NERR_Success && NetLocalGroupEnumLevels[x] != -1 );
		
		puts("");
	}


	if (g_bAll || g_bNULL || bGroups)
	{
		x = 0;
		do
		{
			ret = DoNetGroupEnum(wRemoteName, NetGroupEnumLevels[x]);
			x++;
		} while (ret != NERR_Success && NetGroupEnumLevels[x] != -1 );

		puts("");
	}


	if (g_bAll || bFiles )
	{
		x = 0;
		do
		{
			ret = DoNetFileEnum(wRemoteName, NetFileEnumLevels[x]);
			x++;
		} while (ret != NERR_Success && NetFileEnumLevels[x] != -1 );

		puts("");
	}

	if (g_bAll || bNames )
	{
		x = 0;
		do
		{
			ret = DoNetMessageNameEnum(wRemoteName, NetMessageNameEnumLevels[x]);
			x++;
		} while (ret != NERR_Success && NetMessageNameEnumLevels[x] != -1 );

		puts("");
	}

	if (g_bAll || bReplications )
	{
		x = 0;
		do
		{
			ret = DoNetReplExportDirEnum(wRemoteName, NetReplExportDirEnumLevels[x]);
			x++;
		} while ( ret != NERR_Success && NetReplExportDirEnumLevels[x] != -1 );

		puts("");

		x = 0;
		do
		{
			ret = DoNetReplImportDirEnum(wRemoteName, NetReplImportDirEnumLevels[x]);
			x++;
		} while ( ret != NERR_Success && NetReplImportDirEnumLevels[x] != -1 );

		puts("");
	}


	if (g_bAll || bJobs)
	{
		ret = DoNetScheduleJobEnum(wRemoteName);
		puts("");
	}

	if (g_bAll || bServices)
	{
		DoServiceEnum(RemoteName );

		puts("");

		x = 0;
		do
		{
			ret = DoNetServiceEnum(wRemoteName, NetServiceEnumLevels[x]);
			x++;
		} while (ret != NERR_Success && NetServiceEnumLevels[x] != -1 );

		puts("");

	}


	if (g_bAll || bUses)
	{
		x = 0;
		do
		{
			ret = DoNetUseEnum(wRemoteName, NetUseEnumLevels[x]);
			x++;
		} while (ret != NERR_Success && NetUseEnumLevels[x] != -1 );

		puts("");
	}


	if (g_bAll || bStatistics)
	{
		DoNetStatisticsGet(wRemoteName, L"SERVER", 0 );
		puts("");
		DoNetStatisticsGet(wRemoteName, L"WORKSTATION", 0 );
		puts("");
	}

	if (g_bAll || g_bNULL || bPrinters)
	{
		BOOL b;


		x = 0;
		do
		{
			b = DoEnumPrinters(RemoteName, EnumPrintersLevels[x]);
			x++;
		} while (/*b == 0 &&*/ EnumPrintersLevels[x] != -1);

		puts("");

		x = 0;
		do
		{
			b = DoEnumPorts(RemoteName, EnumPortsLevels[x]);
			x++;
		} while (b == 0 && EnumPortsLevels[x] != -1);

		puts("");

		x = 0;
		do
		{
			b = DoEnumMonitors(RemoteName, EnumPortsLevels[x]);
			x++;
		} while (b == 0 && EnumPortsLevels[x] != -1);

		puts("");

		x = 0;
		do
		{
			b = DoEnumPrinterDrivers(RemoteName, EnumPrinterDriverLevels[x]);
			x++;
		} while (b == 0 && EnumPrinterDriverLevels[x] != -1);
		
		puts("");
	}

	if (g_bNULL || g_bAll || bRASPorts )
	{
		DoRasAdminGetUserAccountServer(wRemoteName);

		puts("");
	}
	

	if (g_bAll || bRASPorts )
	{
		if (DoRasAdminServerGetInfo(wRemoteName) == ERROR_SUCCESS)
			DoRasAdminPortEnum(wRemoteName);

		puts("");
	}

	if (g_bNULL || bPDC || g_bAll)
	{
		DoNetGetDCName(wRemoteName);
		
		puts("");
	}

	if (g_bAll || bReg)
	{
		DoRegConnectRegistry(RemoteName, HKEY_LOCAL_MACHINE);
		DoRegConnectRegistry(RemoteName, HKEY_USERS);

		if (g_PlatformID == PLATFORM_ID_NT || g_PlatformID == 0)
			DoRegConnectRegistry(RemoteName, HKEY_PERFORMANCE_DATA);

		if (g_PlatformID == PLATFORM_ID_OS2 || g_PlatformID == 0)
		{
			DoRegConnectRegistry(RemoteName, HKEY_DYN_DATA);
			DoRegConnectRegistry(RemoteName, HKEY_CURRENT_CONFIG);
		}

		puts("");
	}

	return 0;
}
