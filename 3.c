#include <stdio.h>
#include <math.h>

int main()
{
    // Define small decimal values
    const int a = 1;
    const double b = pow(10, -1);
    const double c = pow(10, -1);
    const double d = pow(10, -5);
    const double e = pow(10, 5);
    const double f = pow(10, 0);

    // Compute the sum of a, b, and c in two different ways
    const double result1 = a + (b + c);
    const double result2 = (a + b) + c;

    // Compute the sum of d, e, and f in different orders
    const double result3 = d + e + f;
    const double result4 = d + f + e;
    const double result5 = e + d + f;
    const double result6 = e + f + d;
    const double result7 = f + d + e;
    const double result8 = f + e + d;

    // Print the results
    printf("a + (b + c) = %.20lf\n(a + b) + c = %.20lf\n", result1, result2);

    // Check if the sums are equal
    if (result1 == result2)
    {
        printf("a + (b + c) == (a + b) + c\nAddition is associative.\n");
    }
    else
    {
        printf("a + (b + c) != (a + b) + c\nAddition is not associative.\n");
    }

    printf("\n-------------------------\n\n");

    // Print the results with higher precision to show the difference
    printf("d + e + f = %.20lf\nd + f + e = %.20lf\ne + d + f = %.20lf\ne + f + d = %.20lf\nf + d + e = %.20lf\nf + e + d = %.20lf\n", result3, result4, result5, result6, result7, result8);

    // Check if any of the sums involving d, e, and f are equal
    if (result3 != result4 && result3 != result5 && result3 != result6 && result3 != result7 && result3 != result8 &&
        result4 != result5 && result4 != result6 && result4 != result7 && result4 != result8 &&
        result5 != result6 && result5 != result7 && result5 != result8 &&
        result6 != result7 && result6 != result8 &&
        result7 != result8)
    {
        printf("Addition is not commutative.\n");
    }
    else
    {
        printf("Addition is commutative.\n");
    }

    return 0;
}