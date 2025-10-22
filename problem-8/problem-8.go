package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func runeToInt(char rune) int {
	result, err := strconv.Atoi(string(char))
	check(err)
	return result
}

func charToInt(char byte) int {
	return int(char - '0')
}

func main() {
	// open file with sequence
	file, err := os.ReadFile("sequence.txt")
	check(err)

	// Split on 0 because any segment with a 0 cannot be the largest
	data := strings.Split(string(file), "0")

	maxProduct := 0

	for _, str := range data {
		// Skip strings with length less than 13
		if len(str) < 13 {
			continue
		}

		product := 1
		baseIndex := 0 // Tracks the index of the first digit being used
		for strIndex, char := range str {
			// Convert character to numerical value
			digit := runeToInt(char)

			if strIndex < 13 {
				product *= digit

				if strIndex != 12 {
					// Do not check product against max product
					continue
				}
			} else {
				// Remove base from product
				product /= charToInt(str[baseIndex])

				product *= digit
				baseIndex++
			}

			if maxProduct < product {
				maxProduct = product
			}
		}
	}

	fmt.Println(maxProduct)
}
