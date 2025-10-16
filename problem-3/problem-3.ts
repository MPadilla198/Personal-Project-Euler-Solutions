import { NewPrimeSieve } from './../utils/typescript/prime_sieve';

const given_composite = 600851475143
let composite_sqrt = Math.floor(Math.sqrt(given_composite)) + 1

// Create prime sieve and populate to assume all numbers are prime, initially
const prime_sieve: boolean[] = NewPrimeSieve(composite_sqrt)

let i = composite_sqrt - 1
for (const value of prime_sieve.reverse()) {
    if (value && given_composite % i == 0) {
        console.log(i)
        break
    }
    i--
}