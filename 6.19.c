#include <stdio.h>
#include <stdlib.h>
/*
#define MAX_N 100 //limit for global array
int res[MAX_N]; //for global array
*/

//mine
/*
void fibonacci(int n, int *res) {
    res[0] = 1;
    res[1] = 1;
    for (int i = 2; i < n; i++) {
        res[i] = res[i - 1] + res[i - 2];
    }
}
*/

//for global array and stack
void fibonacci(int n) {
    int res[n];

    res[0] = 1;
    res[1] = 1;
    for (int i = 2; i < n; i++) {
        res[i] = res[i - 1] + res[i - 2];

    }
    printf("Fibonacci number: %d\n", res[n-1]);
}

int main() {
    int n;

    puts("Your number: ");
    scanf("%d", &n);

//heap memory
    /* int *res = malloc(sizeof(int) * n);
    fibonacci(n,res);
    for (int i =0; i < n; i++) {
        printf("%d ", res[i]);
    }
    free(res);  */

//global array mảng toàn cực

/*    if (n > MAX_N) {
        printf("Value too large! Increase MAX_N.\n");
        return 1;
    }
*/

    if (n > 1000) { // ✅ Prevent excessive stack usage
        printf("Value too large! Try a smaller number.\n");
        return 1;
    }

    fibonacci(n);

    // Print only the final answer (last element of the array) for global array

    return 0;
    
}
