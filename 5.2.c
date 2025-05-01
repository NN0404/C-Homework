#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
main() {

int m,n,i,j;

    puts("Nhap m row: ");
    scanf("%d", &m);

    puts("Nhap n column: ");
    scanf("%d", &n);

    int **a = (int**)malloc(m+1 * sizeof(int *));
    if (a == NULL) {
        puts("Memory could not be allocated");
        return 1;
    }

    for (i = 1; i <= m; i++) {
        a[i] = (int*)malloc(n+1 * sizeof(int));
        if (a[i] == NULL) {
            puts("Memory could not be allocated");
            return 1;
        }
    }

    for (i=1; i<=m; i++) {
        for (j=1; j<=n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("You entered:\n");
    for ( i = 1; i <= m; i++) {
        for ( j = 1; j <= n; j++) {
            printf("%d ", a[i][j]);

        // Print the values
        }
        printf("\n");
    }

    for ( i = 1; i <= m; i++) {
        for ( j = 1; j <= n; j++) {
            printf("%lu ", (uintptr_t) &a[i][j]);
            //printf("%p ", (void *) &a[i][j]);
            //need #include <stdint.h>
        }
        printf("\n");
    }


    for (i = 1; i <= m; i++) {
        free(a[i]);
    }
    free(a); // Free allocated memory to avoid memory leaks

    return 0;
}
