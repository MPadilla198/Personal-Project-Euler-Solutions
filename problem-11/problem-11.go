package main

import (
	"os"
	"strconv"
	"strings"
)

// Size of 2D matrix
const SIZE = 20

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func load2DArray() [][]int {
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
	matrix := load2DArray()

	// We are calculating the 4 adjacent numbers, so TRAVERSE_SIZE reflects the bounds of this traversal
	const DISPLACE_SIZE = 3
	const TRAVERSE_SIZE = SIZE - DISPLACE_SIZE

	maxProduct := 0

	for row := range SIZE {
		for col := range SIZE {
			if col < TRAVERSE_SIZE {
				horizontalProduct := matrix[row][col] * matrix[row][col+1] * matrix[row][col+2] * matrix[row][col+3]
				if horizontalProduct > maxProduct {
					maxProduct = horizontalProduct
				}
			}

			if row < TRAVERSE_SIZE {
				verticalProduct := matrix[row][col] * matrix[row+1][col] * matrix[row+2][col] * matrix[row+3][col]
				if verticalProduct > maxProduct {
					maxProduct = verticalProduct
				}
			}

			// Diagonal with negative slope
			if col < TRAVERSE_SIZE && row < TRAVERSE_SIZE {
				diagonalProduct := matrix[row][col] * matrix[row+1][col+1] * matrix[row+2][col+2] * matrix[row+3][col+3]
				if diagonalProduct > maxProduct {
					maxProduct = diagonalProduct
				}
			}

			// Diagonal with positive slope
			if col >= DISPLACE_SIZE && row < TRAVERSE_SIZE {
				diagonalProduct := matrix[row][col] * matrix[row+1][col-1] * matrix[row+2][col-2] * matrix[row+3][col-3]
				if diagonalProduct > maxProduct {
					maxProduct = diagonalProduct
				}
			}
		}
	}

	println(maxProduct)
}
