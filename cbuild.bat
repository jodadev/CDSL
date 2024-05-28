@echo off
REM Create and navigate to the build directory
if not exist build (
    mkdir build
)
cd build

REM Run CMake and build the project
cmake ..
cmake --build .