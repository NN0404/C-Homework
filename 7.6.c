#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    char line[256];

    puts("Enter the string:");
    if (fgets(line, sizeof(line), stdin))
        {
        // Remove trailing newline, if present
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
    }

    puts("Enter the nth number for removal:");
    scanf("%d", &n);

    int i = 0, space_count = 0, start = 0;
    puts("the string modified:");
    while (line[i] != '\0') {
        if (isspace(line[i])) {
            space_count++;
            if (space_count == n - 1) //cause we start from 0
                {
                while (line[i] != '\0' && !isspace(line[i])) {
                    i++;
//!isspace(line[i]):failed | find the nth-1 space, it skipped the word (i++) until the next space is found
//next space found then it become fails with the !isspace, loop exits
                }
            }
            else {
                putchar(line[i]); //print the other
            }
        }
        else if (space_count != n - 1) {
                putchar(line[i]); //not print the nth word
            }
            i++;
    }
    return 0;
}
