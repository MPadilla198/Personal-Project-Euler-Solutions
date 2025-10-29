package com.github.problem10;

import com.github.utils.Primes;

public class problem10 {
    public static void main(String[] args) {
        final int SIZE = 2000000;

        // Create prime sieve
        boolean[] prime_sieve = Primes.NewPrimeSieve(SIZE);

        long sum = 0;

        for (int i = 2; i < SIZE; i++) {
            if (prime_sieve[i]) {
                sum += (long) i;
            }
        }

        System.out.println(sum);
    }
}
