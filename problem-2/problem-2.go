package main

import (
	"C"
	"fmt"
)

func main() {
	a := 1
	b := 2

	sum := 0

	for b < 4000000 {
		// If even, then add fibonacci term to sum
		if b%2 == 0 {
			sum += b
		}

		// Update fibonacci terms
		c := a + b
		a = b
		b = c
	}

	fmt.Println(sum)
}
