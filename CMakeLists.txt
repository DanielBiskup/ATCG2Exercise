cmake_minimum_required(VERSION 3.17)
project(bcg_graphics VERSION 1.0)

option(BCG_APPS "Build Apps" ON)
option(BCG_OPENGL "Build OpenGL" ON)
option(BCG_TESTS "Build Tests" ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif ()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)

if (NOT GENERATOR_IS_MULTI_CONFIG AND CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")
endif (NOT GENERATOR_IS_MULTI_CONFIG AND CMAKE_BUILD_TYPE MATCHES Debug)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if (GENERATOR_IS_MULTI_CONFIG)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR})
endif (GENERATOR_IS_MULTI_CONFIG)

add_subdirectory(external)
add_subdirectory(libs)
add_subdirectory(apps)

if(BCG_TESTS)
    add_subdirectory(tests)
endif(BCG_TESTS)
