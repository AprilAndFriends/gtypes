# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)
set(CMAKE_VERBOSE_MAKEFILE on)

file(
	GLOB_RECURSE CppSrc
    "../../include/*.h"
    "../../src/*.h"
    "../../src/*.cpp"
)

include_directories(AFTER "../../include/gtypes")
include_directories(AFTER "../../src")

add_library(
	gtypes
	STATIC
	${CppSrc}
)

target_link_libraries(
	gtypes
)
