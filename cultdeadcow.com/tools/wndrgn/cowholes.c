/* cowholes.c - punch cow shaped holes in all windows on the system */
/* copyright 1999 SIr Dystic and Cult of the Dead Cow */
/* Questions, comments, bitches and bugs to sd@cultdeadcow.com */


#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define FIXDELAY 7000

BOOL g_fix = 0;

BOOL CALLBACK WindowEnumCallback(HWND hWnd, LPARAM lparam)
{
        int s_wndxsize, s_wndysize;
        HRGN rgn, rgn2, rgn3;
        RECT rect;

        if (g_fix)
        {
                SetWindowRgn(hWnd, NULL, TRUE);
                return TRUE;
        }
        
        GetWindowRect(hWnd, &rect);
        s_wndxsize = rect.right - rect.left ;
        s_wndysize = rect.bottom - rect.top ;
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

        // create rect region the size of the whole window
        DeleteObject(rgn);
        rgn = CreateRectRgn(0, 0, s_wndxsize, s_wndysize);

        CombineRgn(rgn2, rgn, rgn3, RGN_DIFF);

        DeleteObject(rgn);
        DeleteObject(rgn3);
        SetWindowRgn(hWnd, rgn2, TRUE);

        return TRUE;
}

void __cdecl EntryPoint(void)
{

        EnumWindows(WindowEnumCallback, 0);

        Sleep(FIXDELAY);

        g_fix = 1;

        EnumWindows(WindowEnumCallback, 0);

}