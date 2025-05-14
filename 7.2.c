#include <stdio.h>      // Standard input-output library
#include <string.h>     // String manipulation functions
#include <ctype.h>      // Character type functions like tolower()

#define MAX_CHAR 256    // Define maximum character array size

int main() {
    char str[MAX_CHAR], trs[MAX_CHAR]; // Arrays for input and reversed string

    puts("Your text: ");               // Prompt user input
    fgets(str, sizeof(str), stdin);    // Read input including spaces

    size_t n = 0;

    // Convert input to lowercase and remove newline character
    while (str[n] != '\0') {           
        if (str[n] ==  '\n' ) {       
            str[n] = '\0';            // Replace newline with null terminator
        }
        else {
            str[n] = tolower((unsigned char) str[n]); // Convert to lowercase
            ++n;                      // Increment index
        }
    }

    trs[n] = '\0'; // Ensure reversed string is properly null-terminated

    // Reverse the string
    for (size_t i = 0; n-- != 0; i++) {
        trs[n] = str[i];  // Store reversed version in trs
    }

    // Compare original and reversed strings
    if (strcmp(str, trs) == 0) {  
        puts("YES");  // If palindrome, print YES
    }
    else {
        puts("NO");   // Otherwise, print NO
    }

    return 0; // End program
}
//creater: https://stackoverflow.com/questions/65601607/c-reverse-string-comparison-palindrome
