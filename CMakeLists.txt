# +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# + CMakeLists.txt
# + Folder: /
# +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

project(AngewandteKryptographie)
cmake_minimum_required(VERSION 3.4)
# set(CMAKE_VERBOSE_MAKEFILE true)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib )
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules )

add_subdirectory(src)
add_subdirectory(test)
