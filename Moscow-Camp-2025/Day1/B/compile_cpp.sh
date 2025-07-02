#!/bin/bash

g++ -std=c++17 -O2 -o segments $1 grader.cpp

#usage: bash compile_cpp.sh solution.cpp