export function NewPrimeSieve(size: number): boolean[] {
    // Create prime sieve and populate to assume all numbers are prime, initially
    const prime_sieve: boolean[] = new Array<boolean>(size).fill(true);

    let i = 2
    while (i < size) {
        for (let index = i * i; index < size; index += i) {
            prime_sieve[index] = false
        }

        // Update i to the next prime exposed by the sieve
        do {
            i++
        } while (i < size && !prime_sieve[i])
    }

    return prime_sieve
}