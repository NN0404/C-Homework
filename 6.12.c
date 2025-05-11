#include <stdio.h>
#include <stdlib.h>



// Function to allocate memory for a 2D matrix
int **allocate_matrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        puts("Memory allocation error.");
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            puts("Memory allocation error.");
            return NULL;
        }
    }
    return matrix;
}

// Function to free a matrix
void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to read matrix values from user
void read_matrix(int **matrix, int rows, int cols) {
    puts("Enter matrix values:");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("matrix[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to swap two rows in a dynamically allocated matrix
void swap_rows(int **matrix, int row1, int row2) {
    int *temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;

    printf("Rows %d and %d have been swapped.\n", row1 + 1, row2 + 1);
}


// Function to print a matrix
void print_matrix(int **matrix, int rows, int cols) {
    puts("Matrix:");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}





int main() {
    int rows, cols;

    // Get matrix dimensions
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Allocate matrix dynamically
    int **matrix = allocate_matrix(rows, cols);
    if (matrix == NULL) {
        return EXIT_FAILURE;
    }

    // Read matrix values
    read_matrix(matrix, rows, cols);

    // Print original matrix
    print_matrix(matrix, rows, cols);

    // Ask user for rows to swap
    int row1, row2;
    printf("Enter two row indices to swap (1-based index): ");
    scanf("%d %d", &row1, &row2);

row1 -= 1;
    row2 -= 1;

    // Validate indices before swapping
    if (row1 >= 0 && row1 < rows && row2 >= 0 && row2 < rows && row1 != row2) {
        swap_rows(matrix, row1, row2);
        puts("Matrix after swapping rows:");
        print_matrix(matrix, rows, cols);
    } else {
        puts("Invalid row indices. No swap performed.");
    }

    // Free memory
    free_matrix(matrix, rows);

    return 0;
}
