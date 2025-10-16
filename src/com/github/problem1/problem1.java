package com.github.problem1;

public class problem1 {
    public static void main(String[] args) {
        // Sum of multiples of 3, using Gauss Summation
        int multiples_of_3_sum = (333 * (3 + 999)) / 2;

    	// Sum of multiples of 5, using Gauss Summation
        int multiples_of_5_sum = (199 * (5 + 995)) / 2;

        // Sum of multiples of 15, using Gauss Summation
        int multiples_of_15_sum = (66 * (15 + 990)) / 2;
    
    	// Add summations of 3 and 5 then subtract the numbers that have both as factors (multiples of 15)
	    int multiples_of_3_and_5 = multiples_of_3_sum + multiples_of_5_sum - multiples_of_15_sum;

        // Display result
        System.out.printf("%d\n", multiples_of_3_and_5);
    }
}