package main

import "fmt"

func main() {
	// Sum of multiples of 3, using Gauss Summation
	multiples_of_3_sum := 3 * ((333 * (1 + 333)) / 2)

	// Sum of multiples of 5, using Gauss Summation
	multiples_of_5_sum := 5 * ((199 * (1 + 199)) / 2)

	// Sum of multiples of 15, using Gauss Summation
	multiples_of_15_sum := 15 * ((66 * (1 + 66)) / 2)

	// Add summations of 3 and 5 then subtract the numbers that have both as factors (multiples of 15)
	multiples_of_3_and_5 := multiples_of_3_sum + multiples_of_5_sum - multiples_of_15_sum

	// Display result
	fmt.Println(multiples_of_3_and_5)
}
