#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void read_matrix(double **matrix, int rows, int cols) {
    puts("Enter the elements of the matrix: ");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
        printf("\n");
    }
}

void write_matrix(double **matrix, int rows, int cols) {
    puts("Your matrix: ");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            printf("%.0lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);


double **matrix = (double **)malloc((rows + 1) * sizeof(double *));
    if (matrix == NULL) {
        puts("Memory allocation error");
        return EXIT_FAILURE;
    }
    for (int i = 1; i <= rows; i++) {
        matrix[i] = (double *)malloc((cols + 1) * sizeof(double));
        if (matrix[i] == NULL) {
            puts("Memory allocation error");
            return EXIT_FAILURE;
        }
    }

    read_matrix(matrix, rows, cols);

    write_matrix(matrix, rows, cols);

    for (int i = 1; i <= rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
