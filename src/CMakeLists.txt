cmake_minimum_required(VERSION 3.8) 

add_executable(ip_address main.cpp)
set_target_properties(ip_address PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQIRED ON)
target_link_libraries(ip_address PRIVATE libip)

if(MSVC)
	target_compile_options(ip_address PRIVATE /W4)
else()
	target_compile_options(ip_address PRIVATE -Wall -Wextra -Werror)
endif()

install(TARGETS ip_address RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME )

set(CPACK_PACKAGE_VERSION_MAJOR )
set(CPACK_PACKAGE_VERSION_MINOR )
set(CPACK_PACKAGE_VERSION_PATCH )

set(CPACK_PACKAGE_CONTACT gavl.andr96@gmail.com)

include(CPack)
