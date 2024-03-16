#! /bin/bash
# 该脚本用于自动编译QUARK-AUTONOMOUS工程

rm -r build
mkdir build
cd build
cmake ..
make -j6

