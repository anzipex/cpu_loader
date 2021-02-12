cmake_minimum_required(VERSION 3.0.0)
project(cpu_loader VERSION 1.0)

set(SOURCE_FILES main.cpp CpuLoader.cpp)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(cpu_loader ${SOURCE_FILES})
