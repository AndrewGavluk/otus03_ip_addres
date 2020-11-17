cmake_minimum_required(VERSION 3.8) 

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
	project( ip_printer VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
	project( ip_printer VERSION 99.99.999)
endif()
add_executable(ip_printer main.cpp)
set_target_properties(ip_printer PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQIRED ON)
target_link_libraries(ip_printer PRIVATE libip)

if(MSVC)
	target_compile_options(ip_printer PRIVATE /W4)
else()
	target_compile_options(ip_printer PRIVATE -Wall -Wextra -Werror)
endif()

install(TARGETS ip_printer RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME ip_printer)

set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})

set(CPACK_PACKAGE_CONTACT gavl.andr96@gmail.com)

include(CPack)
