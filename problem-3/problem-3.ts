const given_composite = 600851475143
let composite_sqrt = Math.floor(Math.sqrt(given_composite)) + 1

// Create prime sieve and populate to assume all numbers are prime, initially
const prime_sieve: boolean[] = new Array(composite_sqrt).fill(true);

let i = 2
while (i < composite_sqrt) {
    for (let index = i*i; index < composite_sqrt; index += i) {
        prime_sieve[index] = false
    }

    // Update i to the next prime exposed by the sieve
    i++
    while (i < composite_sqrt && !prime_sieve[i]) {
        i++
    }
}

i = composite_sqrt - 1
for (const value of prime_sieve.reverse()) {
    if (value && given_composite % i == 0) {
        console.log(i)
        break
    }
    i--
}