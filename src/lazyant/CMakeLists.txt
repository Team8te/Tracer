cmake_minimum_required(VERSION 3.10)

include_directories(${LAZYANT_SOURCE_ROOT}/include)

set(SOURCES ImplOutStream.cpp
            ImplTracer.cpp
            ITracer.cpp
            TraceString.cpp)

set(PRIVATE_INCLUDES)

add_library(lazyant_core SHARED  ${SOURCES})

if (LAZYANT_EXPORT)
    target_compile_definitions(lazyant_core PRIVATE LAZYANT_EXPORT)
endif()