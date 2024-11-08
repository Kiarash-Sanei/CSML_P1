#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Defines the minimum series length and the range for random values
#define MIN_N 10000
#define RANGE_N 10000
#define MULTIPLY 1.0001 // Multiplier used for scaling terms in the summation

// Function to calculate each term in the series: computed as (1.0009)^(-x)
double series(int x)
{
    // Returns the reciprocal of (1.0009)^x for a given index 'x'
    return pow(pow(1.0009, x), -1);
}

int main()
{
    // Prompt the user to enter the number of calculations to perform
    printf("Please type the times that you want the series to be calculated!\n");
    int size;
    scanf("%d", &size); // Reads the user input to set the number of series calculations

    // Arrays to store summation results in single and double precision, using different addition orders
    float answerInSinglePrecisionMultiplyPlus[size];  // Single precision, multiply then sum
    float answerInSinglePrecisionPlusMultiply[size];  // Single precision, sum then multiply
    double answerInDoublePrecisionMultiplyPlus[size]; // Double precision, multiply then sum
    double answerInDoublePrecisionPlusMultiply[size]; // Double precision, sum then multiply
    int list[size];                                   // Stores randomly generated series lengths for each calculation

    // Seed the random number generator with the current time for unique random values
    srand(time(NULL));

    // Populate 'list' array with random series lengths between MIN_N and MIN_N + RANGE_N
    for (int i = 0; i < size; i++)
    {
        list[i] = rand() % RANGE_N + MIN_N; // Generate random series length for each entry in 'list'
    }

    // Compute the series summation for each series length in 'list'
    for (int i = 0; i < size; i++)
    {
        // Initialize summation values
        answerInSinglePrecisionMultiplyPlus[i] = 0;
        answerInDoublePrecisionMultiplyPlus[i] = 0;

        // Multiply each term by MULTIPLY, then sum
        for (int j = 0; j < list[i]; j++)
        {
            answerInSinglePrecisionMultiplyPlus[i] += MULTIPLY * series(j); // Single precision
            answerInDoublePrecisionMultiplyPlus[i] += MULTIPLY * series(j); // Double precision
        }

        // Initialize summation values
        answerInSinglePrecisionPlusMultiply[i] = 0;
        answerInDoublePrecisionPlusMultiply[i] = 0;

        // Sum terms first, then multiply the final sum by MULTIPLY
        for (int j = 0; j < list[i]; j++)
        {
            answerInSinglePrecisionPlusMultiply[i] += series(j); // Single precision
            answerInDoublePrecisionPlusMultiply[i] += series(j); // Double precision
        }

        // Apply multiplication to the final sum
        answerInSinglePrecisionPlusMultiply[i] *= MULTIPLY;
        answerInDoublePrecisionPlusMultiply[i] *= MULTIPLY;
    }

    // Output the results of different summation orders and precisions for each generated N
    for (int i = 0; i < size; i++)
    {
        printf("N: %d\n\tMultiply by 2 then summation:\n\t\tSingle: %f\n\t\tDouble: %.20lf\n\tSummation then multiply by 2:\n\t\tSingle: %f\n\t\tDouble: %.20lf\n",
               list[i],
               answerInSinglePrecisionMultiplyPlus[i],
               answerInDoublePrecisionMultiplyPlus[i],
               answerInSinglePrecisionPlusMultiply[i],
               answerInDoublePrecisionPlusMultiply[i]);
    }

    // Find the maximum computed value among all summation results
    double bestAnswerCalculated = 0;
    int index = 0;
    char where[31]; // Stores the method used to calculate the best answer
    for (int i = 0; i < size; i++)
    {
        // Check and update best answer for "Double Precision Multiply Plus" method
        if (answerInDoublePrecisionMultiplyPlus[i] > bestAnswerCalculated)
        {
            bestAnswerCalculated = answerInDoublePrecisionMultiplyPlus[i];
            index = i;
            strcpy(where, "Double Precision Multiply Plus");
        }
    }
    for (int i = 0; i < size; i++)
    {
        // Check and update best answer for "Double Precision Plus Multiply" method
        if (answerInDoublePrecisionPlusMultiply[i] > bestAnswerCalculated)
        {
            bestAnswerCalculated = answerInDoublePrecisionPlusMultiply[i];
            index = i;
            strcpy(where, "Double Precision Plus Multiply");
        }
    }
    for (int i = 0; i < size; i++)
    {
        // Check and update best answer for "Single Precision Multiply Plus" method
        if (answerInSinglePrecisionMultiplyPlus[i] > bestAnswerCalculated)
        {
            bestAnswerCalculated = answerInSinglePrecisionMultiplyPlus[i];
            index = i;
            strcpy(where, "Single Precision Multiply Plus");
        }
    }
    for (int i = 0; i < size; i++)
    {
        // Check and update best answer for "Single Precision Plus Multiply" method
        if (answerInSinglePrecisionPlusMultiply[i] > bestAnswerCalculated)
        {
            bestAnswerCalculated = answerInSinglePrecisionPlusMultiply[i];
            index = i;
            strcpy(where, "Single Precision Plus Multiply");
        }
    }

    // Identify the largest series length in the 'list' array
    int maxN = 0;
    for (int i = 0; i < size; i++)
    {
        if (list[i] > maxN)
        {
            maxN = list[i];
        }
    }

    // Output the best computed answer, method used, corresponding N, and the maximum N value
    printf("Theoretical Answer: %.4lf * (1 + 10000 / 9) ~ 1113.2232\nBest Answer that has been calculated: %.10lf\n\tThis answer was calculated on %s.\nN of Best Answer: %d\nMaximum of N: %d\n",
           MULTIPLY, bestAnswerCalculated, where, list[index], maxN);

    return 0;
}
