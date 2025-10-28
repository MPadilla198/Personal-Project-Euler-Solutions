#include <iostream>
#include <math.h>

#include "../../utils/cpp/primes.cpp"

using namespace std;

int main()
{
    const long int given_composite = 600851475143L;
    const int composite_sqrt = 775147;

    // Create prime sieve
    bool *prime_sieve = newPrimeSieve(composite_sqrt);

    // Iterate sieve in reverse and mod the given composite until it equals 0
    for (long int j = composite_sqrt - 1; j > 0; j--)
    {
        if (prime_sieve[j] && given_composite % j == 0)
        {
            cout << j << endl;
            break;
        }
    }

    delete prime_sieve;

    return 0;
}