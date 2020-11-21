#!/usr/bin/env bash

# change in external/spectral/CMakeLists.txt all occurrences of
# CMAKE_SOURCE_DIR to CMAKE_CURRENT_SOURCE_DIR
# and find_package(Eigen3 NO_MODULE REQUIRED) to find_package(eigen3 REQUIRED)
sed -i 's/CMAKE_SOURCE_DIR/CMAKE_CURRENT_SOURCE_DIR/g' ./external/spectra/CMakeLists.txt
sed -i 's/find_package(Eigen3 NO_MODULE REQUIRED)/find_package(eigen3 REQUIRED)/g' ./external/spectra/CMakeLists.txt
