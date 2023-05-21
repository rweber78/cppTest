cmake_minimum_required(VERSION 3.22)
project(cppTest)

message(STATUS "Creating cppTest cmake files")

set(CMAKE_CXX_STANDARD 17)

include_directories(src googletest/googletest/include)

file(GLOB SRC_FILES src/*.cpp src/*.h)

add_subdirectory(googletest)
add_subdirectory(tst)

add_executable(cppTest ${SRC_FILES} main.cpp)
# target_link_libraries(cppTest PUBLIC)
