#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void range(int upper, int lower, int *value) {
     *value = rand() % (upper - lower + 1) + lower;
}

int main() {
    int upper, lower, value;

    puts("Lower value: "); scanf("%d", &lower);
    puts("Upper value: "); scanf("%d", &upper);
srand(time(NULL));
range (upper, lower, &value);
    printf("value: %d\n", value);
    return 0;
}


//6.3.1.c
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void range(int upper, int lower, int *value) {
     *value = rand() % (upper - lower + 1) + lower;
}
int main() {
    int upper, lower, value,n;
    puts("Lower value: "); scanf("%d", &lower);
    puts("Upper value: "); scanf("%d", &upper);

    srand(time(NULL));
    puts("Number of elements: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        range (upper, lower, &value);
    printf("value: %d\n", value);
    }
    return 0;
}
*/

//6.3.2.c
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void range(float upper, float lower, float *value) {
     *value = lower + ((float)rand() / RAND_MAX) * (upper - lower);
}

int main() {
   float upper, lower;
float value;
    puts("Lower value: "); scanf("%f", &lower);
    puts("Upper value: "); scanf("%f", &upper);

    srand(time(NULL));
        range (upper, lower, &value);
    printf("value: %.2f\n", value);
    return 0;
}
*/
