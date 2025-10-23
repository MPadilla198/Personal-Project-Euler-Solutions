package main

import (
	"os"
	"strconv"
	"strings"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func print2DArray(arr [][]int) {
	for _, row := range arr {
		for _, col := range row {
			print(col, " ")
		}
		println()
	}
}

func load2DArray() [][]int {
	SIZE := 20
	result := make([][]int, SIZE)

	// open file with sequence
	file, err := os.ReadFile("numbers.txt")
	check(err)

	// Split on newline
	lines := strings.Split(string(file), "\n")

	for i, line := range lines {
		// Create sub-array
		result[i] = make([]int, SIZE)

		digits := strings.Split(line, " ")

		for j, digit := range digits {
			result[i][j], err = strconv.Atoi(digit)
			check(err)
		}
	}

	return result
}

func main() {
	print2DArray(load2DArray())
}
