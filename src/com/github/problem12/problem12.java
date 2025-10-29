package com.github.problem12;

import com.github.utils.Primes;
import java.util.ArrayList;

public class problem12 {

    private static int sum = 0;
    private static int count = 1;

    private static int nextTriangularNumber() {
        sum += count;
        count++;
        return sum;
    }

    public static void main(String[] args) {
        // Get all primes to reasonable guess, i.e. 10,000,000
        ArrayList<Long> primes = Primes.GetPrimesLessThan(10000000);

        // for each triangular number
        while (true) {
            int triangularNumber = nextTriangularNumber();
            int triangularNumberSqrt = (int) Math.sqrt((double) triangularNumber);

            long factors = 1;

            // Use primes to find prime numbers
            for (int i = 0; primes.get(i) < triangularNumberSqrt; i++) {
                long prime = primes.get(i);

                // If this prime is a factor of the triangular number then
                if (triangularNumber % prime == 0) {
                    // find out to what power these prime numbers are factors
                    long power = 1;
                    long factor = prime;

                    while (triangularNumber % (factor * prime) == 0) {
                        power++;
                        factor *= prime;
                    }
                    factors *= power + 1;
                }
            }
            // If number of factors is above 500, print triangular number
            if (factors > 500) {
                System.err.printf("%d\n", triangularNumber);
                break;
            }
        }
    }
}
