package main

import (
	"fmt"

	"github.com/MPadilla198/utils"
)

func main() {
	size := 400000

	// Create prime sieve
	prime_sieve := utils.NewPrimeSieve(size)

	count := 0
	result := 0
	for i := 2; i < size; i++ {
		if prime_sieve[i] {
			count++
			if count == 10001 {
				result = i
				break
			}
		}
	}

	fmt.Println(result)
}
