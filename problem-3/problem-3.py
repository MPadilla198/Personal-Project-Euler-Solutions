import sys

sys.path.append(".")

from utils import newPrimeSieve

import math

GIVEN_COMPOSITE = 600851475143
composite_sqrt = int(math.sqrt(GIVEN_COMPOSITE)) + 1

# Create prime sieve and populate to assume all numbers are prime, initially
prime_sieve = newPrimeSieve(composite_sqrt)

i = composite_sqrt -1
for value in reversed(prime_sieve):
    if value and GIVEN_COMPOSITE % i == 0:
        print(i)
        break
    i -= 1
