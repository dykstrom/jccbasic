# jccbasic

The JCC Basic standard library - a part of [JCC](https://github.com/dykstrom/jcc).


## Using

The standard library is not usable on its own. It is distributed with JCC as
jccbasic.dll.


## Building

To build the JCC Basic standard library, you need the 64-bit version of MinGW, 
as well as some tools that are not normally part of Windows.


### mingw-w64

The 64-bit version of MinGW can be downloaded from their home page:
[mingw-w64](https://mingw-w64.org).


### make

GNU make for Windows can be downloaded from the
[GnuWin32](http://gnuwin32.sourceforge.net/packages/make.htm) project.


### mkdir and rm

The makefile uses the *nix tools mkdir and rm. These can also be downloaded
from the [GnuWin32](http://gnuwin32.sourceforge.net/packages/coreutils.htm)
project as part of the CoreUtils package.

An alternative is to install bash, for example as part of [Git](https://git-scm.com).
