@echo off

REM Make dir
if not exist build (
    mkdir build
)

REM Compile the source files using g++
g++ -o ./build/CDSL -std=c++17 src/*.cpp
