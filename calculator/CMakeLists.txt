cmake_minimum_required(VERSION 3.10)
project(calculator)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

file(GLOB CALC_SRC "*.cpp")

add_executable(${PROJECT_NAME} ${CALC_SRC})
