# CMakeList.txt : CMake project for haxegitlib, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("haxegitlib")
# Add source to this project's executable.
add_executable (haxegitlib "haxegitlib.cpp" "haxegitlib.h" "tinyxml2.h" "tinyxml2.cpp")

set_property(TARGET haxegitlib PROPERTY CXX_STANDARD 17)
# TODO: Add tests and install targets if needed.
