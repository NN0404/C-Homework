#include <stdio.h>
#include <stdlib.h>

void td(float *diemtk, float tx, float gk, float ck) {
    *diemtk = 0.2 * tx + 0.2 * gk + 0.6 * ck;
}


int main() {
    int n,i;

    puts("how many students: ");
    scanf("%d",&n);

//memory
    float **arr = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        arr[i] = (float *)malloc(3 * sizeof(float));
    }

    puts("Enter numbers (tx, gk, ck): ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%f",&arr[i][j]);
        }
    }

    puts("Final result: ");
    float diemtk;
    for (int i = 0; i < n; i++) {
            td (&diemtk, arr[i][0], arr[i][1], arr[i][2]);
            printf ("%.2f\n", diemtk);
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}


