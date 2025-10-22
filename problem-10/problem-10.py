import sys

sys.path.append(".")

from utils import newPrimeSieve

SIZE = 2000000

# Create prime sieve and populate to assume all numbers are prime, initially
prime_sieve = newPrimeSieve(SIZE)

i = 0
sum = 0
for val in prime_sieve:
    if i >= 2 and val:
        sum += i
    i += 1

print(sum)