package main

import (
	"fmt"
	"math"

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

	// Get all primes to reasonable guess, i.e. 10,000,000
	primes := utils.GetPrimesLessThan(10000000)

	// for each triangular number
	for {
		triangularNumber := nextTriangularNumber()
		triangularNumberSqrt := int(math.Floor(math.Sqrt(float64(triangularNumber))))

		factors := 1
		//   use primes to find prime factors
		for i := 0; primes[i] < triangularNumberSqrt; i++ {
			prime := primes[i]

			// If this prime is a factor of the triangular number then
			if triangularNumber%prime == 0 {
				//   find out to what power these prime numbers are factors
				power := 1
				factor := prime
				for triangularNumber%(factor*prime) == 0 {
					power++
					factor *= prime
				}
				factors *= power + 1
			}

			// Catch this for sanity check
			if i == len(primes)-1 {
				fmt.Println("Not enough primes")
				return
			}
		}

		//   If number of factors is above 500, print triangular number
		if factors > 500 {
			fmt.Println(triangularNumber)
			return
		}
	}
}
