#include <stdio.h>
#include <stdlib.h>

int main() {
    int m,n,i,j,p,q,k;



    puts("Matrix A!");
    puts("Enter the number of rows: ");
    scanf("%d", &m);
    puts("Enter the number of columns: ");
    scanf("%d", &n);

printf("\n");
    puts("Matrix B!");
    puts("Enter the number of rows: ");
    scanf("%d", &p);
    puts("Enter the number of columns: ");
    scanf("%d", &q);

    if (n != p) {
        puts("Matrix multiplication not possible (n must be equal to p).");
        return EXIT_FAILURE;
    }

    // Allocate memory AFTER reading values
    int *mata = (int *)malloc(m * n * sizeof(int));
    int *matb = (int *)malloc(p * q * sizeof(int));
    int *matc = (int *)malloc(m * q * sizeof(int));

    if (!mata || !matb || !matc) {
        puts("Memory allocation failed.");
        free(mata);
        free(matb);
        free(matc);
        return EXIT_FAILURE;
    }

    puts("Enter the elements of matrix A");
    for (i=1;i<=m;i++) {
        for (j=1;j<=n;j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", (mata + (i-1)*n + (j-1)));
        }
    }
    //

    puts("Enter the elements of matrix B");
    for (j=1;j<=p;j++) {
        for (k=1;k<=q;k++) {
            printf("matrix[%d][%d] = ", j,k);
            scanf("%d", (matb + (j-1)*q + (k-1)));
        }
    }
    //

    for (i=0; i<m*q;i++) {
        *(matc + i) = 0;
    }

    for (i=1;i<=m;i++) {
        for (k=1;k<=q;k++) {
            for (j=1;j<=n;j++) {
                if (n==p) {
                    //matrix[i][k] = mata[i][j] * matb[j][k];
                    *(matc + (i-1)*q + (k-1)) += *(mata + (i-1)*n + (j-1)) * *(matb + (j-1)*q + (k-1));
                }
            }
        }
    }


    puts("Matrix sum: ");
    for (i=1;i<=m;i++) {

        for (k=1;k<=q;k++) {

            printf("%d ", *(matc + (i-1)*q + (k-1)) );
        }
        printf("\n");
    }

    free(mata); free(matb); free(matc);
    return 0;
}
