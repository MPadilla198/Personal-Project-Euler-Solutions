package com.github.problem3;

import com.github.utils.PrimeSieve;

public class problem3 {
    public static void main(String[] args) {
        long given_composite = 600851475143L;
        int composite_sqrt = (int) Math.sqrt(given_composite);

        // Create prime sieve
        boolean[] prime_sieve = PrimeSieve.NewPrimeSieve(composite_sqrt);

        // Iterate sieve in reverse and mod the given composite until it equals 0
        for (int j = composite_sqrt -1; j > 0; j--) {
            if (prime_sieve[j] && given_composite % j == 0) {
                System.out.println(j);
                break;
            }
        }
    }
}
