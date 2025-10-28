import { GetPrimesLessThan } from '../utils/typescript/primes';

function TriangularNumberGenerator(): () => number {
    let sum = 0
    let count = 1
    return function(): number {
        sum += count
        count++
        return sum
    }
}

let nextTriangularNumber = TriangularNumberGenerator()

// Get all primes to reasonable guess, i.e. 10,000,000
const primes: number[] = GetPrimesLessThan(10000000)

// for each triangular number
while (true) {
    const triangularNumber = nextTriangularNumber()
    const triangularNumberSqrt = Math.floor(Math.sqrt(triangularNumber))

    let factors = 1

    // use primes to find prime factors
    for (let i = 0; primes[i]! < triangularNumberSqrt; i++) {
        const prime = primes[i]!

        // If this prime is a factor of the triangular number then
        if (triangularNumber % prime == 0) {
            // find out to what power these prime numbers are factors
            let power = 1
            let factor = prime
            while (triangularNumber % (factor * prime) == 0) {
                power++
                factor *= prime
            }

            factors *= power + 1
        }
    }

    if (factors > 500) {
        console.log(triangularNumber)
        break;
    }
}