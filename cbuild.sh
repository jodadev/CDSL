#!/bin/bash

# Create and navigate to the build directory
mkdir -p build
cd build

# Run CMake and build the project
cmake ..
make
