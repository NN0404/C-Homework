#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 26 // a - z while 256 is all ascii character
int main() {
    char str[100];
    int frequency[MAX_CHAR] = {0};
    int unique_count = 0;

    puts("Your text: ");
    scanf("%99s", str);

    int dem = strlen(str);

//convert and count occurrences
    for (int i = 0; i < dem; i++) {
        char ch = tolower(str[i]);
        if (isalpha(ch)) {
            if (frequency[ch - 'a'] == 0) {
                unique_count++;
            }
            frequency[ch - 'a']++;
        }
    }

    printf("%d\n", unique_count);
    //letter count
    for (int i = 0; i < MAX_CHAR; i++) {
        if (frequency[i] > 0) {
            printf("%c: %d\n", i + 'a', frequency[i]);
        }
    }
    return 0;
}
