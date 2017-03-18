/* rpcdump.c - Dump rpc data to console */
/* written by Sir Dystic (sd@cultdeadcow.com) */
/* copyright 1999 Cult of the Dead Cow */

/* must be linked with rpcrt4.lib (or appropriate rpc lib) */

#include &lt;windows.h&gt;
#include &lt;rpc.h&gt;
#include &lt;stdio.h&gt;
#include &lt;string.h&gt;


#define MAXAUTHNAMES 26
char *g_authn_names[MAXAUTHNAMES] = { "Default", "None", "Connect", "Call", "Packet", "Packet integrity", "Packet privacy", "7", "8", "GSS Negotiate", "WinNT", "11", "12", "13", "GSS SChannel", "15", "GSS Keberos", "MSN", "DPA", "19", "20, 21, 22, 23, 24, 25"};
        

void Usage()
{
        puts("rpcdump [options] commands");
        puts("commands: STAT - Get stats  AUTH - Authenticate IAUTH - Inquire auth info ");
        puts("   STOP - Stop server listening  NAME - Get principle name  VECS - Get vectors");
        puts("   ENUM - Enumerate endpoints");
        puts("options: [-p protocol] [-u UUID] [-n netadr] [-e endpoint] [-o options]");
        puts("         [-s user] [-a password] [-d domain] [-i server principal name]");
        puts("         [-v auth service] [-l auth level] (used with AUTH)");
//        puts("         [-j object UUID]");
        puts("Valid protocols and their endpoints are:");
        puts("ncacn_nb_tcp*  - Connection-oriented NetBIOS over TCP     - 0-255");
        puts("ncacn_nb_ipx*  - Connection-oriented NetBIOS over IPX     - 0-255");
        puts("ncacn_nb_nb    - Connection-oriented NetBIOS over NetBEUI - 0-255");
        puts("ncacn_ip_tcp   - Connection-oriented TCP/IP (default)     - Port#");
        puts("ncacn_np@      - Connection-oriented named pipes          - \\\\pipe\\pipename");
        puts("ncacn_spx      - Connection-oriented SPX                  - 1-65535");
        puts("ncacn_vns_spp* - Vines SPP transport                      - Port# 250-511");
        puts("ncadg_ip_udp*@ - Datagram (connectionless) UDP/IP         - Port#");
        puts("ncadg_ipx*@    - Datagram (connectionless) IPX            - 1-65535");
        puts("ncalrpc@       - Local procedure call                     - App/Service name");
        puts("  (* May only be available under NT)");
        puts("  (@ The 'Security' option is available, but only under NT)");
        puts("The netadr for different protocols is specified as:");
        puts("For _nb_ protocols - Windows machine name           - myserver");
        puts("For _ip_ protocols - IP address or host name        - 12.34.56.78  hostname");
        puts("For _np protocol   - NT server name (\\\\ optional)   - myhost  \\\\somehost");
        puts("For _spx/_ipx prot - IPX inet adr or NT server name - ~0000000108002B30612C");
        puts("For _vns_ protocol - StreetTalk name item@group@org - print@docs@cdc");
        puts("For ncalrpc        - Machine name                   - mymachine");
        puts("The Security option is specified in the form:");
        puts("Security=id type bool");
        puts("Values for id:");
        puts("Anonymous      - The client is anonymous to the server");
        puts("Identification - The server has information about client but cannot impersonate");
        puts("Impersonation  - The server is the client on the client’s behalf");
        puts("Values for type:");
        puts("Dynamic - A pointer to the security token is maintained.");
        puts("Static  - Security settings associated with the endpoint represent a copy ");
        puts("         of the security information at the time the endpoint was created.");
        puts("         The settings do not change. ");
        puts("Values for bool:");
        puts("True  - Effective = TRUE; only Windows NT security settings set to ON are");
        puts("        included in the token. ");
        puts("False - Effective = FALSE; all Windows NT security settings, including those");
        puts("        set to OFF, are included in the token.");
        

}


int main(int argc, char **argv)
{
        char *a_protocol = "ncacn_ip_tcp";
        char *a_UUID = NULL;
        char *a_netadr = NULL;
        char *a_endpoint = NULL;
        char *a_options = NULL;
        char *a_user = "";
        char *a_domain = "";
        char *a_password = "";
        char *a_objuuid = NULL;
        char *a_authservice = "10";
        char *a_authlevel = "0";
        char *a_princname = NULL;
        

        UUID uuid;
        RPC_EP_INQ_HANDLE context;
        RPC_IF_ID id;
        RPC_BINDING_HANDLE handle, handle2;
        RPC_STATUS st;
        RPC_IF_ID_VECTOR *vector;
        RPC_AUTH_IDENTITY_HANDLE auth_id_handle;
        RPC_STATS_VECTOR *statsvector;
        SEC_WINNT_AUTH_IDENTITY authid;

        unsigned long l, l2, l3;
        
        int trystoplistening = 0;
        int trystats = 0;
        int tryprincname = 0;
        int tryvecs = 0;
        int tryinqauth = 0;
        int tryauth = 0;
        
        int x, y;
        int enumep = 0;
        
        unsigned char * ptr;
        unsigned char * ptr2;
        unsigned char *binding;
        unsigned char buff[1024];

        puts("rpcdump v0.92 - Questions, comments, bitches, and bugs to sd@cultdeadcow.com");

        for (x = 1; x &lt; argc; x++)
        {
                if (argv[x][0] == '-' || argv[x][0] == '/')
                {
                    switch (tolower(argv[x][1]))
                    {
                        case '?':
                                Usage();
                                return 0;
                        break;
                        case 'p':
                                if (argv[x][2] == 0)
                                {
                                        x++;
                                        a_protocol = argv[x];
                                } else {
                                        a_protocol = &amp;argv[x][2];
                                }
                        break;
                        case 'u':
                                if (argv[x][2] == 0)
                                {
                                    x++;
                                    a_UUID = argv[x];
                                } else {
                                    a_UUID = &amp;argv[x][2];
                                }
                        break;
                        case 'n':
                                if (argv[x][2] == 0)
                                {
                                    x++;
                                    a_netadr = argv[x];
                                } else {
                                    a_netadr = &amp;argv[x][2];
                                }
                        break;
                        case 'e':
                                if (argv[x][2] == 0)
                                {
                                    x++;
                                    a_endpoint = argv[x];
                                } else {
                                    a_endpoint = &amp;argv[x][2];
                                }
                        break;
                        case 'o':
                                if (argv[x][2] == 0)
                                {
                                    x++;
                                    a_options = argv[x];
                                } else {
                                    a_options = &amp;argv[x][2];
                                }
                        break;
                        case 's':
                                if (argv[x][2] == 0)
                                {
                                    x++;
                                    a_user = argv[x];
                                } else {
                                        a_user = &amp;argv[x][2];
                                }
                        break;
                        case 'a':
                                if (argv[x][2] == 0)
                                {
                                        x++;
                                        a_password = argv[x];
                                } else {
                                        a_password = &amp;argv[x][2];
                                }
                        break;                                
                        case 'd':
                                if (argv[x][2] == 0)
                                {
                                        x++;
                                        a_domain = argv[x];
                                } else {
                                        a_domain = &amp;argv[x][2];
                                }
                        break;
                        case 'j':
                                if (argv[x][2] == 0)
                                {
                                        x++;
                                        a_objuuid = argv[x];
                                } else {
                                        a_objuuid = &amp;argv[x][2];
                                }
                        break;
                        case 'v':
                                if (argv[x][2] == 0)
                                {
                                        x++;
                                        a_authservice = argv[x];
                                } else {
                                        a_authservice = &amp;argv[x][2];
                                }
                        break;
                        case 'i':
                                if (argv[x][2] == 0)
                                {
                                        x++;
                                        a_princname = argv[x];
                                } else {
                                        a_princname = &amp;argv[x][2];
                                }
                        break;
                        case 'l':
                                if (argv[x][2] == 0)
                                {
                                        x++;
                                        a_authlevel = argv[x];
                                } else {
                                        a_authlevel = &amp;argv[x][2];
                                }
                        break;
                        
                        case 0:
                                puts("Bad option '-' (Use -? for help)");
                        break;
                        default:
                                printf("Unknown option: '%c' (Use -? for help)\n", argv[x][1]);
                        break;
                    }
                } else {
                        if (stricmp(argv[x], "STOP") == 0)
                        {
                                trystoplistening = 1;
                        } else if (stricmp(argv[x], "IAUTH") == 0) {
                                tryinqauth = 1;
                        } else if (stricmp(argv[x], "AUTH") == 0) {
                                tryauth = 1;
                        } else if (stricmp(argv[x], "NAME") == 0) {
                                tryprincname = 1;
                        } else if (stricmp(argv[x], "STAT") == 0) {
                                trystats = 1;
                        } else if (stricmp(argv[x], "VECS") == 0) {
                                tryvecs = 1;
                        } else if (stricmp(argv[x], "ENUM") == 0) {
                                enumep = 1;
                        } else {
                                printf("Unknown command: '%s' (Use -? for help)\n", argv[x]);
                        }
                }
        }

        
       
        st = RpcStringBindingCompose(a_UUID, a_protocol, a_netadr, a_endpoint, a_options, &amp;binding);

        if (st != RPC_S_OK)
        {
            DceErrorInqText(st, buff);
            printf("Unable to compose binding string: Error %d:%s", st, buff);
            return 0;
        }

        puts(binding);
        
        st = RpcBindingFromStringBinding(binding, &amp;handle);

        if (st != RPC_S_OK)
        {
                DceErrorInqText(st, buff);
                printf("Unable to create binding handle: %d:%s", st, buff);
                RpcStringFree(&amp;binding);
        
                return 0;
        }

        if (enumep)
        {
                l = RPC_C_EP_ALL_ELTS;

                if (a_objuuid != NULL)
                {
                        st = UuidFromString(a_objuuid, &amp;uuid);
                        if (st != RPC_S_OK)
                        {
                                DceErrorInqText(st, buff);
                                printf("Unable to convert '%s' to uuid: %d:%s", a_objuuid, st, buff);
                        } else {
                                l = RPC_C_EP_MATCH_BY_OBJ;
                        }
                }
                
                st = RpcMgmtEpEltInqBegin( handle, l, NULL, 0, &amp;uuid, &amp;context); 
                if (st != RPC_S_OK)
                {
                    DceErrorInqText(st, buff);
                    switch (st)
                    {
                        case EPT_S_NOT_REGISTERED:
                                puts("Server reports no endpoints");
                        break;
                        case RPC_S_SERVER_UNAVAILABLE:
                                puts("RPC server unavailable for the interface specified");
                        default:
                            printf("RpcMgmtEpEltInqIfIds() failed with %d:%s", st, buff);
                        break;
                    }
                } else {
                        puts("Inquiring first endpoint...");
                        while ( RpcMgmtEpEltInqNext(context, &amp;id, &amp;handle2, &amp;uuid, &amp;ptr) == RPC_S_OK)
                        {
        
                                puts("");               
                                UuidToString(&amp;id.Uuid, &amp;ptr2);
                                printf("ID:  %s version %u.%u\n", ptr2, id.VersMajor, id.VersMinor);
                                RpcStringFree(&amp;ptr2);
                                
 //                               printf("Binding handle: 0x%08x\n", handle2);
                                RpcBindingToStringBinding(handle2, &amp;ptr2);
                                printf("Binding string: %s\n", ptr2);
                                RpcStringFree(&amp;ptr2);

                                if (!UuidIsNil(&amp;uuid, &amp;st))
                                {
                                        UuidToString(&amp;uuid, &amp;ptr2);
                                        printf("UUID:           %s\n", ptr2);
                                        RpcStringFree(&amp;ptr2);
                                }
                                
                                if (ptr != NULL &amp;&amp; strlen(ptr))
                                        printf("Annotation:     %s\n", ptr);


                                if (tryvecs)
                                {
                                        puts("Retrieving vectors...");
                                        st = RpcMgmtInqIfIds(handle2, &amp;vector);
                                        if (st != RPC_S_OK)
                                        {
                                            DceErrorInqText(st, buff);
                                            switch (st)
                                            {
                                                case EPT_S_NOT_REGISTERED:
                                                        puts("Server reports no endpoints");
                                                break;
                                                case RPC_S_SERVER_UNAVAILABLE:
                                                        puts("RPC server unavailable for the interface specified");
                                                default:
                                                    printf("RpcMgmtInqIfIds() failed with %d:%s", st, buff);
                                                break;
                                            }
                                        } else {
                                            l = vector-&gt;Count;
                                            printf("Number of vectors:  %ld\n", l);
                                            for (l2 = 0; l2 &lt; l; l2++) {
                                                UuidToString(&amp;vector-&gt;IfId[l2]-&gt;Uuid, &amp;ptr2);
                                                printf("%ld - UUID:  %s Version %u.%u\n", l2+1, ptr2, vector-&gt;IfId[l2]-&gt;VersMajor, vector-&gt;IfId[l2]-&gt;VersMinor);
                                                RpcStringFree(&amp;ptr2);
                                            }
                                            RpcIfIdVectorFree(&amp;vector);
                                        }
                                }


                                if (handle2 != NULL)
                                        RpcBindingFree(&amp;handle2);
                                if (ptr != NULL)
                                        RpcStringFree(&amp;ptr);
                
                        }
                        RpcMgmtEpEltInqDone( &amp;context);
                }

        } else {

                st = RpcMgmtIsServerListening(handle);

                if (st != RPC_S_OK)
                {
                        DceErrorInqText(st, buff);
                        printf("Error %d:%s", st, buff);
                        RpcStringFree(&amp;binding);
                        RpcBindingFree(&amp;handle);
                        return 0;
                }

                puts("Server is listening.");
                
                if (tryauth)
                {
                        x = atoi(a_authservice);
                        y = atoi(a_authlevel);

                        if (x &gt;= MAXAUTHNAMES &amp;&amp; x != 100)
                        {
                                printf("Invalid auth level: %d  Setting to WinNT\n", x);
                                x = 10;
                        }

                        printf("Setting authentication for type ");
                        if (x != 100)
                                 puts(g_authn_names[x]);
                        else
                                puts("Setting authentication for type MQ");
                                
                        ptr = NULL;
                        switch (x)
                        {
        
                                case 10:
                                        authid.User = a_user;
                                        authid.Domain = a_domain;
                                        authid.Password = a_password;
                                        authid.UserLength = strlen(authid.User);
                                        authid.DomainLength = strlen(authid.Domain);
                                        authid.PasswordLength = strlen(authid.Password);
                                        authid.Flags = 1;   /* ANSI */
                                        ptr = (void *)&amp;authid;
                                break;
                        }

                        printf("Attempting to set auth info with user:'%s' domain:'%s' pass:'%s'\n", a_user, a_domain, a_password);
                        st = RpcBindingSetAuthInfo(handle, a_princname, y, x, (RPC_AUTH_IDENTITY_HANDLE)ptr, x);
                        if (st != RPC_S_OK)
                        {
                                DceErrorInqText(st, buff);
                                printf("RpcBindingSetAuthInfo() failed with %d:%s", st, buff);
                        } else {
                                puts("Binding authentication info set");
                        }                                
                }

                if (trystats)
                {
                        puts("Retrieving stats...");
                        st = RpcMgmtInqStats(handle, &amp;statsvector);
                        if (st != RPC_S_OK)
                        {
                                printf("RpcMgmtInqStats() returned %d\n", st);
                        } else {
                                printf("Server statistics:  Calls: In: %lu  Out: %lu   Packets: In: %lu  Out: %lu\n", statsvector-&gt;Stats[RPC_C_STATS_CALLS_IN], statsvector-&gt;Stats[RPC_C_STATS_CALLS_OUT], statsvector-&gt;Stats[RPC_C_STATS_PKTS_IN], statsvector-&gt;Stats[RPC_C_STATS_PKTS_OUT]);
                                RpcMgmtStatsVectorFree(&amp;statsvector);
                        }
                }
                                
                if (tryprincname)
                {
                        puts("Inquiring principle server name for auth types 0 to 25 and 100...");
                        for (x = 0; x &lt; MAXAUTHNAMES ; x++)
                        {
                                                        
                                st = RpcMgmtInqServerPrincName(handle, x, &amp;ptr2);
                                if (st != RPC_S_OK)
                                {
                                        if (st != RPC_S_UNKNOWN_AUTHN_SERVICE)
                                        {
                                                DceErrorInqText(st, buff);
                                                printf("RpcMgmtInqServerPrincName(%d) returned %d:%s", x, st, buff);
                                        }
                                } else {
                                        printf("Server's principal name for auth type %s: '%s'\n", g_authn_names[x], ptr2);
                                        if (ptr2 != NULL)
                                                RpcStringFree(&amp;ptr2);
                                }
                        }
                        st = RpcMgmtInqServerPrincName(handle, 100, &amp;ptr2);
                        if (st != RPC_S_OK)
                        {
                                if (st != RPC_S_UNKNOWN_AUTHN_SERVICE)
                                {
                                        DceErrorInqText(st, buff);
                                        printf("RpcMgmtInqServerPrincName(100) returned %d:%s",  st, buff);
                                }
                        } else {
                                printf("Server's principal name for auth type MQ: '%s'\n", ptr2);
                                if (ptr2 != NULL)
                                        RpcStringFree(&amp;ptr2);
                        }
                        
                }
                                
                if (tryinqauth)
                {

                        st = RpcBindingInqAuthInfo(handle, &amp;ptr2, &amp;l, &amp;l2, &amp;auth_id_handle, &amp;l3);
                        if (st != RPC_S_OK)
                        {
                                DceErrorInqText(st, buff);
                                printf("RpcBindingInqAuthInfo() failed with %d:%s", st, buff);
                        } else {
                                printf("Authentication Info:\nPrinciple server: '%s'\nAuth Level:     ", ptr2);
                        
                                switch(l)
                                {
                                        case RPC_C_AUTHN_LEVEL_DEFAULT:
                                                puts("Default level");
                                        break;
                                        case RPC_C_AUTHN_LEVEL_NONE:
                                                puts("No authentication");
                                        break;
                                        case RPC_C_AUTHN_LEVEL_CONNECT:
                                                puts("Only when the client establishes a relationship with the server");
                                        break;
                                        case RPC_C_AUTHN_LEVEL_CALL:
                                                puts("Only at beginning of each rpc call. Does not apply to ncacn protocols.");
                                        break;
                                        case RPC_C_AUTHN_LEVEL_PKT:
                                                puts("Authenticates that all data received is from the expected client.");
                                        break;
                                        case RPC_C_AUTHN_LEVEL_PKT_INTEGRITY:
                                                puts("Authenticates and verifies that none of the data transferred between client and server has been modified.");
                                        break;
                                        case RPC_C_AUTHN_LEVEL_PKT_PRIVACY:
                                                puts("Authenticates all previous levels and encrypts the argument value of each remote procedure call. ");
                                        break;
                                        default:
                                                printf("Unknown auth level:  %d\n", l);
                                        break;
                                }

                                printf("Auth service:   ");
                                switch (l2)
                                {
                                        case RPC_C_AUTHN_DCE_PRIVATE: /* 1  */
                                                puts("DCE private key authentication");
                                        break;
                                        case RPC_C_AUTHN_DCE_PUBLIC: /* 2 */
                                                puts("DCE public key authentication (reserved for future use)");
                                        break;
                                        case RPC_C_AUTHN_DEC_PUBLIC: /* 4 */
                                                puts("DEC public key authentication (reserved for future use)");
                                        break;
                                        case RPC_C_AUTHN_DEFAULT: /* 0xfffffff */
                                                puts("Default authentication service");
                                        break;
                                        case RPC_C_AUTHN_NONE: /* 0 */
                                                puts("No authentication");
                                        break;
                                        case RPC_C_AUTHN_WINNT: /* 10 */
                                                puts("NTLMSSP (NT LAN Manager Security Support Provider)");
                                        break;
                                        default:
                                                printf("Unknown auth service: %d\n", l2);
                                        break;
                                }
                        
                                printf("Auth requested: ");
                                switch (l3)
                                {
                                        case RPC_C_AUTHN_DCE_PRIVATE: /* 1  */
                                                puts("DCE private key authentication");
                                        break;
                                        case RPC_C_AUTHN_DCE_PUBLIC: /* 2 */
                                                puts("DCE public key authentication (reserved for future use)");
                                        break;
                                        case RPC_C_AUTHN_DEC_PUBLIC: /* 4 */
                                                puts("DEC public key authentication (reserved for future use)");
                                        break;
                                        case RPC_C_AUTHN_DEFAULT: /* 0xfffffff */
                                                puts("Default authentication service");
                                        break;
                                        case RPC_C_AUTHN_NONE: /* 0 */
                                                puts("No authentication");
                                        break;
                                        case RPC_C_AUTHN_WINNT: /* 10 */
                                                puts("NTLMSSP (NT LAN Manager Security Support Provider)");
                                        break;
                                        default:
                                                printf("Unknown auth service: %d\n", l3);
                                        break;
                                }
                                                        
                                RpcStringFree(&amp;ptr2);
                        }
                }                                                
#if 0
                st = RpcBindingInqAuthClient( 0, NULL, &amp;ptr, &amp;l, &amp;l2, &amp;l3);
                if (st != RPC_S_OK)
                {
                        DceErrorInqText(st, buff);
                        printf("RpcBindingInqAuthClient() failed with %d:%s", st, buff);
                } else {
                        puts("Authentication info:");
                        printf("Principle server name:  %s\n", ptr);
                        printf("Authentication level:   %d\n", l);
                        printf("Authentication service: %d\n", l2);
                        printf("Authorization service:  %d\n", l3);

                        RpcStringFree(&amp;ptr);
                }
#endif

#if 0
//                st = RpcBindingInqAuthInfo( handle, &amp;ptr, &amp;l, &amp;l2, (RPC_AUTH_IDENTITY_HANDLE *)&amp;authid, &amp;l3);
                st = RpcBindingInqAuthInfo( handle, &amp;ptr, &amp;l, &amp;l2, NULL, &amp;l3);
                if (st != RPC_S_OK)
                {
                        DceErrorInqText(st, buff);
                        printf("RpcBindingInqAuthInfoEx() failed with %d:%s", st, buff);
                } else {
                        puts("Authentication info:");
                        printf("Principle server name:  %s\n", ptr);
                        printf("Authentication level:   %d\n", l);
                        printf("Authentication service: %d\n", l2);
                        printf("Authorization service:  %d\n", l3);

                        RpcStringFree(&amp;ptr);
                }
#endif                                

                if (tryvecs)
                {
                        puts("Retrieving vectors...");
                        st = RpcMgmtInqIfIds(handle, &amp;vector);
                        if (st != RPC_S_OK)
                        {
                                DceErrorInqText(st, buff);
                            switch (st)
                            {
                                case EPT_S_NOT_REGISTERED:
                                        puts("Server reports no endpoints");
                                break;
                                case RPC_S_SERVER_UNAVAILABLE:
                                        puts("RPC server unavailable for the interface specified");
                                default:
                                        printf("RpcMgmtInqIfIds() failed with %d:%s", st, buff);
                                break;
                            }
                        } else {
                                l = vector-&gt;Count;
                                printf("Number of vectors:  %ld\n", l);
                                for (l2 = 0; l2 &lt; l; l2++)
                                {
                                        UuidToString(&amp;vector-&gt;IfId[l2]-&gt;Uuid, &amp;ptr2);
                                        printf("%ld - UUID:  %s Version %u.%u\n", l2+1, ptr2, vector-&gt;IfId[l2]-&gt;VersMajor, vector-&gt;IfId[l2]-&gt;VersMinor);
                                        RpcStringFree(&amp;ptr2);
                                }
                                RpcIfIdVectorFree(&amp;vector);
                        }
                }

                                
                if ( trystoplistening )
                {
                        puts("Attempting to stop server listening...");
                        st = RpcMgmtStopServerListening(handle);
                        if (st != RPC_S_OK)
                        {
                                DceErrorInqText(st, buff);
                                printf("RpcMgmtStopServerListening() failed with %d:%s", st, buff);
                        } else {
                                puts("Server stopped.");
                        }
                }       


        }
                

        RpcStringFree(&amp;binding);
        
        RpcBindingFree(&amp;handle);

        puts("All done.");       

        return 0;
}
