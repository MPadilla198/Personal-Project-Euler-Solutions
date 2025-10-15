package main

import (
	"fmt"
	"math"
	"slices"
)

func main() {
	const given_composite = 600851475143
	composite_sqrt := int(math.Sqrt(float64(given_composite))) + 1

	// Create prime sieve
	prime_sieve := make([]bool, composite_sqrt)

	// Populate the prime sieve to assume all numbers are prime
	for i := range composite_sqrt {
		prime_sieve[i] = true
	}

	// Set all composite numbered indexes in the sieve to false
	i := 2
	for i < composite_sqrt {
		// Set all
		for index := i * i; index < composite_sqrt; index += i {
			prime_sieve[index] = false
		}

		// Update i to the next prime exposed by the sieve
		i++
		for i < composite_sqrt && !prime_sieve[i] {
			i++
		}
	}

	// Iterate sieve in reverse and mod the given composite until it equals 0
	for i, val := range slices.Backward(prime_sieve) {
		if val && given_composite%i == 0 {
			fmt.Println(i)
			break
		}
	}
}
