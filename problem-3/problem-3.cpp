#include <iostream>
#include <math.h>

int main()
{
    const long int given_composite = 600851475143L;
    const int composite_sqrt = 775147;

    // Create prime sieve
    bool prime_sieve[775147];

    for (int i = 0; i < composite_sqrt; i++) {
        prime_sieve[i] = true;
    }

    // Set all composite numbered indexes in the sieve to false
    int i = 2;
    while (i < composite_sqrt)
    {
        for (int index = i * i; index > 0 && index < composite_sqrt; index += i)
        {
            prime_sieve[index] = false;
        }

        // Update i to the next prime exposed by the sieve
        i++;
        while (i < composite_sqrt && !prime_sieve[i])
        {
            i++;
        }
    }

    // Iterate sieve in reverse and mod the given composite until it equals 0
    for (int j = composite_sqrt - 1; j > 0; j--)
    {
        if (prime_sieve[j] && given_composite % ((long int) j) == 0)
        {
            break;
        }
    }

    return 0;
}