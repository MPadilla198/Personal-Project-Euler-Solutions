#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constants
#define LINE_SIZE 52 // 50 digits, plus a new line character and a null terminator
#define NUM_OF_LINES 100

#define RESULT_NUM_DIGITS 53 // 52 digits, plus a null terminator character

int main()
{
    FILE *fptr;

    // open file with numbers
    fptr = fopen("problem-13/numbers.txt", "r");

    // Read entire file
    char line[LINE_SIZE];

    // string split the sequence based on newline
    char lines[NUM_OF_LINES][LINE_SIZE];

    int index = 0;
    while (fgets(line, LINE_SIZE, fptr))
    {
        strcpy(lines[index], line);

        index++;
    }

    int carryOver = 0;
    char result[RESULT_NUM_DIGITS];
    result[RESULT_NUM_DIGITS - 1] = '\0';
    int resultIndex = RESULT_NUM_DIGITS - 2;

    for (int strIndex = LINE_SIZE - 3; strIndex >= 0; strIndex--)
    {
        int columnSum = carryOver;
        for (int colIndex = 0; colIndex < NUM_OF_LINES; colIndex++)
        {
            columnSum += lines[colIndex][strIndex] - '0';
        }

        // split between digit and carry over sum
        char digit = (columnSum % 10) + '0';
        carryOver = columnSum / 10;

        // Append to beginning of resulting string
        result[resultIndex] = digit;
        resultIndex--;
    }

    // Append left over carry over to beginning of the result
    result[resultIndex] = (carryOver % 10) + '0';
    carryOver /= 10;
    result[resultIndex-1] = carryOver + '0';

    // Print needed result
    for (int i = 0; i < 10; i++)
    {
        printf("%c", result[i]);
    }
    printf("\n");
}