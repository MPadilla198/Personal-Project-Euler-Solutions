bool *newPrimeSieve(int size)
{
    // Create prime sieve
    bool *prime_sieve = new bool[size];

    for (int i = 0; i < size; i++)
    {
        prime_sieve[i] = true;
    }

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