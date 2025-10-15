#include <stdio.h>

int main()
{
    long int sum_of_squares = 0;
    long int square_of_sum = 0;

    for (long int i = 1; i <= 100; i++)
    {
        sum_of_squares += i * i;
        square_of_sum += i;
    }

    square_of_sum *= square_of_sum;

    printf("%d\n", square_of_sum - sum_of_squares);

    return 0;
}