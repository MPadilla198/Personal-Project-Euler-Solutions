#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fptr;

    // open file with sequence
    fptr = fopen("problem-8/sequence.txt", "r");

    // Read entire sequence
    char sequence[1001];
    fgets(sequence, 1001, fptr);

    long int maxProduct = 0;

    // string split the sequence based on 0
    char *token;
    token = strtok(sequence, "0");
    while (token != NULL)
    {
        int tokenLength = strlen(token);
        // Skip strings with length less than 13 as these will contain a 0
        if (tokenLength < 13)
        {
            token = strtok(NULL, "0");
            continue;
        }

        long int product = 1;
        int baseIndex = 0; // Tracks the index of the first digit being used within the token
        for (int ind = 0; ind < tokenLength; ind++)
        {
            char character = token[ind];

            // Convert character to numerical value
            long int digit = character - '0';

            if (ind < 13)
            {
                product *= digit;

                if (ind != 12)
                {
                    // Do not check product against max product
                    continue;
                }
            }
            else
            {
                long int baseDigit = token[baseIndex] - '0';
                // Remove base from product
                product /= baseDigit;

                product *= digit;
                baseIndex++;
            }

            if (maxProduct < product)
            {
                maxProduct = product;
            }
        }

        token = strtok(NULL, "0");
    }

    printf("%d\n", maxProduct);

    // close the file
    fclose(fptr);

    return 0;
}