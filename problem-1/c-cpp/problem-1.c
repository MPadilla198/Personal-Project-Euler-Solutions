#include <stdio.h>

int main() {
    // Sum of multiples of 3, using Gauss Summation
	int multiples_of_3_sum = 3 * ((333 * (1 + 333)) / 2);

	// Sum of multiples of 5, using Gauss Summation
	int multiples_of_5_sum = 5 * ((199 * (1 + 199)) / 2);

	// Sum of multiples of 15, using Gauss Summation
	int multiples_of_15_sum = 15 * ((66 * (1 + 66)) / 2);

	// Add summations of 3 and 5 then subtract the numbers that have both as factors (multiples of 15)
	int multiples_of_3_and_5 = multiples_of_3_sum + multiples_of_5_sum - multiples_of_15_sum;
    
    // Display result
    printf("%d\n", multiples_of_3_and_5);
    return 0;
}