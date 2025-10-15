import math

GIVEN_COMPOSITE = 600851475143
composite_sqrt = int(math.sqrt(GIVEN_COMPOSITE)) + 1

# Create prime sieve and populate to assume all numbers are prime, initially
prime_sieve = [True] * composite_sqrt

i = 2
while i < composite_sqrt:
    for index in range(i*i, composite_sqrt, i):
        prime_sieve[index] = False

    # Update i to the next prime exposed by the sieve
    i += 1
    while i < composite_sqrt and not prime_sieve[i]:
        i += 1

i = composite_sqrt -1
for value in reversed(prime_sieve):
    if value and GIVEN_COMPOSITE % i == 0:
        print(i)
        break
    i -= 1
