#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// Defines the minimum value for generated series lengths and the range for random values
#define MIN_N 10000
#define RANGE_N 10000

// Function to calculate individual terms in the series: each term is computed as (1.0009)^(-x)
double series(int x)
{
    return pow(pow(1.0009, x), -1);
}

int main()
{
    // Prompt user to specify the number of calculations (i.e., size of arrays)
    printf("Please type the times that you want the series to be calculated!\n");
    int size;
    scanf("%d", &size); // Read user input to set the number of series calculations

    // Arrays to store results of summations in both single and double precision
    float answerInSinglePrecisionLeftToRight[size];
    float answerInSinglePrecisionRightToLeft[size];
    double answerInDoublePrecisionLeftToRight[size];
    double answerInDoublePrecisionRightToLeft[size];
    int list[size]; // Array to store randomly generated series lengths for each calculation

    // Initialize the random number generator with the current time for unique random values
    srand(time(NULL));

    // Populate the 'list' array with random series lengths between MIN_N and MIN_N + RANGE_N
    for (int i = 0; i < size; i++)
    {
        list[i] = rand() % RANGE_N + MIN_N;
    }

    // Compute the series summation for each generated series length in 'list'
    for (int i = 0; i < size; i++)
    {
        // Initialize summation values for left-to-right addition
        answerInSinglePrecisionLeftToRight[i] = 0;
        answerInDoublePrecisionLeftToRight[i] = 0;

        // Perform left-to-right summation for both single and double precision
        for (int j = 0; j < list[i]; j++)
        {
            answerInSinglePrecisionLeftToRight[i] += series(j);    // Single precision
            answerInDoublePrecisionLeftToRight[i] += series(j);    // Double precision
        }

        // Initialize summation values for right-to-left addition
        answerInSinglePrecisionRightToLeft[i] = 0;
        answerInDoublePrecisionRightToLeft[i] = 0;

        // Perform right-to-left summation for both single and double precision
        for (int j = list[i] - 1; j >= 0; j--)
        {
            answerInSinglePrecisionRightToLeft[i] += series(j);    // Single precision
            answerInDoublePrecisionRightToLeft[i] += series(j);    // Double precision
        }
    }

    // Output results, comparing the different summation orders and precisions for each N in 'list'
    for (int i = 0; i < size; i++)
    {
        printf("N: %d\n\tLeft To Right:\n\t\tSingle: %f\n\t\tDouble: %lf\n\t\tDifference: %lf\n\tRight To Left:\n\t\tSingle: %f\n\t\tDouble: %lf\n\t\tDifference: %lf\n\tBest Answer: %lf\n",
               list[i],
               answerInSinglePrecisionLeftToRight[i],
               answerInDoublePrecisionLeftToRight[i],
               answerInDoublePrecisionLeftToRight[i] - answerInSinglePrecisionLeftToRight[i],
               answerInSinglePrecisionRightToLeft[i],
               answerInDoublePrecisionRightToLeft[i],
               answerInDoublePrecisionRightToLeft[i] - answerInSinglePrecisionRightToLeft[i],
               answerInDoublePrecisionLeftToRight[i]);
    }

    // Find the maximum value computed in double precision (left-to-right) and its corresponding N
    double bestAnswerCalculated = 0;
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (answerInDoublePrecisionLeftToRight[i] > bestAnswerCalculated)
        {
            bestAnswerCalculated = answerInDoublePrecisionLeftToRight[i];
            index = i;
        }
    }

    // Identify the largest series length N in the 'list' array
    int maxN = 0;
    for (int i = 0; i < size; i++)
    {
        if (list[i] > maxN)
        {
            maxN = list[i];
        }
    }

    // Output the calculated best answer, the corresponding N, and the maximum N value
    printf("Theoretical Answer: 1 + 10000 / 9 ~ 1112.111111\nBest Answer that has been calculated: %lf\nN of Best Answer: %d\nMaximum of N: %d\n", 
           bestAnswerCalculated, list[index], maxN);

    return 0;
}
