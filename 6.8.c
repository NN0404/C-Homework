#include <stdio.h>
#include <math.h>

// Function to calculate ln(x) using Taylor series
double taylor_ln(double x, double error) {
    if (x <= 0) return NAN;  // Return NaN for invalid x values

    double term = (x - 1) / (x + 1);
    double sum = 0.0, power = term;
    int n = 1;

    while (fabs(power / n) > error) {  // Stop when error is small
        sum += power / n;
        power *= term * term;  // Compute the next power term
        n += 2;
    }

    return 2 * sum;
}

// Function to calculate e^x using Taylor series
double taylor_exp(double x, double error) {
    double sum = 1.0, term = 1.0;
    int n = 1;

    while (fabs(term) > error) {  // Stop when error is small
        term *= x / n;
        sum += term;
        n++;
    }

    return sum;
}

// Function to compute x^a using Taylor series
double taylor_pow(double x, double a, double error) {
    return taylor_exp(a * taylor_ln(x, error), error);
}

int main() {
    double x, a, error;

    // Get user input
    printf("Enter the base x: "); scanf("%lf", &x);
    printf("Enter the exponent a: "); scanf("%lf", &a);
    printf("Enter the allowed error: "); scanf("%lf", &error);

    // Compute x^a using Taylor series
    double result = taylor_pow(x, a, error);
    printf("x^a approximate %.6f\n", result);

    return 0;
}

//all this by copilot, i dont claim this :(
