let primes = [2,3,5,7,11,13,17,19]
let product = 1

for (const prime of primes) {
    let subproduct = prime

    while (subproduct < 20) {
        product *= prime
        subproduct *= prime
    }
}

console.log(product)