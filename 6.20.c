#include <stdio.h>

// Recursive function for exponentiation
int power(int x, int n) {
    if (n == 0) return 1; // Base case: x^0 = 1

    if (n % 2 == 0) {
        int half = power(x, n / 2);  // Recursive call
        return half * half;          // x^n = (x^(n/2)) * (x^(n/2))
    } else {
        int half = power(x, (n - 1) / 2);  // Recursive call
        return half * half * x;           // x^n = (x^((n-1)/2)) * (x^((n-1)/2)) * x
    }
}

int main() {
    int x, n;

    puts("Enter base (x): ");
    scanf("%d", &x);

    puts("Enter exponent (n): ");
    scanf("%d", &n);

    int result = power(x, n); // Recursive stack-based calculation
    printf("%d^%d = %d\n", x, n, result);

    return 0;
}
