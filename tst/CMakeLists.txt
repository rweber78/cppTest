cmake_minimum_required(VERSION 3.22)

message(STATUS "Creating unitTest cmake files")

project(unitTest)

set(CMAKE_CXX_STANDARD 17)

file(GLOB TEST_FILES *.cpp)

add_executable(unitTest ${SRC_FILES} ${TEST_FILES})

target_link_libraries(unitTest PUBLIC gtest_main)
