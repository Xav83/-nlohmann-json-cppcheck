cmake_minimum_required(VERSION 3.15.2)

project(cppcheckOnModernJson)

find_program(CONAN NAMES conan.exe HINTS "C:\\Program Files\\Conan\\conan")

if(${CONAN}-NOTFOUND)
    message(FATAL_ERROR "Conan not found")
endif(${CONAN}-NOTFOUND)

execute_process(COMMAND ${CONAN} install ${CMAKE_CURRENT_LIST_DIR} -s arch=x86 -s build_type=Debug -s compiler.runtime=MTd --build=missing
                COMMAND ${CONAN} install ${CMAKE_CURRENT_LIST_DIR} -s arch=x86 -s build_type=Release -s compiler.runtime=MT --build=missing
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
conan_basic_setup(TARGETS)

add_executable(HelloWorld ${CMAKE_CURRENT_LIST_DIR}/src/main)
set_source_files_properties(HelloWorld PROPERTIES CXX_STANDARD 17)
target_link_libraries(HelloWorld PRIVATE CONAN_PKG::jsonformoderncpp)