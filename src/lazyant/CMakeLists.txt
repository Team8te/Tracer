cmake_minimum_required(VERSION 3.10)

include_directories(${LAZYANT_SOURCE_ROOT}/include)

set(SOURCES BaseTracer.cpp)

set(PRIVATE_INCLUDES)

add_library(lazyant_core SHARED  BaseTracer.cpp)
if (LAZYANT_EXPORT)
    target_compile_definitions(lazyant_core PRIVATE LAZYANT_EXPORT) 
endif()