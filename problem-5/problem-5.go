package main

import "fmt"

func main() {
	primes := [...]int{2, 3, 5, 7, 11, 13, 17, 19}
	product := 1

	for i := range len(primes) {
		prime := primes[i]
		subproduct := prime

		for subproduct < 20 {
			product *= prime
			subproduct *= prime
		}
	}

	fmt.Println(product)
}
