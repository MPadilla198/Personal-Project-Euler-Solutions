def newPrimeSieve(size):
    # Create prime sieve and populate to assume all numbers are prime, initially
    prime_sieve = [True] * size

    i = 2
    while i < size:
        for index in range(i*i, size, i):
            prime_sieve[index] = False

        # Update i to the next prime exposed by the sieve
        i += 1
        while i < size and not prime_sieve[i]:
            i += 1
    
    return prime_sieve