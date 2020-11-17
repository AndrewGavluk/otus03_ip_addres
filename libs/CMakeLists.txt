cmake_minimum_required(VERSION 3.8)

add_library(libip STATIC lib_ip.cpp lib_ip.h)
set_target_properties(libip  PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)
target_include_directories(libip PRIVATE ${CMAKE_BINARY_DIR})

if(MSVC)
	target_compile_options(libip PRIVATE /W4)
else()
 	target_compile_options(libip PRIVATE -Wall -Wextra -Werror)
endif()
