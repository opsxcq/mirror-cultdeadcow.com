/* peloader.c - PE exe loader for pecrunch */
/* Copyright 1999  Sir Dystic of the Cult of the Dead Cow */
/* sd@cultdeadcow.com  http://www.cultdeadcow.com/~sd     */


#include <windows.h>
#include "lzh.h"




void *g_readptr;
void *g_writeptr;
int g_dataleft;

int lzh_read(void *data, int n)
{
        if (g_dataleft)
                memcpy(data, g_readptr, n);
        if (g_dataleft < n)
                n = g_dataleft;                
        g_dataleft -= n;
        (int)g_readptr += n;
        return n;
}

int lzh_write(void *data, int n)
{
        memcpy(g_writeptr, data, n);
        (int)g_writeptr += n;
        return n;
}

void *lzh_malloc(unsigned n)
{
        return (void *)LocalAlloc(LMEM_FIXED, n);
}

void lzh_free(void *data)
{
        LocalFree((HLOCAL)data);
}

void __cdecl wstart_()
{
        PIMAGE_DOS_HEADER pdosheader;
        PIMAGE_NT_HEADERS pntheaders;
        PIMAGE_SECTION_HEADER psectionheader;
        PIMAGE_IMPORT_DESCRIPTOR pimportdescriptor;
        PIMAGE_THUNK_DATA pthunkdatain, pthunkdataout;
        PIMAGE_BASE_RELOCATION pbaserelocation;
        PIMAGE_IMPORT_BY_NAME pimportbyname;
        int x;
        PVOID pvd;
        DWORD dw, entrypoint;
        HANDLE handle;
        PCHAR ptr;
        PWORD pw;
        PDWORD pdw;
        char buff[128];
        HINSTANCE hInstance = GetModuleHandle(NULL);
        char exepath[MAX_PATH];
        char *exename;

        // get exe filename in exepath and point to last char in string
        exename = exepath + GetModuleFileName(NULL, exepath, MAX_PATH) - 1;

        // find last backslash
        while (*exename != '\\') exename--;

        exename++;

        // decompress appropriate sections
        pdosheader = (PIMAGE_DOS_HEADER)hInstance;
        pntheaders = (PIMAGE_NT_HEADERS)((DWORD)hInstance + pdosheader->e_lfanew);
        psectionheader = (PIMAGE_SECTION_HEADER)(pntheaders + 1);
        
        for (x = 0; x < pntheaders->FileHeader.NumberOfSections - 4; x++)
        {
                if (psectionheader->Misc.VirtualSize != 0)
                {
                        pvd = VirtualAlloc(NULL, psectionheader->SizeOfRawData, MEM_COMMIT, PAGE_READWRITE);
                        memcpy(pvd, (PVOID)((DWORD)hInstance + psectionheader->VirtualAddress), psectionheader->SizeOfRawData);
                        // decompress the data
                        g_readptr = pvd;
                        g_writeptr = (PVOID)((DWORD)hInstance + psectionheader->VirtualAddress);
                        g_dataleft = psectionheader->SizeOfRawData;
                        VirtualProtect(g_writeptr, psectionheader->Misc.VirtualSize, PAGE_EXECUTE_READWRITE, &dw);
                        lzh_melt(lzh_read, lzh_write, lzh_malloc, lzh_free, psectionheader->Misc.VirtualSize);
                        VirtualFree(pvd, 0, MEM_RELEASE);
                }
                psectionheader++;
        }
        // do imports

        pimportdescriptor = (PIMAGE_IMPORT_DESCRIPTOR)((DWORD)hInstance + pntheaders->OptionalHeader.DataDirectory[15].VirtualAddress);

        while ( pimportdescriptor->TimeDateStamp != 0 ||pimportdescriptor->Name != 0)
        {
                ptr = (PCHAR)((DWORD)hInstance+ pimportdescriptor->Name);
                handle = GetModuleHandle(ptr);
                if (handle == NULL)
                        handle = LoadLibrary(ptr);
                if (handle == NULL)
                {
                        wsprintf(buff, "A required .DLL file, %hs, was not found.", ptr);
                        MessageBox(HWND_DESKTOP, buff, "Error Starting Program", MB_OK|MB_ICONEXCLAMATION);
                        ExitProcess(0);
                }
                        if (pimportdescriptor->TimeDateStamp != -1)
                        {
                                pimportdescriptor->ForwarderChain  = (DWORD)handle;
                                pimportdescriptor->TimeDateStamp = 0xCDC31337;

                                pthunkdataout = (PIMAGE_THUNK_DATA)((DWORD)hInstance + (DWORD)pimportdescriptor->FirstThunk);
                                if (pimportdescriptor->Characteristics == 0)
                                        pthunkdatain = pthunkdataout;
                                else 
                                        pthunkdatain = (PIMAGE_THUNK_DATA)((DWORD)hInstance + (DWORD)pimportdescriptor->Characteristics);

                                while ( pthunkdatain->u1.AddressOfData != NULL)
                                {
                                        if ((DWORD)pthunkdatain->u1.Ordinal & IMAGE_ORDINAL_FLAG) // no name, just ordinal
                                        {
                                                dw = (DWORD)GetProcAddress(handle, MAKEINTRESOURCE(LOWORD(pthunkdatain->u1.Ordinal)));
                                        } else {
                                                pimportbyname = (PIMAGE_IMPORT_BY_NAME)((DWORD)pthunkdatain->u1.AddressOfData + (DWORD)hInstance);
                                                dw = (DWORD)GetProcAddress(handle, pimportbyname->Name);
                                        }
                                        if (dw == 0)
                                        {
                                                if ((DWORD)pthunkdatain->u1.AddressOfData & IMAGE_ORDINAL_FLAG)
                                                {
                                                        wsprintf(buff, "The %hs file is \nlinked to missing export %hs:0x%04x.", exename, ptr, LOWORD(pthunkdatain->u1.AddressOfData));
                                                } else {
                                                        wsprintf(buff, "The %hs file is \nlinked to missing export %hs:%hs.", exename, ptr, pimportbyname->Name);
                                                }
                                                MessageBox(HWND_DESKTOP, buff, "Error Starting Program", MB_OK|MB_ICONEXCLAMATION);
                                                ExitProcess(0);
                                      
                                        }

                                        pthunkdataout->u1.Function = (PDWORD)dw;
        
                                        pthunkdatain++;
                                        pthunkdataout++;
                                }
               
                        } else { // -1 = new style bound import
                                dw = 0;
                                wsprintf(buff, "New style bound import: %hs", ptr);
                                MessageBox(HWND_DESKTOP, buff, "Error:", MB_OK );

                        }
                        pimportdescriptor++;                
                }
                
        // do fixups

        if ((DWORD)hInstance != pntheaders->OptionalHeader.ImageBase && pntheaders->OptionalHeader.DataDirectory[15].Size)
        {
                pbaserelocation = (PIMAGE_BASE_RELOCATION)((DWORD)hInstance + pntheaders->OptionalHeader.DataDirectory[15].Size);
                while (pbaserelocation->VirtualAddress != 0)
                {
                        pw = (PWORD)((DWORD)pbaserelocation + sizeof(IMAGE_BASE_RELOCATION));
                        for (x = 0; x < (pbaserelocation->SizeOfBlock-sizeof(IMAGE_BASE_RELOCATION))/2; x++)
                        {
                                pdw = (PDWORD)(pbaserelocation->VirtualAddress + (DWORD)hInstance + (*pw & 0xFFF));
                                switch(*pw >> 12)
                                {
                                        case IMAGE_REL_BASED_ABSOLUTE:
                                        break;
                                        case IMAGE_REL_BASED_HIGHLOW:
                                                dw = *pdw;
                                                dw = dw - pntheaders->OptionalHeader.ImageBase + (DWORD)hInstance;
                                                if (dw < (DWORD)hInstance || dw > (DWORD)hInstance + pntheaders->OptionalHeader.SizeOfImage)
                                                {
                                                        wsprintf(buff, "*pdw = 0x%08x", *pdw);
                                                        MessageBox(HWND_DESKTOP, buff, "Bad pointer:", MB_OK );
                                                } else {
                                                        *pdw = dw;
                                                }
                                        break;
                                        default:
                                        case IMAGE_REL_BASED_HIGH:
                                        case IMAGE_REL_BASED_LOW:
                                                wsprintf(buff, "*pw = 0x%04x  *pdw = 0x%08x", *pw, *pdw);
                                                MessageBox(HWND_DESKTOP, buff, "Unexpected relocation type:", MB_OK);
                                        break;
                                }

                                pw++;
                        }
                
                        pbaserelocation = (PIMAGE_BASE_RELOCATION)((DWORD)pbaserelocation + pbaserelocation->SizeOfBlock);
                }
                
        }
        
        entrypoint = ((DWORD)hInstance + pntheaders->OptionalHeader.DataDirectory[14].Size);

        _asm jmp [entrypoint];

}