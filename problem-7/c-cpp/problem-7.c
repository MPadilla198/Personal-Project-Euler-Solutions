#include <stdio.h>
#include "../../utils/c/prime_sieve.c"

int main()
{
    int size = 400000;

    unsigned char *prime_sieve = getPrimeSieve(size);

    int count = 1;
    for (int i = 2; i < size; i++)
    {
        // If slot in prime sieve is true, then
        if (prime_sieve[i] == 1)
        {
            ++count;
            if (count == 10001)
            {
                printf("%d\n", i);
                break;
            }
        }
    }

    free(prime_sieve);
    return 0;
}