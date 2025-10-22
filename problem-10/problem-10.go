package main

import (
	"fmt"

	"github.com/MPadilla198/utils"
)

func main() {
	const SIZE = 2000000

	// Create prime sieve
	prime_sieve := utils.NewPrimeSieve(SIZE)

	sum := 0

	// Iterate sieve, adding all primes
	for i, val := range prime_sieve {
		if i < 2 {
			continue
		}

		if val {
			sum += i
		}
	}

	fmt.Println(sum)
}
