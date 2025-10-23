#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constants
const int LINE_SIZE = 61;
const int SIZE = 20;

int main()
{
    FILE *fptr;

    // open file with numbers
    fptr = fopen("problem-11/numbers.txt", "r");

    // Read entire file
    char line[LINE_SIZE];

    // string split the sequence based on newline
    char lines[SIZE][LINE_SIZE];

    int index = 0;
    while (fgets(line, LINE_SIZE, fptr))
    {
        strcpy(lines[index], line);

        // Update
        index++;
    }

    // Split strings on spaces and convert strings to ints
    char *number;
    int matrix[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        int j = 0;
        number = strtok(lines[i], " ");
        while (number != NULL)
        {
            matrix[i][j] = atoi(number);

            // Update
            j++;
            number = strtok(NULL, " ");
        }
    }

    const int DISPLACE_SIZE = 3; // We are calculating the 4 adjacent numbers, so TRAVERSE_SIZE reflects the bounds of this traversal
    const int TRAVERSE_SIZE = SIZE - DISPLACE_SIZE;

    int maxProduct = 0;

    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (c < TRAVERSE_SIZE) {
                const int horizontalProduct = matrix[r][c] * matrix[r][c+1] * matrix[r][c+2] * matrix[r][c+3];
                if (horizontalProduct > maxProduct) {
                    maxProduct = horizontalProduct;
                } 
            }

            if (r < TRAVERSE_SIZE) {
                const int verticalProduct = matrix[r][c] * matrix[r+1][c] * matrix[r+2][c] * matrix[r+3][c];
                if (verticalProduct > maxProduct) {
                    maxProduct = verticalProduct;
                }
            }

            if (c < TRAVERSE_SIZE && r < TRAVERSE_SIZE) {
                const int diagonalProduct = matrix[r][c] * matrix[r+1][c+1] * matrix[r+2][c+2] * matrix[r+3][c+3];
                if (diagonalProduct > maxProduct) {
                    maxProduct = diagonalProduct;
                }
            }

            if (c >= DISPLACE_SIZE && r < TRAVERSE_SIZE) {
                const int diagonalProduct = matrix[r][c] * matrix[r+1][c-1] * matrix[r+2][c-2] * matrix[r+3][c-3];
                if (diagonalProduct > maxProduct) {
                    maxProduct = diagonalProduct;
                }
            }
        }
    }

    printf("%d\n", maxProduct);

    // Close the file
    fclose(fptr);

    return 0;
}