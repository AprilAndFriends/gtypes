AC_INIT(libgtypes, 1.2, ivan@vucica.net)
AC_CONFIG_SRCDIR(src/Rectangle.cpp)

PACKAGE=libgtypes
VERSION=1.2.0



GTYPES_RELEASE=1:2:0
GTYPES_LIBRARY_VERSION=0:0:0
#                     | | |
#              +------+ | +---+
#              |        |     |
#            current:revision:age
#              |        |     |
#              |        |     +- increment if interfaces have been added
#              |        |        set to zero if interfaces have been removed
#              |        |        or changed
#              |        +- increment if source code has changed
#              |           set to zero if current is incremented
#              +- increment if interfaces have been added, removed or changed



#AM_INIT_AUTOMAKE($PACKAGE, $VERSION)
AM_INIT_AUTOMAKE([foreign])

AC_PROG_CC
AC_PROG_CXX
AC_PROG_RANLIB

AC_OUTPUT(Makefile src/Makefile include/gtypes/Makefile)

