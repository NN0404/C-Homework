#include <stdio.h>
#include <stdlib.h>

void dup(int arr[], int n, int *result) {
    for (int i = 0; i < n; i++) {
        result[2*i] = arr[i];
        result[2*i+1] = arr[i];
    }
}

int main() {
    int n;


    // Input size
    puts("Enter how many number: ");
    scanf("%d", &n);

    //Allocate memory
    int *arr = (int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        puts("Memory allocation error");
        return 1;
    }

   puts("Your number: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

   int *result = (int*)malloc(2*n*sizeof(int));
    if (result == NULL) {
        puts("Memory allocation error");
        return 1;
    }


dup(arr, n, result);

    // Output result
    for (int i = 0; i < 2*n; i++) {
        printf("%d ", result[i]);
    }
    
        free(arr);
        free(result);
    return 0;
}
