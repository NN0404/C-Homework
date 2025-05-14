#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256 // a - z while 256 is all ascii character
int main() {
    char str[256], trs[256];


    puts("Your text: ");
    fgets(str, sizeof(str), stdin);

    size_t n = 0;

    while (str[n] != '\0') {
        if (str[n] ==  '\n' ) {
            str[n] = '\0';
        }
        else {
            str[n] = tolower((unsigned char) str[n]);
            ++n;
        }
    }

    trs[n] = '\0';

    for (size_t i = 0; n-- != 0; i++) {
        trs[n] = str[i];
    }

    if ( strcmp(str, trs) == 0 )
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }


    return 0;
}
