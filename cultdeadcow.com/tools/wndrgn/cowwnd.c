/* cowwnd.c - cow window */
/* Copyright 1999 Sir Dystic and Cult of the Dead Cow */
/* Questions, comments, bitches and bugs to sd@cultdeadcow.com */

/* this exe does NOT use a standard WinMain entrypoint or the clib */
/* to compile and link this program, you must link it with ONLY:  */
/* kernel32.lib,user32.lib,gdi32.lib */
/* You must define 'inline intrinsic functions' and you must define */
/* the program entry symbol as WinEntry */


#define WIN32_LEAN_AND_MEAN

#include <windows.h>


#define APPTITLE "Cow Window"
#define SPLASHCLASSNAME "CowSplashClass"


HBRUSH g_splashbrush = NULL;
HINSTANCE g_hInstance = NULL;



LRESULT CALLBACK SplashWndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
        static int s_wndxsize;
        static int s_wndysize;
        static int s_lastmousexpos = 0;
        static int s_lastmouseypos = 0;
        LRESULT retval = 0;
        HRGN rgn, rgn2, rgn3;
        RECT rect;
        DWORD dw;
        
        switch (uMsg)
        {
                case WM_LBUTTONDBLCLK:
                        PostQuitMessage(0);
                break;
                case WM_MOUSEMOVE:
                        if ( (wParam & MK_RBUTTON ) /*|| (wParam & MK_LBUTTON) */)
                        {
                                GetWindowRect(hWnd, &rect);
                                MoveWindow(hWnd, rect.left + LOWORD(lParam) - s_lastmousexpos, rect.top + HIWORD(lParam) - s_lastmouseypos , rect.right-rect.left, rect.bottom-rect.top, TRUE);
                        } else {
                                s_lastmousexpos = LOWORD(lParam);
                                s_lastmouseypos = HIWORD(lParam);
                        }
                break;
                case WM_SIZE:
                        s_wndxsize = LOWORD(lParam) ;
                        s_wndysize = HIWORD(lParam) ;
                        // empty region to be overwritten
                        rgn = CreateRectRgn(1, 1, 2, 2);
                        // top region to be the horns
                        rgn2 = CreateEllipticRgn(0, s_wndysize/10, s_wndxsize, s_wndysize/3);
                        // region to be carved out of top of horns
                        rgn3 = CreateEllipticRgn(0, 0, s_wndxsize, s_wndysize/4);

                        CombineRgn(rgn, rgn2, rgn3, RGN_DIFF);
        
                        DeleteObject(rgn3);
                        // left eye area
                        rgn3 = CreateEllipticRgn(s_wndxsize/4, (s_wndysize*90)/400, s_wndxsize/2, (s_wndysize*30)/40);

                        CombineRgn(rgn2, rgn, rgn3, RGN_OR);
                        
                        DeleteObject(rgn);
                        // right eye area
                        rgn = CreateEllipticRgn(s_wndxsize/2, (s_wndysize*90)/400, (s_wndxsize*30)/40, (s_wndysize*30)/40);

                        CombineRgn(rgn3, rgn, rgn2, RGN_OR);

                        DeleteObject(rgn);
                        // mouth and jaw area
                        rgn = CreateEllipticRgn((s_wndxsize*20)/50, s_wndysize/4, (s_wndxsize*30)/50, s_wndysize);

                        CombineRgn(rgn2, rgn, rgn3, RGN_OR);
                        
                        DeleteObject(rgn);
                        // piece to carve out left cheek
                        rgn = CreateEllipticRgn(0, s_wndysize/3, s_wndxsize/3, s_wndysize);

                        CombineRgn(rgn3, rgn2, rgn,  RGN_DIFF);
                        
                        DeleteObject(rgn);
                        // piece to carve out of right cheek
                        rgn = CreateEllipticRgn((s_wndxsize*20)/30, s_wndysize/3, s_wndxsize, s_wndysize);

                        CombineRgn(rgn2, rgn3, rgn, RGN_DIFF);
                        
                        DeleteObject(rgn);
                        // piece carved out of bottom left cheek
                        rgn = CreateEllipticRgn(s_wndxsize/4, (s_wndysize*80)/130, (s_wndxsize*20)/50, s_wndysize);

                        CombineRgn(rgn3, rgn2, rgn, RGN_DIFF);
                        
                        DeleteObject(rgn);
                        // piece carved out of bottom right cheek
                        rgn = CreateEllipticRgn((s_wndxsize*30)/50, (s_wndysize*80)/130, (s_wndxsize*30)/40, s_wndysize);

                        CombineRgn(rgn2, rgn3, rgn, RGN_DIFF);
                        
                        DeleteObject(rgn);
                        // notch out of bottom of mouth
                        rgn = CreateEllipticRgn((s_wndxsize*20)/50, (s_wndysize*170)/180, (s_wndxsize*30)/50, s_wndysize*2);

                        CombineRgn(rgn3, rgn2, rgn, RGN_DIFF);

                        DeleteObject(rgn);
                        
                        dw = GetSystemMetrics(SM_CXVSCROLL);
                        // square for size button
                        rgn = CreateRectRgn(s_wndxsize , s_wndysize , s_wndxsize+dw, s_wndysize+dw);

                        CombineRgn(rgn2, rgn3, rgn, RGN_OR);
        
                        DeleteObject(rgn);
                        DeleteObject(rgn3);
                        SetWindowRgn(hWnd, rgn2, TRUE);
                break;
                default:
                        retval =     DefWindowProc(hWnd, uMsg, wParam, lParam);
                break;
        }


        return retval;
}

void __cdecl WinEntry()
{
        HICON icon;
        HCURSOR cursor, splashcursor;
        char buff[1024];
        LOGBRUSH brushinfo;
        DWORD dw;
        WNDCLASS class;
        MSG msg;
        int x, y;
        HWND hWnd;


        g_hInstance = GetModuleHandle(NULL);

        icon = LoadIcon(g_hInstance, "cDcIcon");
        if (icon == NULL)
                icon = LoadIcon(NULL, IDI_APPLICATION);
        if (icon == NULL)
        {
                dw = GetLastError();
                wsprintf(buff, "Error %d loading icon", dw);
                MessageBox(HWND_DESKTOP, buff, APPTITLE, MB_OK);
                icon = LoadIcon(NULL, IDI_EXCLAMATION);
        }
        cursor = LoadCursor(NULL, IDC_ARROW);

        splashcursor = LoadCursor(g_hInstance, "CowCursor");
        if (splashcursor == NULL)
                splashcursor = LoadCursor(NULL, IDC_ARROW);
//        brushinfo.lbStyle = BS_HATCHED;
        brushinfo.lbStyle = BS_SOLID;
        brushinfo.lbColor = RGB(180, 90, 90);
        brushinfo.lbHatch = HS_BDIAGONAL;
        g_splashbrush = CreateBrushIndirect(&brushinfo);

        class.style = CS_NOCLOSE|CS_DBLCLKS;
        class.lpfnWndProc = SplashWndProc;
        class.cbClsExtra = 0;
        class.cbWndExtra = 0;
        class.hInstance = g_hInstance;
        class.hIcon = icon;
        class.hCursor = splashcursor;
        class.hbrBackground = g_splashbrush;
        class.lpszMenuName = NULL;
        class.lpszClassName = SPLASHCLASSNAME;

        RegisterClass(&class);

        x = GetSystemMetrics(SM_CXSCREEN);
        y = GetSystemMetrics(SM_CYSCREEN);
        hWnd = CreateWindowEx(WS_EX_TOPMOST, SPLASHCLASSNAME, NULL, WS_VISIBLE|WS_POPUP|WS_BORDER|WS_THICKFRAME, x/4, y/6, x/2, (y*2)/3, NULL, NULL, g_hInstance, (LPVOID)NULL);


        do
        {
                x = GetMessage(&msg, NULL, 0, 0);
                if (x == -1)
                        ExitProcess(0);
                if (x == 0)
                {
                        ExitProcess(msg.wParam);
                }
                if (TranslateMessage(&msg) == 0)
                        DispatchMessage(&msg);
        } while (TRUE);

}