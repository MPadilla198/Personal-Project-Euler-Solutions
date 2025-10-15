package utils

func NewPrimeSieve(size int) []bool {

	// Create prime sieve
	prime_sieve := make([]bool, size)

	// Populate the prime sieve to assume all numbers are prime
	for i := range size {
		prime_sieve[i] = true
	}

	// Set all composite numbered indexes in the sieve to false
	i := 2
	for i < size {
		for index := i * i; index < size; index += i {
			prime_sieve[index] = false
		}

		// Update i to the next prime exposed by the sieve
		i++
		for i < size && !prime_sieve[i] {
			i++
		}
	}

	return prime_sieve
}
