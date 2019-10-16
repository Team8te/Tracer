cmake_minimum_required(VERSION 3.10)

include(GoogleTest)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(lazyant_core)
add_subdirectory(object)

add_executable(${PROJECT_NAME}_test main.cpp
                                    $<TARGET_OBJECTS:lazyant_core_test>
                                    $<TARGET_OBJECTS:object_test>)

if(WIN32)
    set_target_properties(${PROJECT_NAME}_test PROPERTIES LINK_FLAGS "/INCREMENTAL:NO")
endif()

target_link_libraries(${PROJECT_NAME}_test PRIVATE  gtest
                                                    gmock
                                                    gtest_main
                                                    lazyant_core)

gtest_discover_tests(${PROJECT_NAME}_test)