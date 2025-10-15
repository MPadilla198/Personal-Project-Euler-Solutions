package main

import "C"

func main() {
	sum_of_squares := 0
	square_of_sum := 0

	for i := 1; i <= 100; i++ {
		sum_of_squares += i * i
		square_of_sum += i
	}

	square_of_sum *= square_of_sum

	println(square_of_sum - sum_of_squares)
}
