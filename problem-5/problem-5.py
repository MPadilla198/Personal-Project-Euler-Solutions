primes = [2,3,5,7,11,13,17,19]
product = 1

for prime in primes:
    subproduct = prime

    while subproduct < 20:
        product *= prime
        subproduct *= prime

print(product)