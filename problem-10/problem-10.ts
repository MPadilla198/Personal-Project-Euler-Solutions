import { NewPrimeSieve } from './../utils/typescript/prime_sieve';


const SIZE = 2000000

// Create prime sieve
const prime_sieve: boolean[] = NewPrimeSieve(SIZE)

let i = 0
let sum = 0
for (const val of prime_sieve) {
    if (val) {
        sum += i
    }
    i++
}

console.log(sum)