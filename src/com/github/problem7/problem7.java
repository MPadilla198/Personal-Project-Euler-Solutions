package com.github.problem7;

import com.github.utils.PrimeSieve;

public class problem7 {
    public static void main(String[] args) {
        // This size is a rough estimate for how high the result might be
        int size = 400000;

        // Create prime sieve
        boolean[] prime_sieve = PrimeSieve.NewPrimeSieve(size);

        int count = 1;

        for (int i = 2; i < size; i++) {
            if (prime_sieve[i]) {
                count++;
                if (count == 10001) {
                    System.out.println(i);
                    break;
                }
            }
        }
    }
}
