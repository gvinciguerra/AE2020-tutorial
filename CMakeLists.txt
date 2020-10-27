cmake_minimum_required(VERSION 2.8.11)
project(AE2020-tutorial)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(sdsl-lite)

add_executable(tutorial main.cpp)
target_link_libraries(tutorial sdsl)