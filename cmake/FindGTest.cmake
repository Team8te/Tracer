set(INSTALL_GTEST OFF CACHE BOOL "")
set(INSTALL_GTEST OFF CACHE BOOL "")
set(gtest_force_shared_crt ON CACHE BOOL "")
enable_testing()
add_subdirectory(${CMAKE_SOURCE_DIR}/3rdparty/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})