#include <stdlib.h>

unsigned char *getPrimeSieve(int size)
{
    // Create prime sieve
    unsigned char *prime_sieve = (unsigned char *)malloc(size * sizeof(unsigned char));

    for (int i = 0; i < size; i++)
    {
        prime_sieve[i] = 1;
    }

    // Set all composite numbered indexes in the sieve to false
    long int i = 2;
    while (i < size)
    {
        for (long int index = i * i; index >= 0 && index < size; index += i)
        {
            prime_sieve[index] = 0;
        }

        // Update i to the next prime exposed by the sieve
        do
        {
            i++;
        } while (i < size && prime_sieve[i] == 0);
    }

    return prime_sieve;
}