# Personal-Project-Euler-Solutions

This is a compilation of all of my solutions to the problems presented in the [Project Euler Problem Archive](https://projecteuler.net/archives) using multiple languages, including Golang, Python, C/C++, Typescript and Java.

| __No.__ | __Problem__ | __Golang__ | __Python__ | __C__ | __C++__ | __Typescript__ | __Java__ |
| ------- | ----------- | ---------- | ---------- | ----- | ------- | -------------- | -------- |
| 1 | [Multiples of 3 or 5](https://projecteuler.net/problem=1) | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: |
| 2 | [Even Fibonacci Numbers](https://projecteuler.net/problem=2) | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: |
| 3 | [Largest Prime Factor](https://projecteuler.net/problem=3) | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: |
| 4 | [Largest Palindrome Product](https://projecteuler.net/problem=4) |  |  |  |  |  |  |
| 5 | [Smallest Multiple](https://projecteuler.net/problem=5) | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: |
| 6 | [Sum Square Difference](https://projecteuler.net/problem=6) | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: |
| 7 | [10 001st Prime](https://projecteuler.net/problem=7) | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: |
| 8 | [Largest Product in a Series](https://projecteuler.net/problem=8) | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: |
| 9 | [Special Pythagorean Triplet](https://projecteuler.net/problem=9) |  |  |  |  |  |  |
| 10 | [Summation of Primes](https://projecteuler.net/problem=10) | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :white_check_mark: | :x: |
| 11 | [Largest Product in a Grid](https://projecteuler.net/problem=11) |  |  |  |  |  |  |
| 12 | [Highly Divisible Triangular Number](https://projecteuler.net/problem=12) |  |  |  |  |  |  |
| 13 | [Large Sum](https://projecteuler.net/problem=13) |  |  |  |  |  |  |
| 14 | [Longest Collatz Sequence](https://projecteuler.net/problem=14) |  |  |  |  |  |  |
| 15 | [Lattice Paths](https://projecteuler.net/problem=15) |  |  |  |  |  |  |
| 16 | [Power Digit Sum](https://projecteuler.net/problem=16) |  |  |  |  |  |  |
| 17 | [Number Letter Counts](https://projecteuler.net/problem=17) |  |  |  |  |  |  |
| 18 | [Maximum Path Sum I](https://projecteuler.net/problem=18) |  |  |  |  |  |  |
| 19 | [Counting Sundays](https://projecteuler.net/problem=19) |  |  |  |  |  |  |
| 20 | [Factorial Digit Sum](https://projecteuler.net/problem=20) |  |  |  |  |  |  |

## Instructions for running each language

These instructions assume that you have installed each language onto your machine.

Also, if a _permission denied_ response is given when attempting to run any of these scripts, then run
```
chmod +x {script-name}
```

For example, to give execution permission to the golang script, run
```
chmod +x run-go.sh
```

### Golang
From the project root directory, run 
```
./run-go.sh {problem-name}
```

For example, to run problem 1 from the root directory, run
```
./run-go.sh problem-1
```
__NOTE:__ This __MUST__ be run from the root directory as the _run-go_ script used relies on relative paths.

### Python

From the project root directory, run 
```
./run-py.sh {problem-name}
```

For example, to run problem 3, run
```
./run-py.sh problem-3
```

__NOTE:__ This __MUST__ be run from the root directory as the _run-py_ script relies on relative paths.

### C
From the project root directory, run
```
./run-c.sh {problem-name}
```

For example, to run problem 1, run
```
./run-c.sh problem-1
```

The script _run-c.sh_ compiles the source code, runs the executable, then deletes the compiled executable.

__NOTE:__ This __MUST__ be run from the root directory as the script relies on relative paths.

### C++
From the project root directory, run
```
./run-cpp.sh {problem-name}
```

For example, to run problem 1, run
```
./run-cpp.sh problem-1
```

The script _run-cpp.sh_ compiles the source code, runs the executable, then deletes the compiled executable.

__NOTE:__ This __MUST__ be run from the root directory as the script relies on relative paths.

### Typescript
Run
```
tsx {file-path}
```

For example, to run problem 1 from the root directory, run
```
tsx problem-1/problem-1.ts
```

### Java
From the project root directory, run
```
./run-java.sh {problem-name}
```

For example, to run problem 1, run
```
./run-java.sh problem1
```

__NOTE:__ This __MUST__ be run from the root directory as the _run-java_ script relies on relative paths.

__NOTE:__ The hyphen is removed from file name of the java file, because it causes conflicts with the Java class name requirements.