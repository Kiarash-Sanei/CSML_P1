# Summary of Purpose
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
