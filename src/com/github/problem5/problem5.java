package com.github.problem5;

public class problem5 {
    public static void main(String[] args) {
        int[] primes = {2,3,5,7,11,13,17,19};
        int product = 1;

        for (int prime : primes) {
            int subproduct = prime;

            while (subproduct < 20) {
                product *= prime;
                subproduct *= prime;
            }
        }

        System.out.println(product);
    }    
}
