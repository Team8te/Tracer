cmake_minimum_required(VERSION 3.10)

include_directories(${LAZYANT_SOURCE_ROOT}/include)

set(INCLUDES ../../include/export.hpp
            ../../include/IOutStream.hpp
            ../../include/ITrace.hpp
            ../../include/ITracer.hpp)

set(SOURCES ImplOutStream.cpp
            ImplTracer.cpp
            ITracer.cpp
            TraceString.cpp)

set(PRIVATE_INCLUDES)

add_library(lazyant_core SHARED  ${SOURCES} 
                                 ${INCLUDES})

if (LAZYANT_EXPORT)
    target_compile_definitions(lazyant_core PUBLIC LAZYANT_EXPORT)
endif()