#include <stdio.h>
#include "../../utils/c/primes.c"

int main() {
    const int SIZE = 2000000;

    // Create prime sieve
    unsigned char* prime_sieve = getPrimeSieve(SIZE);

    long int sum = 0;

    for (long int i = 2; i < SIZE; i++) {
        if (prime_sieve[i] != 0) {
            sum += i;
        }
    }

    printf("%ld\n", sum);

    free(prime_sieve);

    return 0;
}