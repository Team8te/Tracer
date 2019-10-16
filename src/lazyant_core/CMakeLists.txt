cmake_minimum_required(VERSION 3.10)

include_directories(${LAZYANT_SOURCE_ROOT}/include)

set(INCLUDES    ../../include/lazyant_core/export.hpp
                ../../include/lazyant_core/IOutStream.hpp
                ../../include/lazyant_core/ITrace.hpp
                ../../include/lazyant_core/ITracer.hpp
                ../../include/lazyant_core/internal/ImplOutStream.hpp
                ../../include/lazyant_core/internal/ImplTracer.hpp
                ../../include/lazyant_core/internal/TraceString.hpp
                )

set(SOURCES ImplOutStream.cpp
            ImplTracer.cpp
            ITracer.cpp
            TraceString.cpp)

set(PRIVATE_INCLUDES)

add_library(lazyant_core SHARED  ${SOURCES}
                                 ${INCLUDES})

if(WIN32)
    set_target_properties(lazyant_core PROPERTIES LINK_FLAGS "/INCREMENTAL:NO")
endif()

if (LAZYANT_EXPORT)
    target_compile_definitions(lazyant_core PUBLIC LAZYANT_EXPORT)
endif()