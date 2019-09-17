cmake_minimum_required(VERSION 3.10)

project(lazyant)

set(CMAKE_CXX_STANDARD 17)
set(LAZYANT_SOURCE_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

option(LAZYANT_BUILD_TESTS ON)

add_subdirectory(src)

if(LAZYANT_BUILD_TESTS)
    find_package(GTest REQUIRED)
    add_subdirectory(tests)
endif()