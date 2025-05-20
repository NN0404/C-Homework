#include <stdio.h>
#include <string.h>

int main () {
    char line[256];

    puts("Enter many lines of text:");
    if (fgets(line, sizeof(line), stdin) == NULL ){
        puts("Error in code");
    } else {

char *next = line;

        while ((next = strchr(next, '.')) != NULL) {
            if (*(next + 1) == ' ') { //to see if it true
                *(next + 1) = '\n'; //true then replace the . to .\n
            }
            next++; //next + 1 means the next character right after
        }
        printf("%s", line);
    }
    return 0;
}
