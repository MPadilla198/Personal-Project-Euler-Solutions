#!/bin/bash

# Compile c code
gcc $1/c-cpp/$1.c -o $1/c-cpp/$1 -lm

# run compiled code
./$1/c-cpp/$1

# delete compiled code
rm $1/c-cpp/$1
