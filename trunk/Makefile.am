ACLOCAL_AMFLAGS = -I m4
SUBDIRS = src include/gtypes
EXTRA_DIST = autogen.sh

lib_LTLIBRARIES = libgtypes.la
libgtypes_la_SOURCES = 
libgtypes_la_LIBADD =  $(LIBOBJS) \
	src/libgtypes_src.la
libgtypes_la_LDFLAGS = -version-info @LT_VERSION@

