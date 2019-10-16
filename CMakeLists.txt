cmake_minimum_required(VERSION 3.10)

project(lazyant)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(LAZYANT_SOURCE_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

#if (MSVC)
#    set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
#    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#endif ()

link_directories("C:/Users/Alexander Sorokin/CMakeBuilds/f5186564-9768-a83a-a7a8-35d7206a1d62/build/x86-Debug/src/lazyant_core")

option(LAZYANT_BUILD_TESTS ON)
list(APPEND CMAKE_MODULE_PATH ${LAZYANT_SOURCE_ROOT}/cmake)

add_subdirectory(src)

option(LAZYANT_EXPORT ON)

if(LAZYANT_BUILD_TESTS)
    find_package(GTest REQUIRED)
    add_subdirectory(tests)
endif()