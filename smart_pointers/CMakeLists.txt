cmake_minimum_required(VERSION 3.10)
project(smart_pointer)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

file(GLOB SMART_PTR_SRC "*.cpp")

add_executable(${PROJECT_NAME} ${SMART_PTR_SRC})
