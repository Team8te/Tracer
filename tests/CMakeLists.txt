cmake_minimum_required(VERSION 3.10)

include(GoogleTest)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(lazyant)

add_executable(${PROJECT_NAME}_test main.cpp
                                    $<TARGET_OBJECTS:lazyant_core_test>)

target_link_libraries(${PROJECT_NAME}_test PRIVATE  gtest
                                                    gtest_main)

gtest_discover_tests(${PROJECT_NAME}_test)