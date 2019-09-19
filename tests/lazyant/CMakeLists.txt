cmake_minimum_required(VERSION 3.10)

set(SOURCE  test.cpp)

add_library(lazyant_core_test OBJECT
            ${SOURCE}
            )

target_link_libraries(lazyant_core_test PRIVATE)