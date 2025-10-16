import sys

sys.path.append(".")

from utils import newPrimeSieve

# This size is a rough estimate for how high the result might be
size = 400000

# Create prime sieve
primeSieve = newPrimeSieve(size)

count = 0
for i in range(2, size):
    if primeSieve[i]:
        count += 1
        if count == 10001:
            print(i)
            break

