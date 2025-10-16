import { NewPrimeSieve } from './../utils/typescript/prime_sieve';

// This size is a rough estimate for how high the result might be
let size = 400000

// Create prime sieve
let prime_sieve = NewPrimeSieve(size)

let count = 0;
for (let i = 2; i < size; i++) {
    if (prime_sieve[i]) {
        count++
        if (count == 10001) {
            console.log(i)
            break
        }
    }
}