#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1 ; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int n;

    puts("Enter size: ");
    scanf("%d", &n);

int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        puts("Memory allocation error");
        return EXIT_FAILURE;
    }

    puts("Enter array elements:");
    for (int i = 0; i< n; i++) {
        scanf("%d", &arr[i]);
    }

    // sort
    sort(arr, n);

    //output sorted
    puts("Sorted array:");
    for (int i = 0; i< n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
