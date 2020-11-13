cmake_minimum_required (VERSION 3.8)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
	project( ip_printer VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
	project( ip_printer VERSION 99.99.999)
endif()

add_subdirectory (${PROJECT_SOURCE_DIR}/libs)
add_subdirectory (${PROJECT_SOURCE_DIR}/src)
add_subdirectory (${PROJECT_SOURCE_DIR}/test)

