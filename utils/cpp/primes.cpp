bool *newPrimeSieve(int size)
{
    // Create prime sieve
    bool *prime_sieve = new bool[size];

    for (int i = 0; i < size; i++)
    {
        prime_sieve[i] = true;
    }

    // 0 and 1 are not prime
    prime_sieve[0] = false;
    prime_sieve[1] = false;

    // Set all composite numbered indexes in the sieve to false
    long int i = 2;
    while (i < size)
    {
        for (long int index = i * i; index > 0 && index < size; index += i)
        {
            prime_sieve[index] = false;
        }

        // Update i to the next prime exposed by the sieve
        do
        {
            i++;
        } while (i < size && !prime_sieve[i]);
    }

    return prime_sieve;
}

int countPrimes(bool *primeSieve, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (primeSieve[i])
        {
            count++;
        }
    }

    return count;
}

long *getPrimesLessThan(int size)
{
    bool *primeSieve = newPrimeSieve(size);

    int primesSize = countPrimes(primeSieve, size);

    long *primes = new long[primesSize];
    int primesIndex = 0;

    for (long i = 0; i < size; i++)
    {
        if (primeSieve[i]) {
            primes[primesIndex] = i;
            primesIndex++;
        }
    }

    return primes;
}