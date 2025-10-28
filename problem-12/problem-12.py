import sys

sys.path.append(".")

from utils import getPrimesLessThan
from math import sqrt, floor

def triangularNumberGenerator():
    sum = 0
    count = 1
    while True:
        sum += count
        count += 1
        yield sum

nextTriangularNumber = triangularNumberGenerator()

# Get all primes to reasonable guess, i.e. 10,000,000
primes = getPrimesLessThan(10000000)

# for each triangular number
while True:
    triangularNumber = next(nextTriangularNumber)
    triangularNumberSqrt = floor(sqrt(triangularNumber))

    factors = 1

    # use primes to find prime factors
    i = 0
    while i < len(primes) and primes[i] < triangularNumberSqrt:
        prime = primes[i]

        # If this prime is a factor of the triangular number then
        if triangularNumber % prime == 0:
            # find out to what power these prime numbers are factors
            power = 1
            factor = prime
            while triangularNumber%(factor*prime) == 0:
                power += 1
                factor *= prime

            factors *= power + 1

        i += 1
    
    # If number of factors is above 500, print triangular number
    if factors > 500:
        print(triangularNumber)
        break