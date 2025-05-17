#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strndup(const char *s, size_t len)
{
    size_t nbytes = strnlen(s, len);
    char *result = malloc(nbytes + 1);
    if (result != NULL)
    {
        memmove(result, s, nbytes);
        result[nbytes] = '\0';
    }
    return result;
}

int main() {

    int words = 0;
    char **argv = NULL;

    char cmd[256];
    printf("Enter a string:\n");
    fgets(cmd, sizeof(cmd), stdin);

    //remove \n
    size_t len = strlen(cmd);
    if (len > 0 && cmd[len - 1] == '\n') {
        cmd[len - 1] = '\0';
    }

    int start = 0;
    for (size_t i = 0; i < len; i++) {
        if (cmd[i] == ' ' || cmd[i] == '\0') {
            argv = realloc(argv, (words + 1) * sizeof(char *));
            if (!argv) {
                puts("Memory allocation error");
                exit(1);
            }

            argv[words++] = strndup(cmd + start, i - start);
            start = i + 1;
        }
    }

    for(int i = 0; i < words; i++){
        printf("%s\n", argv[i]);
        free(argv[i]);
    }
    return 0;
}
