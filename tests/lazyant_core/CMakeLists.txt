cmake_minimum_required(VERSION 3.10)

set(SOURCE  ITracer_test.cpp)

add_library(lazyant_core_test OBJECT
            ${SOURCE}
            )