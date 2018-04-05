cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_VERBOSE_MAKEFILE on)

#project(gtypes)

file(
	GLOB_RECURSE CppSrc
	"../../src/*.c"
	"../../src/*.cpp"
)

#file(
#	GLOB CppSrc
#	"../../src/Quaternion.cpp"
#	"../../src/Matrix3.cpp"
#)

add_library(gtypes STATIC ${CppSrc})

include_directories(AFTER "../../include/gtypes")
include_directories(AFTER "../../src")

add_definitions(
	-DGTYPES_EXPORTS
)

find_library(liblog log)
target_link_libraries(
	gtypes
	${liblog}
)
