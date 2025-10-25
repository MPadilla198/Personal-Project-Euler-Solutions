package main

import (
	"fmt"

	"github.com/MPadilla198/utils"
)

func TriangularNumberGenerator() func() int {
	sum := 0
	count := 1
	return func() int {
		sum += count
		count++
		return sum
	}
}

func main() {

	nextTriangularNumber := TriangularNumberGenerator()

	for range 20 {
		fmt.Println(nextTriangularNumber())
	}

	// Get all primes to reasonable guess, i.e. 100,000,000
	primes := utils.GetPrimesLessThan(100000000)
	fmt.Printf("%v\n", primes)

	// for each triangular number
	//   use primes to find prime factors
	//   find out to what power these prime numbers are factors
	//   Use above info to find number of factors
	//   If number of factors is above 500, print triangular number
}
