cmake_minimum_required(VERSION 3.10)

project(lazyant)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(LAZYANT_SOURCE_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

option(LAZYANT_BUILD_TESTS ON)
list(APPEND CMAKE_MODULE_PATH ${LAZYANT_SOURCE_ROOT}/cmake)

add_subdirectory(src)

option(LAZYANT_EXPORT ON)

if(LAZYANT_BUILD_TESTS)
    find_package(GTest REQUIRED)
    add_subdirectory(tests)
endif()