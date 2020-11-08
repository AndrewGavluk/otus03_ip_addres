cmake_minimum_required(VERSION 3.2)
enable_testing()

find_package(GTest REQUIRED)
include_directories()
add_executable(gtest_ip test_ip.cpp)

set_target_properties(gtest_ip 
	PROPERTIES 
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS})
	
				
if(MSVC)
	target_compile_options(gtest_ip PRIVATE /W4)
else()
	target_compile_options(gtest_ip PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
							
target_link_libraries(gtest_ip gtest pthread libip)
							
add_test(gtest_ip_test1 gtest_ip)
