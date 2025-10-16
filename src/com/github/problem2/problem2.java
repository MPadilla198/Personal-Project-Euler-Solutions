package com.github.problem2;

public class problem2 {
    public static void main(String[] args) {
        int a = 1;
        int b = 2;
        int sum = 0;

        while (b < 4000000) {
            // If even, then add fibonacci term to sum
            if (b % 2 == 0) {
                sum += b;
            }

            // Update fibonacci terms
            int c = a + b;
            a = b;
            b = c;
        }

        System.out.println(sum);
    }
}
