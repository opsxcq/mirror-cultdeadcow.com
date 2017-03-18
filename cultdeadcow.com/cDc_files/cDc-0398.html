<html><body bgcolor="#000000" text="#00FF00"><title>cDc paramedia: texXxt #398</title><pre>
                                    _
                                   | \
                                   |  \
                                   | | \
                            __     | |\ \             __
      _____________       _/_/     | | \ \          _/_/     _____________
     |  ___________     _/_/       | |  \ \       _/_/       ___________  |
     | |              _/_/_____    | |   > >    _/_/_____               | |
     | |             /________/    | |  / /    /________/               | |
     | |                           | | / /                              | |
     | |                           | |/ /                               | |
     | |                           | | /                                | |
     | |                           |  /                                 | |
     | |                           |_/                                  | |
     | |                                                                | |
     | |      c   o   m   m   u   n   i   c   a   t   i   o   n   s     | |
     | |________________________________________________________________| |
     |____________________________________________________________________|

     ...presents...   How to Create Very Small Win32 Executables
                                                        by Sir Dystic

           __//////\   -cDc- CULT OF THE DEAD COW -cDc-   /\\\\\\__
                    __      Grand Imperial Dynasty      __
 Est. 1984   \\\\\\/ cDc paramedia: texXxt 398-10/14/2004 \//////   Est. 1984

  ___    _   _    ___     _   _    ___       _   _      ___    _   _      __
 |___heal_the_sick___raise_the_dead___cleanse_the_lepers___cast_out_demons__|

       The key to creating minimal sized executables is in reducing the 
overhead in the executable by not linking data into the executable that isn't 
needed.  Obviously, not using MFC or other such libraries will reduce the 
executable size considerably, but your code will be smallest and most 
efficient if you start from a completely empty executable and add only what 
is needed.

       Create an empty win32 exe application project and add an empty .c 
source file to it.  First, define the macro 'WIN32_LEAN_AND_MEAN' and 
include windows.h:

#define WIN32_LEAN_AND_MEAN 
#include "windows.h"

       Defining that macro before including windows.h causes only commonly
used parts of the Windows API to be included. It usually doesn't make the 
final executable any smaller, but it speeds the compiling time.  Create a 
function called something like EntryPoint that accepts no parameters and 
returns none:

void __cdecl EntryPoint(void) { }

       We will use this function later in place of the usual WinMain 
entrypoint function.  Just leave it empty for now. 

       In the linker settings for your executable, remove all of the
libraries that are automatically imported by your development environment.  
Next, find the setting to ignore all default libraries and enable it.  The 
main library we're trying to avoid including is the clib, the "standard c 
library."  The clib library is a set of functions which are implemented 
across platforms to make the porting of code from one platform to another 
possible.  However, the functions in this library are actually just wrappers
around Win32 APIs.  Some compilers even come with the source for these 
functions, so if you want to see how a "standard" function is implemented 
you can see what Win32 APIs the function is actually wrapped around.  This 
will be key later.

       By not including the clib, you reduce the overhead in your executable
to almost nothing, but there are a few things that are handled by the clib
that you will now have to handle yourself.  The first of these is the 
entrypoint.  In Win32, the standard entrypoint for a c program is a function 
called WinMain, but this function is not called by the operating system.  
When the linker builds a "standard" executable with a clib and everything, 
it points the actual executable entrypoint to a function in the clib 
usually called the startup code, which initializes everything necessary for 
the clib functions to work and then calls the WinMain function that the coder
implemented.  The source for the startup code is included with compilers more
 often than the clib source.  Since we have not linked in the clib and don't 
have the startup code, you must specify a new entrypoint for the executable.  
This will be the EntryPoint function you put in the source file before, so 
find the linker option for the executable entry point and put the function 
name in there.  You may also have to add an underscore before or after the 
function name, as most compilers add this to the function names you create.

       At this point, you should be able to compile and link your executable
without any problems.  It may crash if you try to run it at this point, but 
if you compile and link release executable, it should give you an idea of the
minimum size of the executable.  There may be other ways to make this size
even smaller, like setting your compiler options to optimize for size instead
of speed.  You may get linker errors if the compiler you are using generates
calls to functions in the clib.  These might include such things as "stack
depth checking," code inserted before every function call to insure that the
stack is large enough to handle it, and grows the stack if necessary.  Find
the appropriate compiler options to disable these calls (such as "disable
stack depth checking") and enable them.  Be sure also to not include ANY
debugging information.  Some compilers still include line number info in
"release" mode executables.  A nother major issue in the size of executables
is the file alignment.  The sections in an executable file always start on
the alignment boundary.  The minimum size for the file alignment is 0x200 
bytes, and many linkers default to this value, but some like MSVC default to
0x1000, the minimum alignment for sections in memory.  There is usually a 
linker switch (/LINK:512 in msvc) to change the file alignment.  By reducing
this value from 0x1000 to 0x200, we reduce the minimum size for an
executable with three sections to 2k instead of 16k.  Also, "incremental 
linking" speeds up linking by creating buffer areas in the code so that it
can insert new code without having to move everything around if only minor
changes have been made, but this dramatically increases the size of the 
code section.  And if your linker supports elimination of "dead code," by 
all means enable it.  Other useful options are obvious things like 
"eliminate duplicate strings."

       By using the /MERGE linker option, you can combine sections to reduce
the overhead even more.  For instance, you can merge the relocation data, the
import section or the export section into the data section. 

       There are other things that the clib does that we might want to use, 
and many of these can be handled using a compiler option called "inline 
intrinsic functions."  Intrinsic functions are functions that are considered 
important and small enough that you can replace calls to the clib with the 
actual function contents inline.  Which clib functions are considered
intrinsic varies between compilers, but they usually include such functions
as:  malloc, memcmp, memcpy, abs, div, and even some string manipulation 
functions like strcmp, strcpy and strlen.  If your program needs to use 
floating point calls, these can also usually be generated inline.

       Okay, so you have a running executable, but what about all that stuff
that got passed to WinMain?  Only three of the four parameters are even
useful, and there are simple API calls to get the values that would normally
be passed to WinMain.  In fact, the startup code in the clib actually just 
calls these APIs and passes their return values to your WinMain.  The 
hInstance parameter is the same value that will be returned by a call to
GetModuleHandle(NULL).  The lpCmdLine can be retrieved using GetCommandLine
and the nCmdShow value can be gotten from the wShowWindow value in the 
STARTUPINFO struct filled in by the GetStartupInfo API.  As far the exe 
returning an integer value, that would normally be returned by your WinMain
function, just pass your return value to ExitProcess when you're ready to end
the process.

       Of course, once you add a call to an API, you start getting errors
linking your exe because it can't find the APIs you're calling. For every 
Win32 API you want to use, you will have to link in the appropriate lib.  The
APIs to get the WinMain parameters are in kernel32.lib, and lots of useful 
APIs like MessageBox and other UI APIs are in user32.lib.  As far as using 
the clib functions which you are no longer including in the executable, keep
in mind that the clib functions are just wrappers around the Win32 API.  Most
clib functions have a one-to-one API equivalent, it's just a matter of 
figuring out the API name, which is what I spend most of my time doing when
programming Win32, just trying to figure out what idiotic name the API I want
to use was given.  Even functions like sprintf have direct Win32 API 
equivalents, wsprintf in this case. If you really can't figure it out, see if
your compiler comes with the clib source and try to figure out what APIs that
calls by looking at the source for the clib function.  Worst case scenario,
you might have to implement your own version of the clib function, but since
your implementation will be less general, it can also be more effecient.

       And that's it, that's about as small an executable as I've figured
out how to make.  For more complex applications where these methods might 
not be appropriate, be sure to see my page on pe wrappers and compressors
(http://www.cultdeadcow.com/tools/pecrunch.html).  Using these methods with
the Watcom 11 compiller or MSVC6, I can create a 1536 byte executable.  You
could probably reduce the minimum exe size by another 512 bytes if the DOS
stub you used fit under 512 bytes with the IMAGE_DOS_HEADER (58 bytes,
aligned to 64), the IMAGE_NT_HEADERS (244 bytes), and the size of however
many sections the executable has, IMAGE_SECTION_HEADERS (40 bytes each).  
The DOS stub used with MSVC 6 is sadly 126 bytes or so, just a couple bytes
too big to fit, and the Watcom 11 DOS stub is around 70 bytes, but both of
these stubs output text strings to the user to tell them that it is not a
DOS exe. The stub could simply exit.  You can use a stub other than the
default using the /STUB linker option, but as far as creating tiny DOS 
EXEs, see the docs from 1984.  The program doesn't do anything, but code 
doesn't actually take up much space.  Since most executables that actually
do something will have at least a code section, a data section, an imports
section and probably at least one other section (like a relocations section
or a constants section), a reasonable minimum executable size is really
around 2.5 k, unless you can merge sections.  Obviously, look at the 
compiler and linker options available to you and use your head, don't 
enable anything like "Runtime Type Information" or debug options which will 
obviously generate extra code, and use generally established good
programming practices.

    .-.                             _   _                             .-.
   /   \           .-.             ((___))             .-.           /   \
  /.ooM \         /   \       .-.  [ x x ]  .-.       /   \         /.ooM \
-/-------\-------/-----\-----/---\--\   /--/---\-----/-----\-------/-------\-
/ fun4us  \     /       \   /     `-(' ')-'     \   /       \     / nofun4u \
           \   /         `-'         (U)         `-'         \   /
            `-'              the original e-zine              `-'    _
      Oooo                   - today, tomorrow -                    / )   __
 /)(\ (   \                        FOREVER                         /  (  /  \
 \__/  )  /  Copyright (c) 2004 cDc communications and the author. \   ) \)(/
       (_/     CULT OF THE DEAD COW is a registered trademark of    oooO
         cDc communications, 1369 Madison Ave. #423, NY, NY 10128, USA    _
  oooO              All rights left.  Edited by Myles Long.         __   ( \
 /   ) /)(\                                                        /  \  )  \
 \  (  \__/       Save yourself!  Go outside!  Do something!       \)(/ (   /
  \_)                     xXx   BOW to the COW   xXx                    Oooo
</pre></body></html>
