cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 17)

option(TRACER_BUILD_TESTS OFF)

project(Tracer)

set(SOURCE)

if(TRACER_BUILD_TESTS)
    find_package(GTest REQUIRED)
    add_subdirectory(tests)
endif()

add_executable(${PROJECT_NAME} ${SOURCE})