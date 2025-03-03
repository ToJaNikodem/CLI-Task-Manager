cmake_minimum_required(VERSION 3.10)
project(CLI-Task-Manager)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES src/main.cpp src/Task.cpp)

add_executable(CLI-Task-Manager ${SOURCES})
