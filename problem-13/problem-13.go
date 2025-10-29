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

func loadFileData() []string {
	// open file with sequence
	file, err := os.ReadFile("numbers.txt")
	check(err)

	// Split on new lines
	lines := strings.Split(string(file), "\n")

	return lines
}

func main() {
	lines := loadFileData()
	lineLength := len(lines[0])
	numOfLines := len(lines)

	carryOver := 0
	result := ""

	for strIndex := lineLength - 1; strIndex >= 0; strIndex-- {
		columnSum := carryOver
		for colIndex := range numOfLines {
			columnSum += int(lines[colIndex][strIndex] - '0')
		}

		// Split between digit and carry over
		digit := strconv.Itoa(columnSum % 10)
		carryOver = columnSum / 10

		// Append to beginning of resulting string
		result = digit + result
	}

	// Append left over carry over to beginning of the result
	result = strconv.Itoa(carryOver) + result

	println(result[:10])
}
