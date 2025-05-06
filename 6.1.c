#include <stdio.h>
#include <stdlib.h>

int findmax(int arr[], int size);

int main() {
    int n;

    puts("how many numbers: ");
    scanf("%d",&n);

    int arr[n];

    puts("Enter number: ");
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }

    int max = findmax(arr,n);
    printf("The maximum number is: %d\n",max);
    return 0;
}

int findmax(int arr[], int size) {
 int max = arr[0];

for (int i = 1; i< size ; i++) {
    if (arr[i] > max) {
        max = arr[i];
    }
}
return max;
}

