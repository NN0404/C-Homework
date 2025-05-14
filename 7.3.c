#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate Fibonacci-like strings
char* fibonacci_string(int n) {
    // Base cases: return predefined strings for F(0) and F(1)
    if (n == 0) return strdup("A"); // F(0) = "A"
    if (n == 1) return strdup("B"); // F(1) = "B"

    // Allocate memory for previous Fibonacci strings
    char *prev1 = strdup("B"); // This holds F(n-1)
    char *prev2 = strdup("A"); // This holds F(n-2)
    char *temp; // Temporary string to store new Fibonacci value

    // Loop to build Fibonacci-like sequence up to F(n)
    for (int i = 2; i <= n; i++) {
        // Allocate exact memory needed for concatenation
        temp = malloc(strlen(prev1) + strlen(prev2) + 1);
        
        // Construct F(n) by concatenating F(n-1) + F(n-2)
        strcpy(temp, prev1);  // Copy F(n-1) into temp
        strcat(temp, prev2);  // Append F(n-2) to temp
        
        // Free old memory (prev2 is no longer needed)
        free(prev2);
        
        // Shift forward for next iteration
        prev2 = prev1; // Move F(n-1) down to F(n-2)
        prev1 = temp;  // Update F(n-1) to the newly created string
    }

    // Free unused memory from the loop
    free(prev2);

    // Return the final Fibonacci-like string
    return temp;
}

int main() {
    int n; // User-defined Fibonacci index
    printf("Enter Fibonacci position: ");
    scanf("%d", &n); // Read user input

    // Generate the Fibonacci-like string
    char *fibString = fibonacci_string(n);
    
    // Output the result
    printf("Fibonacci-based string at position %d: %s\n", n, fibString);

    // Free dynamically allocated memory to prevent memory
