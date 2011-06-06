
# initialize autoconf
AC_INIT(libgtypes, 1.2, ivan@vucica.net)

# autoconf configuration
AC_PREREQ(2.61)
AC_CONFIG_SRCDIR(src/Rectangle.cpp)

# libtool configuration
#  LT_VERSION has nothing to do with VERSION.
#  It is used in versioning of .so (as part of .so's filename), but
#  it is unrelated to VERSION.
#
#   +1 : ? : +1  == new interface that does not break old one
#   +1 : ? : 0   == new interface that breaks old one
#    ? : ? : 0   == no new interfaces, but breaks apps
#    ? :+1 : ?   == just some internal changes, nothing breaks but might work
#                   better
#   CURRENT : REVISION : AGE
LT_VERSION=0:0:0
AC_SUBST(LT_VERSION)

# set up languages that will be used
AC_PROG_CC
AC_PROG_CXX
AC_LANG(C++)

# initialize automake
AM_INIT_AUTOMAKE([foreign])

# more libtool setup
AC_PROG_LIBTOOL # for pre-2.2 libtool
#LT_PREREQ([2.2]) # for post-2.2 libtool
#LT_INIT #([disable-shared])
AC_SUBST([LIBTOOL_DEPS])

# begin checks
# check standard c headers
AC_HEADER_STDC

# end checks; output files
AC_OUTPUT(Makefile src/Makefile include/gtypes/Makefile)

