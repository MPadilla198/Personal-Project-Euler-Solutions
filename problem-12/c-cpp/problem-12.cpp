#include <iostream>
#include <cmath>

#include "../../utils/cpp/primes.cpp"

using namespace std;

// Globals for getTriangularNumber
long int sum = 0;
long int count = 1;

long int nextTriangularNumber()
{
    sum += count;
    count++;
    return sum;
}

int main()
{
    // Get all primes to reasonable guess, i.e. 10,000,000
    long *primes = getPrimesLessThan(10000000);

    // for each triangular number
    while (true)
    {
        long triangularNumber = nextTriangularNumber();
        long triangularNumberSqrt = (long)sqrtl((long double)triangularNumber);

        int factors = 1;

        // use primes to find prime factors
        for (int i = 0; primes[i] < triangularNumberSqrt; i++)
        {
            long prime = primes[i];

            // If this prime is a factor of the triangular number then
            if (triangularNumber % prime == 0)
            {
                // find out to what power these prime numbers are factors

                int power = 1;
                int factor = prime;

                while (triangularNumber % (factor * prime) == 0)
                {
                    power++;
                    factor *= prime;
                }

                factors *= power + 1;
            }
        }

        // If number of factors is above 500, print triangular number
        if (factors > 500)
        {
            printf("%ld\n", triangularNumber);
            break;
        }
    }

    return 0;
}