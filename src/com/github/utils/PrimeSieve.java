package com.github.utils;

import java.util.Arrays;

public class PrimeSieve {
    public static boolean[] NewPrimeSieve(int size) {
        // Create prime sieve
        boolean[] prime_sieve = new boolean[size+1];

        // Populate the prime sieve to assume all numbers are prime
        Arrays.fill(prime_sieve, Boolean.TRUE);

        // 0 and 1 are not prime
        prime_sieve[0] = false;
        prime_sieve[1] = false;

        // Set all composite numbered indexes in the sieve to false
        long i = 2;
        while (i * i < size) {
            for (long index = i * i; index >= 0 && index < size; index += i) {
                prime_sieve[(int) index] = false;
            }

            // Update i to the next prime exposed by the sieve
            do {
                i++;
            } while (i * i < size && !prime_sieve[(int) i]);
        }

        return prime_sieve;
    }
}
