#include <stdio.h>

int main()
{
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
    int primes_length = sizeof(primes) / sizeof(primes[0]);

    int product = 1;
    for (int i = 0; i < primes_length; i++)
    {
        int prime = primes[i];
        int subproduct = prime;

        while (subproduct < 20)
        {
            product *= prime;
            subproduct *= prime;
        }
    }

    printf("%d\n", product);
    return 0;
}