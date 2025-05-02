#include <stdio.h>

int main() {
    int n, pos;
    int arr[100];

    // Input size
    puts("Enter how many number: ");
    scanf("%d", &n);

    // Input array
    puts("Enter elements:");
    for (int i = 0; i < n; i++) {

        scanf("%d", &arr[i]);
    }

    // Input position to delete (1-based index)
    puts("Enter position to delete: ");
    scanf("%d", &pos);

    // Delete the element at position (convert to 0-based)
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--; // decrease array size

    // Output result
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
