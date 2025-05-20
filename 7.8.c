#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_LEN 100

void blockSort(char *arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main () {
    char *words[MAX_WORDS]; int n;

    puts("How many words you want:");
    scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        words[i] = (char *) malloc(MAX_LEN * sizeof(char));
        scanf("%s\n",words[i]);
    }

    blockSort(words, n);

    puts("Sorted words:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n",words[i]);
        free(words[i]);
    }
    return 0;
}
