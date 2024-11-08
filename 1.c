#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// Defines the minimum value for generated list elements and the range of random values
#define MIN_N 10000
#define RANGE_N 10000

// Function to calculate terms in a series, where each term is computed as (1.0009)^(-x)
double series(int x)
{
    return pow(pow(1.0009, x), -1);
}

int main()
{
    // Prompt user to enter the number of series calculations
    printf("Please type the times that u want the series to be calculated!\n");
    int size;
    scanf("%d", &size); // Read the number of calculations (size) from user input

    // Arrays to store results of the series summations
    float answerInSinglePrecisionLeftToRight[size];
    float answerInSinglePrecisionRightToLeft[size];
    double answerInDoublePrecisionLeftToRight[size];
    double answerInDoublePrecisionRightToLeft[size];
    int list[size]; // Array to store the randomly generated series lengths

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Fill the list array with random numbers between MIN_N and MIN_N + RANGE_N
    for (int i = 0; i < size; i++)
    {
        list[i] = rand() % RANGE_N + MIN_N;
    }

    // Compute the series summation for each generated N, both left-to-right and right-to-left
    for (int i = 0; i < size; i++)
    {
        answerInSinglePrecisionLeftToRight[i] = 0;
        answerInDoublePrecisionLeftToRight[i] = 0;

        // Left-to-right summation for both single and double precision
        for (int j = 0; j < list[i]; j++)
        {
            answerInSinglePrecisionLeftToRight[i] += series(j);
            answerInDoublePrecisionLeftToRight[i] += series(j);
        }

        answerInSinglePrecisionRightToLeft[i] = 0;
        answerInDoublePrecisionRightToLeft[i] = 0;

        // Right-to-left summation for both single and double precision
        for (int j = list[i] - 1; j >= 0; j--)
        {
            answerInSinglePrecisionRightToLeft[i] += series(j);
            answerInDoublePrecisionRightToLeft[i] += series(j);
        }
    }

    // Output the results for each N in list
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

    int maxN = 0;
    for (int i = 0; i < size; i++)
    {
        if (list[i] > maxN)
        {
            maxN = list[i];
        }
    }

    printf("Real Answer: 1 + 10000 / 9 ~ 1112.111111\nBest Answer that has been calculated: %lf\nN of Best Answer: %d\nMaximum of N: %d\n", bestAnswerCalculated, list[index], maxN);

    return 0;
}
