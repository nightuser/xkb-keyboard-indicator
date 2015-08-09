cmake_minimum_required (VERSION 2.8 FATAL_ERROR)
project(xki)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

add_definitions(-O2 -Wall -Wextra -pedantic -std=gnu99)

add_subdirectory(src)
