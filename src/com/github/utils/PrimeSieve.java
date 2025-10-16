package com.github.utils;

import java.util.Arrays;

public class PrimeSieve {
    public static boolean[] NewPrimeSieve(int size) {
        // Create prime sieve
        boolean[] prime_sieve = new boolean[size];

        // Populate the prime sieve to assume all numbers are prime
        Arrays.fill(prime_sieve, Boolean.TRUE);

        // Set all composite numbered indexes in the sieve to false
        int i = 2;
        while (i < size) {
            for (int index = i * i; index > 0 && index < size; index += i) {
                prime_sieve[index] = false;
            }

            // Update i to the next prime exposed by the sieve
            i++;
            while (i < size && !prime_sieve[i]) {
                i++;
            }
        }

        return prime_sieve;
    }
}
