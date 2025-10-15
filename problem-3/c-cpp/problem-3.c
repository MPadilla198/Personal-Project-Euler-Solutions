#include <stdio.h>
#include "../../utils/c/prime_sieve.c"

int main()
{
    const long int given_composite = 600851475143L;
    const int composite_sqrt = 775147;

    // Create prime sieve
    unsigned char* prime_sieve = getPrimeSieve(composite_sqrt);

    // Iterate sieve in reverse and mod the given composite until it equals 0
    for (int j = composite_sqrt - 1; j > 0; j--)
    {
        if (prime_sieve[j] != 0 && given_composite % ((long int) j) == 0)
        {
            printf("%d\n", j);
            break;
        }
    }

    free(prime_sieve);

    return 0;
}