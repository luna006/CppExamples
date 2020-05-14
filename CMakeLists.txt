cmake_minimum_required(VERSION 3.10)
project(cpp_examples)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_subdirectory(smart_pointers)
add_subdirectory(calculator)
