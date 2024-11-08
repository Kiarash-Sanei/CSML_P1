# `1.c`

## Summary of Purpose

This program calculates and compares the summation of a series in single and double precision, both from left to right and right to left, for multiple randomly generated series lengths. It examines the difference between summation orders and precisions to reveal potential floating-point inaccuracies due to the order of operations and precision types.

## What does this code aim to reveal and what do you typically observe when running it?

### Precision Differences:

Double precision summations (using double) will generally yield more accurate results than single precision summations (using float) due to double precision’s higher bit-width, which reduces round-off errors.
The differences between single and double precision results (Difference) should be noticeable, especially for larger values of N.

### Summation Order:

Left-to-right summation and right-to-left summation may yield slightly different results, especially in single precision. This is because, in floating-point arithmetic, adding smaller terms to larger accumulated sums can lead to different rounding than adding larger terms first.
The discrepancy between left-to-right and right-to-left summations will be more pronounced in single precision, as it is more susceptible to round-off errors.
Identification of Maximum Sum and Largest N:

### Output:

The code also tracks the maximum computed result in double precision, left-to-right order, which should ideally approximate the expected theoretical value close to 1112.111111.

The program outputs both the maximum series length (N) found in the random list and the value of N that produced the highest calculated result. This helps verify that, for sufficiently large N, the results stabilize around the theoretical expectation.

Discrepancies from Theoretical Value will illustrate how the choice of precision and summation order affects the accuracy of results.

# `2.c`

## Code Description

This program aims to analyze precision loss in floating-point arithmetic by performing summations in both single and double precision until additional terms no longer affect the cumulative sum. The code computes terms in a series defined by the formula $1.0009^{-x}$. By observing the point at which adding further terms has no effect on the sum (due to the limitations of floating-point representation), we can understand the difference between single and double precision.

## Aim

The objective of this program is to:

### Determine the smallest value of $N$:

$N$ for which adding additional terms has no effect on the cumulative sum due to precision limitations in single and double precision.
Compare the summation results of single and double precision with the theoretical answer.
This analysis illustrates the limitations of floating-point arithmetic in representing very small incremental changes as values approach the machine's precision limits.

## Process

The program follows these steps:

### Series Term Calculation:

A helper function, series(int x), computes each term in the series.

### Single-Precision Summation:

The program initializes singlePrecision to store the cumulative sum in single precision (float type).
In a while loop, it iteratively adds terms from the series to singlePrecision.
For each term added, the program calculates the difference between the current sum and the previous sum.
If the difference is zero, it indicates that the precision of single-precision floating-point arithmetic has been exhausted, and further additions have no effect on the sum.
The program then prints the smallest value of $N$ where this precision limit is reached and displays the final sum in single precision.

### Double-Precision Summation:

The program reinitializes index and begins a similar process using doublePrecision (of double type).
Using a while loop, terms from the series are added to doublePrecision with the same precision loss detection method.
If the difference between the current and previous sum becomes zero, the program prints the smallest $N$ where double precision reaches its limit, along with the final double-precision sum.

### Comparison with Theoretical Answer:

The program displays the theoretical answer for the summation as a comparison. The theoretical value is approximately $1112.111111$.

## Results

The output includes:

- $N$ (index) for single precision and double precision where adding further terms no longer affects the cumulative sum.
- The final cumulative sum for both single and double precision.
- The theoretical answer for reference.

## Summary

This code effectively demonstrates how floating-point arithmetic in single and double precision can reach a point where further additions to a sum have no effect. This is due to the precision limitations inherent in floating-point formats, with single precision losing accuracy sooner than double precision. The results offer a practical understanding of precision limits, which is essential in numerical computing and scientific applications where floating-point operations are prevalent.

# `3.c`

## Code Description

This C program explores the effects of floating-point precision and summation order on the computed results of a mathematical series. By performing summations in multiple ways using both single and double precision, the program demonstrates how precision and the order of operations can yield different results. It uses randomized series lengths for each calculation, evaluates the sum with various methods, and identifies the maximum computed result among them.

## Aim

The main objectives are to:

Compare how different methods of summation—whether multiplying each term before summing or summing first and then multiplying—affect the final result.
Examine the impact of single (float) vs. double (double) precision in calculations.
Determine the highest computed result across all methods and configurations to assess the influence of summation order and precision on accuracy.

## Final Output:

The program displays the best-computed result, the method that produced it, the corresponding series length (N), and the maximum value of N among all generated series lengths.

## Result

### The final output provides insight into:

#### Precision and Summation Order Effects:

The results show how differences in precision (single vs. double) and summation order (multiply-then-sum vs. sum-then-multiply) influence the final summation values.

#### Best Computed Result Identification:

The program identifies the highest result across all summation methods, indicating which approach maximizes accuracy.

#### Comparison with Theoretical Value:

The computed results are compared with the theoretical approximation, highlighting discrepancies potentially due to floating-point precision or order of operations.

This exploration serves as a practical example of how computational approaches can affect outcomes in scientific calculations, with implications for accuracy and precision in numerical methods.
