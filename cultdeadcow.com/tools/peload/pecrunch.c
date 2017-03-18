/* pecrunch.c - compress and encrypt a PE executable      */
/* Copyright 1999  Sir Dystic of the Cult of the Dead Cow */
/* sd@cultdeadcow.com  http://www.cultdeadcow.com/~sd     */


#include <windows.h>
#include <stdio.h>

#include "lzh.h"


HANDLE g_lzhfile;
LPVOID g_secptr ;
int g_readleft;

void Usage()
{
        puts("Usage:  PECrunch  inputexe  outputexe");
}



int lzh_read(void *data, int n)
{
        DWORD dw;

        putchar('.');
        fflush(stdout);

        if (n > g_readleft)
                n = g_readleft;
                
        if (n)
                ReadFile(g_lzhfile, data, n, &dw, NULL);
        else
                return 0;

        g_readleft -= n;
        return (int)dw;
}

int lzh_write(void *data, unsigned int n)
{
        memcpy(g_secptr, data, n);
        g_secptr = (LPVOID)((unsigned int)g_secptr + n);
        return n;
}        

void *lzh_malloc(unsigned n)
{
        return malloc(n);
}

void lzh_free(void *data)
{
        free(data);
}

#define FILE_ALIGNMENT 0x200
//#define FILE_ALIGNMENT 0x1000

#define PACKSECTIONS

int main(int argc, char **argv)
{
        HANDLE infile, outfile, stubfile, outmap, stubmap;
        IMAGE_DOS_HEADER dosheader, *pdosheader;
        IMAGE_NT_HEADERS ntheaders, *pntheaders;
        PIMAGE_SECTION_HEADER psectionheader, psectionheader2;
        PIMAGE_IMPORT_DESCRIPTOR pimportdescriptor;
        PIMAGE_THUNK_DATA pthunkdata;
        PIMAGE_BASE_RELOCATION pbasereloc;
        DWORD dw;
        DWORD len;
        PDWORD pdw;
        PWORD pw;
        LPVOID lpv, stubptr, baseofcode;
        char *infilename;
        char *outfilename;
        char *ptr;
        int x;
        char zeromem[FILE_ALIGNMENT];
        long highestvirtualaddress = 0;
        long segbasedelta = 0;
        DWORD appdelta = 0;

        puts("PECrunch  v0.1 - Copyright 1999 Sir Dystic and the Cult of the Dead Cow");

        if (argc != 3)
        {
                Usage();
                return 0;
        }

        memset(zeromem, 0, FILE_ALIGNMENT);

        infilename = argv[1];
        outfilename = argv[2];

        infile = CreateFile( infilename, GENERIC_READ, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

        if (infile == INVALID_HANDLE_VALUE)
        {
                printf("Error %d opening input file %s\n", GetLastError(), infilename);
                return 0;
        }

        len = GetFileSize(infile, NULL);

        outfile = CreateFile( outfilename, GENERIC_READ|GENERIC_WRITE, 0, NULL, /*CREATE_NEW*/CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        
        if (outfile == INVALID_HANDLE_VALUE)
        {
                printf("Error %d creating output file %s\n", GetLastError(), outfilename);
                CloseHandle(infile);
                return 0;
        }

        outmap = CreateFileMapping(outfile, NULL, PAGE_READWRITE, 0, len, NULL);

        if (outmap == NULL)
        {
                printf("Error %d creating file mapping\n", GetLastError());
                CloseHandle(infile);
                CloseHandle(outfile);
                DeleteFile(outfilename);
                return 0;
        }

        lpv = MapViewOfFile(outmap, FILE_MAP_WRITE, 0, 0, 0);  // map whole file

        if (lpv == NULL)
        {
                printf("Error %d mapping view of file\n", GetLastError() );
                CloseHandle(outmap);
                CloseHandle(infile);
                CloseHandle(outfile);
                DeleteFile(outfilename);
                return 0;
        }


        stubfile = CreateFile( "peloader.exe", GENERIC_READ, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//        stubfile = CreateFile( "pecrunch.dat", GENERIC_READ, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

        if (stubfile == NULL)
        {
                puts("Unable to open pecrunch.dat");
                CloseHandle(outmap);
                CloseHandle(infile);
                CloseHandle(outfile);
                DeleteFile(outfilename);
                return 0;
        }
                
        stubmap = CreateFileMapping(stubfile, NULL, PAGE_READONLY, 0, 0, NULL);
        stubptr = MapViewOfFile(stubmap, FILE_MAP_READ, 0, 0, 0);  // map whole file


//        memset(lpv, -1, len);

        ReadFile(infile, (LPVOID)&dosheader, sizeof(dosheader), &dw, NULL);

        if (dosheader.e_magic != IMAGE_DOS_SIGNATURE || dw != sizeof(dosheader))
        {
                printf("Input file %s contains a bad MZ exe header\n", infilename);
                UnmapViewOfFile(lpv);
                CloseHandle(outmap);
                CloseHandle(infile);
                CloseHandle(outfile);
                DeleteFile(outfilename);
                return 0;
        }
                
        SetFilePointer(infile, dosheader.e_lfanew, NULL, FILE_BEGIN);

        ReadFile(infile, (LPVOID)&ntheaders, sizeof(ntheaders), &dw, NULL);

        if (ntheaders.Signature != IMAGE_NT_SIGNATURE || ntheaders.OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR_MAGIC || dw != sizeof(ntheaders) )
        {
                printf("Input file %s contains a bad NT exe header\n", infilename);
                UnmapViewOfFile(lpv);
                CloseHandle(outmap);
                CloseHandle(infile);
                CloseHandle(outfile);
                DeleteFile(outfilename);
                return 0;
        }

        // read dos header and stub
        SetFilePointer(infile, 0, NULL, FILE_BEGIN);
        ReadFile(infile, lpv, dosheader.e_lfanew, &dw, NULL);

        // read section headers
        SetFilePointer(infile, dosheader.e_lfanew+sizeof(IMAGE_NT_HEADERS), NULL, FILE_BEGIN);
        ReadFile(infile, (LPVOID)((DWORD)lpv+dosheader.e_lfanew+sizeof(IMAGE_NT_HEADERS)), (sizeof(IMAGE_SECTION_HEADER)*ntheaders.FileHeader.NumberOfSections), &dw, NULL);

//        psectionheader = (PIMAGE_SECTION_HEADER)((DWORD)lpv+dosheader.e_lfanew + ntheaders.OptionalHeader.SizeOfHeaders);
        psectionheader = (PIMAGE_SECTION_HEADER)((DWORD)lpv+dosheader.e_lfanew + sizeof(IMAGE_NT_HEADERS));
     
        g_lzhfile = infile;

        g_secptr = (LPVOID)((DWORD)psectionheader + sizeof(IMAGE_SECTION_HEADER)*(ntheaders.FileHeader.NumberOfSections+4));

        printf("Compressing %s...", infilename);        
        
        for (x = 0; x < ntheaders.FileHeader.NumberOfSections; x++)
        {
                if (psectionheader->PointerToRawData)
                {
                        // allign section in file;
                        g_secptr = (LPVOID)((DWORD)g_secptr + (FILE_ALIGNMENT - ((DWORD)g_secptr % FILE_ALIGNMENT)));

                        // move file pointer to section data
                        SetFilePointer(infile, psectionheader->PointerToRawData, NULL, FILE_BEGIN);
                        // set new file data pointer
                        psectionheader->PointerToRawData = (DWORD)g_secptr - (DWORD)lpv;

                        if (psectionheader->VirtualAddress + psectionheader->SizeOfRawData > highestvirtualaddress )
                                highestvirtualaddress = psectionheader->VirtualAddress + psectionheader->SizeOfRawData ;

                        if (    psectionheader->VirtualAddress == ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress ||
                                psectionheader->VirtualAddress == ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_RESOURCE].VirtualAddress ||
                                psectionheader->VirtualAddress == ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXCEPTION].VirtualAddress ||
                                psectionheader->VirtualAddress == ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_SECURITY].VirtualAddress ||
                                psectionheader->VirtualAddress == ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_DEBUG].VirtualAddress ||
                                psectionheader->VirtualAddress == ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_COPYRIGHT].VirtualAddress ||
                                psectionheader->VirtualAddress == ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_GLOBALPTR].VirtualAddress ||
                                psectionheader->VirtualAddress == ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_GLOBALPTR].VirtualAddress ||
                                psectionheader->VirtualAddress == ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG].VirtualAddress ||
                                psectionheader->VirtualAddress == ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT].VirtualAddress ||
                                psectionheader->VirtualAddress == ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IAT].VirtualAddress
                                )
                        {
                                psectionheader->Misc.VirtualSize = 0;
                                ReadFile(infile, g_secptr, psectionheader->SizeOfRawData, &dw, NULL);
#ifdef PACKSECTIONS
                                ptr = (char *)g_secptr + psectionheader->SizeOfRawData - 1;
                                while (*ptr == 0)
                                {
                                        ptr--;
                                        psectionheader->SizeOfRawData--;
                                }
                                psectionheader->SizeOfRawData+=4;
//                                psectionheader->Misc.VirtualSize = psectionheader->SizeOfRawData;
                                g_secptr = (LPVOID)(ptr+4);
#else
                                (DWORD)g_secptr += psectionheader->SizeOfRawData;
#endif                                
                        } else {

                                                                                      
                                // set virtual size to actual uncompressed size (used for uncompression)
                                g_readleft = psectionheader->Misc.VirtualSize = psectionheader->SizeOfRawData;
                                // set raw data size to compressed size
                                lzh_freeze(lzh_read, lzh_write, lzh_malloc, lzh_free);
                        
                                psectionheader->SizeOfRawData = ((DWORD)g_secptr - (DWORD)lpv) - psectionheader->PointerToRawData;
                        }
                }

                psectionheader++;
        }

                
      
                // align file section pointer
        g_secptr = (LPVOID)((DWORD)g_secptr + (FILE_ALIGNMENT - ((DWORD)g_secptr % FILE_ALIGNMENT)));

                // align virtual address
        highestvirtualaddress += (ntheaders.OptionalHeader.SectionAlignment - (highestvirtualaddress % ntheaders.OptionalHeader.SectionAlignment));


                // point to headers in loader exe
        pdosheader = (PIMAGE_DOS_HEADER)stubptr;
        pntheaders = (PIMAGE_NT_HEADERS)((DWORD)stubptr+pdosheader->e_lfanew);
        psectionheader2 = (PIMAGE_SECTION_HEADER)((DWORD)pntheaders + sizeof(IMAGE_NT_HEADERS));

        segbasedelta = highestvirtualaddress - psectionheader2->VirtualAddress;
        
        appdelta = ntheaders.OptionalHeader.ImageBase - pntheaders->OptionalHeader.ImageBase;


                // copy loader code segment
        memcpy(psectionheader->Name, ".load\0\0\0\0\0\0", IMAGE_SIZEOF_SHORT_NAME);
        psectionheader->Misc.VirtualSize = psectionheader2->SizeOfRawData;
        psectionheader->VirtualAddress = highestvirtualaddress;
        psectionheader->SizeOfRawData = psectionheader2->SizeOfRawData;
        psectionheader->PointerToRawData = (DWORD)g_secptr - (DWORD)lpv;
        psectionheader->PointerToRelocations = 0;
        psectionheader->PointerToLinenumbers = 0;
        psectionheader->NumberOfRelocations = 0;
        psectionheader->NumberOfLinenumbers = 0;
        psectionheader->Characteristics = psectionheader2->Characteristics;

                // copy loader code segment data
        memcpy(g_secptr, (LPVOID)((DWORD)stubptr+psectionheader2->PointerToRawData), psectionheader->SizeOfRawData);

        ntheaders.OptionalHeader.BaseOfCode = psectionheader->VirtualAddress ;
        baseofcode = g_secptr;


#ifdef PACKSECTIONS
        ptr = (char *)g_secptr + psectionheader->SizeOfRawData - 1;
        while (*ptr == 0 && psectionheader->SizeOfRawData > 0)
        {
                ptr--;
                psectionheader->SizeOfRawData--;
        }
        psectionheader->SizeOfRawData+=4;
        g_secptr = (PVOID)(ptr + 4);
#else
        (DWORD)g_secptr += psectionheader->SizeOfRawData;
#endif        

                // align file section pointer
        g_secptr = (LPVOID)((DWORD)g_secptr + (FILE_ALIGNMENT - ((DWORD)g_secptr % FILE_ALIGNMENT)));

        psectionheader++;
        psectionheader2++;


                // create data segment
        memcpy(psectionheader->Name, ".lddata\0\0\0\0\0\0", IMAGE_SIZEOF_SHORT_NAME);
        psectionheader->Misc.VirtualSize = psectionheader2->SizeOfRawData;
        psectionheader->VirtualAddress = psectionheader2->VirtualAddress + segbasedelta;
        psectionheader->SizeOfRawData = psectionheader2->SizeOfRawData;
        psectionheader->PointerToRawData = 0;
        psectionheader->PointerToRelocations = 0;
        psectionheader->PointerToLinenumbers = 0;
        psectionheader->NumberOfRelocations = 0;
        psectionheader->NumberOfLinenumbers = 0;
        psectionheader->Characteristics = psectionheader2->Characteristics;

        ntheaders.OptionalHeader.BaseOfData = psectionheader->VirtualAddress ;

        psectionheader++;
        psectionheader2++;


                // copy loader import segment
        memcpy(psectionheader->Name, ".loadid\0\0\0\0", IMAGE_SIZEOF_SHORT_NAME);
        psectionheader->Misc.VirtualSize = psectionheader2->SizeOfRawData;
        psectionheader->VirtualAddress = psectionheader2->VirtualAddress + segbasedelta;
        psectionheader->SizeOfRawData = psectionheader2->SizeOfRawData;
        psectionheader->PointerToRawData = (DWORD)g_secptr - (DWORD)lpv;
        psectionheader->PointerToRelocations = 0;
        psectionheader->PointerToLinenumbers = 0;
        psectionheader->NumberOfRelocations = 0;
        psectionheader->NumberOfLinenumbers = 0;
        psectionheader->Characteristics = psectionheader2->Characteristics;
        
                // copy loader import segment data
        memcpy(g_secptr, (LPVOID)((DWORD)stubptr+psectionheader2->PointerToRawData), psectionheader->SizeOfRawData);

                // do fixups for import segment
        pimportdescriptor = (PIMAGE_IMPORT_DESCRIPTOR)g_secptr;

        while (pimportdescriptor->OriginalFirstThunk != 0)
        {
                pimportdescriptor->Characteristics += segbasedelta;
                if (pimportdescriptor->ForwarderChain != -1 && pimportdescriptor->ForwarderChain !=0)
                        pimportdescriptor->ForwarderChain += segbasedelta;
                pimportdescriptor->Name += segbasedelta;
                if (pimportdescriptor->FirstThunk != 0)
                        (DWORD)pimportdescriptor->FirstThunk += segbasedelta;

                if (pimportdescriptor->OriginalFirstThunk != 0 && (DWORD)pimportdescriptor->OriginalFirstThunk != -1)
                {
                        pthunkdata = (PIMAGE_THUNK_DATA)((DWORD)g_secptr + (DWORD)pimportdescriptor->OriginalFirstThunk - psectionheader->VirtualAddress);
                        while (pthunkdata->u1.Ordinal != 0)
                        {
                                pthunkdata->u1.Ordinal += segbasedelta;
                                pthunkdata++;
                        }
                }

                if (pimportdescriptor->FirstThunk != 0 && (DWORD)pimportdescriptor->FirstThunk != -1)
                {
                        pthunkdata = (PIMAGE_THUNK_DATA)((DWORD)g_secptr + (DWORD)pimportdescriptor->FirstThunk - psectionheader->VirtualAddress);
                        while (pthunkdata->u1.Ordinal != 0)
                        {
                                pthunkdata->u1.Ordinal += segbasedelta;
                                pthunkdata++;
                        }
                }
                pimportdescriptor++;
        }
        
#ifdef PACKSECTIONS
        ptr = (char *)g_secptr + psectionheader->SizeOfRawData - 1;
        while (*ptr == 0 && psectionheader->SizeOfRawData > 0)
        {
                ptr--;
                psectionheader->SizeOfRawData--;
        }
        g_secptr = (PVOID)(ptr + 4);
        psectionheader->SizeOfRawData+=4;
#else
        (DWORD)g_secptr += psectionheader->SizeOfRawData;
#endif        


        ntheaders.OptionalHeader.DataDirectory[15].VirtualAddress = ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress ;
        ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress = psectionheader->VirtualAddress;
        ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size = psectionheader->SizeOfRawData;



                // align file section pointer
        g_secptr = (LPVOID)((DWORD)g_secptr + (FILE_ALIGNMENT - ((DWORD)g_secptr % FILE_ALIGNMENT)));

        psectionheader++;
        psectionheader2++;
        
                // copy loader relocations segment
        memcpy(psectionheader->Name, ".loadrl\0\0\0\0", IMAGE_SIZEOF_SHORT_NAME);
        psectionheader->Misc.VirtualSize = psectionheader2->SizeOfRawData;
        psectionheader->VirtualAddress = psectionheader2->VirtualAddress + segbasedelta;
        psectionheader->SizeOfRawData = psectionheader2->SizeOfRawData;
        psectionheader->PointerToRawData = (DWORD)g_secptr - (DWORD)lpv;
        psectionheader->PointerToRelocations = 0;
        psectionheader->PointerToLinenumbers = 0;
        psectionheader->NumberOfRelocations = 0;
        psectionheader->NumberOfLinenumbers = 0;
        psectionheader->Characteristics = psectionheader2->Characteristics;
        
                // copy loader import segment data
        memcpy(g_secptr, (LPVOID)((DWORD)stubptr+psectionheader2->PointerToRawData), psectionheader->SizeOfRawData);

                // do relocs segment fixups

        pbasereloc = (PIMAGE_BASE_RELOCATION)g_secptr;

        while (pbasereloc->VirtualAddress != 0)
        {
                pbasereloc->VirtualAddress += segbasedelta;
                        // fixup fixups (ug)
                pw = (PWORD)((DWORD)pbasereloc + sizeof(IMAGE_BASE_RELOCATION));
                for (x = 0; x < (pbasereloc->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION))/2; x++)
                {
                        if (pw[x] != 0)
                        {
                                pdw = (PDWORD)((DWORD)baseofcode + (pw[x] & 0xfff)) ;
                                *pdw += segbasedelta;
                                *pdw += appdelta;
                        }
                }
                
                pbasereloc = (PIMAGE_BASE_RELOCATION)((DWORD)pbasereloc + pbasereloc->SizeOfBlock);
        }

#ifdef PACKSECTIONS
        ptr = (char *)g_secptr + psectionheader->SizeOfRawData - 1;
        while (*ptr == 0 && psectionheader->SizeOfRawData > 0)
        {
                ptr--;
                psectionheader->SizeOfRawData--;
        }
        psectionheader->SizeOfRawData+=4;
        g_secptr = (PVOID)(ptr + 4);
#else
        (DWORD)g_secptr += psectionheader->SizeOfRawData;
#endif

        ntheaders.OptionalHeader.DataDirectory[15].Size = ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress;
        ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress = psectionheader->VirtualAddress;
        ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size = psectionheader->SizeOfRawData;

                // align file section pointer
        g_secptr = (LPVOID)((DWORD)g_secptr + (FILE_ALIGNMENT - ((DWORD)g_secptr % FILE_ALIGNMENT)));


#if 0
                // handle bound import tables
        if (ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT].VirtualAddress != 0)
        {
                ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT].VirtualAddress = 0;
                ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT].Size = 0;
        }
                // handle IATs
        if (ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IAT].VirtualAddress != 0)
        {
                ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IAT].VirtualAddress = 0;
                ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IAT].Size = 0;
        }
#endif

        ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_DEBUG].VirtualAddress = 0;
        ntheaders.OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_DEBUG].Size = 0;

        // fix the rest of the nt headers

               // 4 new segments - code, data, fixups, imports
        ntheaders.FileHeader.NumberOfSections+=4;
        
        ntheaders.FileHeader.PointerToSymbolTable = pntheaders->FileHeader.PointerToSymbolTable ;
        ntheaders.FileHeader.NumberOfSymbols = pntheaders->FileHeader.NumberOfSymbols;
                // copy exe characteristics of loader stub
        ntheaders.FileHeader.Characteristics = pntheaders->FileHeader.Characteristics;

        ntheaders.OptionalHeader.DataDirectory[14].Size = ntheaders.OptionalHeader.AddressOfEntryPoint;
                // point entry point to our new code
        ntheaders.OptionalHeader.AddressOfEntryPoint = pntheaders->OptionalHeader.AddressOfEntryPoint + segbasedelta;
                // set our new file alignment
        ntheaders.OptionalHeader.FileAlignment = FILE_ALIGNMENT;
                // copy loader section alignment
        ntheaders.OptionalHeader.SectionAlignment = pntheaders->OptionalHeader.SectionAlignment;
        ntheaders.OptionalHeader.SizeOfImage = psectionheader->VirtualAddress + psectionheader->SizeOfRawData;
                // copy linker version from loader stub
        ntheaders.OptionalHeader.MajorLinkerVersion = pntheaders->OptionalHeader.MajorLinkerVersion;
        ntheaders.OptionalHeader.MinorLinkerVersion = pntheaders->OptionalHeader.MinorLinkerVersion;
        
                // copy loader flags from our loader stub
        ntheaders.OptionalHeader.LoaderFlags = pntheaders->OptionalHeader.LoaderFlags ;

        ntheaders.OptionalHeader.SizeOfInitializedData = pntheaders->OptionalHeader.SizeOfInitializedData;
        ntheaders.OptionalHeader.SizeOfUninitializedData = pntheaders->OptionalHeader.SizeOfUninitializedData;

        ntheaders.OptionalHeader.SizeOfCode += pntheaders->OptionalHeader.SizeOfCode ;

                // 0 out checksum
        ntheaders.OptionalHeader.CheckSum = 0;

        

#if 1

        ntheaders.OptionalHeader.MajorOperatingSystemVersion = pntheaders->OptionalHeader.MajorOperatingSystemVersion;
        ntheaders.OptionalHeader.MinorOperatingSystemVersion = pntheaders->OptionalHeader.MinorOperatingSystemVersion;
        
        ntheaders.OptionalHeader.MajorImageVersion = pntheaders->OptionalHeader.MajorImageVersion;
        ntheaders.OptionalHeader.MinorImageVersion = pntheaders->OptionalHeader.MinorImageVersion;

        ntheaders.OptionalHeader.MajorSubsystemVersion = pntheaders->OptionalHeader.MajorSubsystemVersion;
        ntheaders.OptionalHeader.MinorSubsystemVersion = pntheaders->OptionalHeader.MinorSubsystemVersion;
#endif
        
                // copy nt headers to file
        memcpy((LPVOID)((DWORD)lpv + dosheader.e_lfanew), &ntheaders, sizeof(ntheaders));
//        memcpy((LPVOID)((DWORD)lpv + dosheader.e_lfanew), &ntheaders, ntheaders.OptionalHeader.SizeOfHeaders);

                                
        CloseHandle(infile);

        UnmapViewOfFile(lpv);
        CloseHandle(outmap);

        // truncate output file
        SetFilePointer(outfile, (DWORD)g_secptr  - (DWORD)lpv, NULL, FILE_BEGIN);
        SetEndOfFile(outfile);
        
        CloseHandle(outfile);

        printf("\n%s written.\n", outfilename);        

        return 0;
}