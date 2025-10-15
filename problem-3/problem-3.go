package main

import (
	"fmt"
	"math"
	"slices"

	"github.com/MPadilla198/utils"
)

func main() {
	const given_composite = 600851475143
	composite_sqrt := int(math.Sqrt(float64(given_composite))) + 1

	// Create prime sieve
	prime_sieve := utils.NewPrimeSieve(composite_sqrt)

	// Iterate sieve in reverse and mod the given composite until it equals 0
	for i, val := range slices.Backward(prime_sieve) {
		if val && given_composite%i == 0 {
			fmt.Println(i)
			break
		}
	}
}
