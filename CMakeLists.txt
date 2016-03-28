cmake_minimum_required (VERSION 2.8 FATAL_ERROR)
project(xki)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -Werror -DNDEBUG")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=gnu99")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

add_subdirectory(src)
