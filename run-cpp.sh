#!/bin/bash

# Compile c++ code
g++ $1/$1.c -o $1/$1

# run compiled code
./$1/$1

# delete compiled code
rm $1/$1
