package main

import (
	"C"
	"fmt"
)

/*
	PRIME SIEVE: SAVE FOR LATER PROBLEM

	sieve_size := 4000001
	sieve_size_sqrt := int(math.Sqrt(float64(sieve_size)))
	prime_sieve := make([]bool, sieve_size)

	// Populate the prime wieve to assume all numbers are prime
	for i := range sieve_size {
		prime_sieve[i] = true
	}

	// Set all composite numbered indexes in the sieve to false
	i := 2
	for i < sieve_size_sqrt {
		// Set all
		for index := i * i; index < sieve_size_sqrt; index += i {
			prime_sieve[index] = false
		}

		// Update i to the next prime exposed by the sieve
		i++
		for !prime_sieve[i] {
			i++
		}
	}
*/

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
