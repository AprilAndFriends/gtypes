cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_VERBOSE_MAKEFILE on)

project(gtypes)

include("../../../hltypes/android-studio/generic/cmake-preprocessors.txt")

file(
	GLOB_RECURSE CppSrc
	"../../src/*.c"
	"../../src/*.cpp"
)

add_library(gtypes STATIC ${CppSrc})

include_directories(AFTER "../../include/gtypes")
include_directories(AFTER "../../src")

add_definitions(
	-DGTYPES_EXPORTS
)

target_link_libraries(
	gtypes
)
