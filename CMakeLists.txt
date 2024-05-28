cmake_minimum_required(VERSION 3.10)

project(CDSL)

# C++ standard version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source files
set(SOURCES
    src/main.cpp
    src/header/Array.h
    src/header/LinkedList.h
)

# Executable
add_executable(CDSL ${SOURCES})
