#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Function to compute each term in the series as (1.0009)^(-x)
double series(int x)
{
    // This function returns a single term in the series based on the given index 'x'
    // The term is computed as the reciprocal of (1.0009)^x
    return pow(pow(1.0009, x), -1);
}

int main()
{
    // Initialize variables for single-precision summation
    float singlePrecision = 0; // Stores the cumulative sum in single precision
    int index = 0; // Index for each term in the series
    
    // Infinite loop to compute summation in single precision until precision loss is detected
    while (true)
    {
        float last = singlePrecision; // Store the current sum before adding the next term
        singlePrecision += series(index); // Add the next term in single precision

        // Calculate the absolute difference between the current and previous sum
        float difference = fabs(singlePrecision - last);
        
        // Check if the difference is zero, indicating precision loss
        if (difference == 0)
        {
            printf("For Single Precision, N = %d is the least N for hitting the limit.\n", index);
            printf("Single Precision Sum: %f\n", singlePrecision);
            break; // Stop further additions for this series in single precision
        }
        
        index++; // Move to the next term in the series
    }

    // Initialize variables for double-precision summation
    double doublePrecision = 0; // Stores the cumulative sum in double precision
    index = 0; // Reset the index for double precision summation
    
    // Infinite loop to compute summation in double precision until precision loss is detected
    while (true)
    {
        double last = doublePrecision; // Store the current sum before adding the next term
        doublePrecision += series(index); // Add the next term in double precision

        // Calculate the absolute difference between the current and previous sum
        double difference = fabs(doublePrecision - last);
        
        // Check if the difference is zero, indicating precision loss
        if (difference == 0)
        {
            printf("For Double Precision, N = %d is the least N for hitting the limit.\n", index);
            printf("Double Precision Sum: %f\n", doublePrecision);
            break; // Stop further additions for this series in double precision
        }
        
        index++; // Move to the next term in the series
    }

    // Display the theoretical answer for comparison
    printf("Theoretical Answer: 1 + 10000 / 9 ~ 1112.111111\n");

    return 0;
}
