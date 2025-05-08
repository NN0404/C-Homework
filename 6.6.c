#include <stdio.h>

// Function to compute GCD of two numbers using the Euclidean algorithm
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// Function to compute GCD for `n` numbers
int findGCD(int arr[], int n) {
    int result = arr[0];  // Start with the first number
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);  // Update GCD with each element
    }
    return result;
}

int main() {
    int n;

    // Ask the user how many numbers they want to input
    printf("Enter how many numbers: ");
    scanf("%d", &n);

    /*int arr[n];  // Create an array to store the numbers
    or doing memory allocation */
    int* arr = (int *)malloc( n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  // Exit program
    }

    // Get numbers from the user
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Compute and print the GCD
    printf("Greatest Common Divisor: %d\n", findGCD(arr, n));

    return 0;
}
