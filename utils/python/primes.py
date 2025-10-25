def newPrimeSieve(size):
    # Create prime sieve and populate to assume all numbers are prime, initially
    prime_sieve = [True] * size

    # 0 and 1 are not prime
    prime_sieve[0] = False
    prime_sieve[1] = False

    i = 2
    while i < size:
        for index in range(i*i, size, i):
            prime_sieve[index] = False

        # Update i to the next prime exposed by the sieve
        i += 1
        while i < size and not prime_sieve[i]:
            i += 1
    
    return prime_sieve

def getPrimesLessThan(size):
    primeSieve = newPrimeSieve(size)

    primes = []

    for i in range(size):
        if primeSieve[i]:
            primes.append(i)
    
    return primes