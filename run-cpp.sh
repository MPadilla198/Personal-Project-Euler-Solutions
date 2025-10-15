#!/bin/bash

# Compile c++ code
g++ $1/c-cpp/$1.cpp -o $1/c-cpp/$1

# run compiled code
./$1/c-cpp/$1

# delete compiled code
rm $1/c-cpp/$1
