#include <iostream>

#include "../../utils/cpp/primes.cpp"

int main()
{

    const int SIZE = 2000000;

    // Create prime sieve
    bool *prime_sieve = newPrimeSieve(SIZE);

    long int sum = 0;

    for (long int i = 2; i < SIZE; i++)
        if (prime_sieve[i])
            sum += i;

    std::cout << sum << std::endl;

    delete prime_sieve;

    return 0;
}