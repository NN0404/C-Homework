#include <stdio.h>
#include <stdlib.h>

main() {

int n;
    puts("Nhap n phan tu: ");
    scanf("%hd", &n);

    short *a = (short*)malloc(n * sizeof(short));
    if (a == NULL) {
        puts("Memory could not be allocated");
        return 1;
    }

    printf("Enter %hd numbers:\n", n);
    for (short i = 0; i < n; i++) {
        scanf("%hd", &a[i]); // Input values into the dynamically allocated array
    }

    printf("You entered:\n");
    for (short i = 0; i < n; i++) {
        printf("%hd ", a[i]);
        printf("%p ", (void *)&a[i]);
        // Print the values
    }

    free(a); // Free allocated memory to avoid memory leaks
    return 0;

}
