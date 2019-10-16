cmake_minimum_required(VERSION 3.10)

include_directories(${LAZYANT_SOURCE_ROOT}/include)

add_subdirectory(lazyant_core)

add_executable(${PROJECT_NAME}_tool  main.cpp)
target_link_libraries(${PROJECT_NAME}_tool PRIVATE lazyant_core)