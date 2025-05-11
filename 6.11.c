#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to check if matrix multiplication is possible
int can_multiply(int rowsA, int colsA, int rowsB, int colsB) {
    return (colsA == rowsB) ? 1 : 0;

    // Returns 1 if valid, 0 otherwise
}

// Function to multiply matrices A and B, storing the result in matrix C
void multiply_matrices(int **A, int **B, int **C, int rowsA, int colsA, int colsB) {
    for (int i = 1; i <= rowsA; i++) {
        for (int j = 1; j <= colsB; j++) {
            C[i][j] = 0;
            for (int k = 1; k <= colsA; k++) {
                C[i][j] += A[i][k] * B[k][j]; // Matrix multiplication formula
            }
        }
    }
}

// Function to allocate a matrix dynamically
int **allocate_matrix(int rows, int cols) {
    int **matrix = (int **)malloc((rows + 1) * sizeof(int *));
    if (matrix == NULL) return NULL;

    for (int i = 1; i <= rows; i++) {
        matrix[i] = (int *)malloc((cols + 1) * sizeof(int));
        if (matrix[i] == NULL) return NULL;
    }
    return matrix;
}

// Function to free matrix memory
void free_matrix(int **matrix, int rows) {
    if (matrix == NULL) return;
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to read matrix from user input
void read_matrix(int **matrix, int rows, int cols, char name) {
    printf("Enter values for Matrix %c (%d x %d):\n", name, rows, cols);
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            printf("%c[%d][%d] = ", name, i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print matrix
void print_matrix(int **matrix, int rows, int cols, char name) {
    //printf("Matrix %c:\n", name);
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n"); // Move to next row
    }
}



int main() {
    int rowsA, colsA, rowsB, colsB, flag = 1;
    puts("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &rowsA, &colsA);


    puts("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    // Check if multiplication is possible
    flag = can_multiply(rowsA, colsA, rowsB, colsB);
    if (flag == 0) {
        printf("0\n");
        return 1;
    }

    // Allocate matrices
    int **A = allocate_matrix(rowsA, colsA);
    int **B = allocate_matrix(rowsB, colsB);
    int **C = allocate_matrix(rowsA, colsB); // Result matrix

    // Read matrices from user
    read_matrix(A, rowsA, colsA, 'A');
    read_matrix(B, rowsB, colsB, 'B');

    // Multiply matrices
    multiply_matrices(A, B, C, rowsA, colsA, colsB);

    printf("%d\n", flag);

    // Print matrices
    /* print_matrix(A, rowsA, colsA, 'A');
    print_matrix(B, rowsB, colsB, 'B'); */
    print_matrix(C, rowsA, colsB, 'C'); // Result matrix

    // Free allocated memory
    free_matrix(A, rowsA);
    free_matrix(B, rowsB);
    free_matrix(C, rowsA);

    return 0;
}
