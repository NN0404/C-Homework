#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

typedef struct {
    char name[MAX]; // Use fixed-size name instead of dynamic allocation
    int y;
    float g;
} Stu;

int main() {
    int a;
    char buffer[MAX];

    FILE *f = fopen("D:/untitle/cmake-build-debug/data_input.txt", "r");
    if (!f) return printf("Error: Can't find input file.\n"), 1;

    fscanf(f, "%d\n", &a);
    Stu *stu = malloc(a * sizeof(Stu));
    if (!stu) return printf("Error: Can't allocate memory.\n"), 1;

    for (int i = 0; i < a; i++) {
        fgets(buffer, MAX, f);
        sscanf(buffer, "%255[^\n] %d %f", stu[i].name, &stu[i].y, &stu[i].g);
    }
    fclose(f);

    FILE *p = fopen("D:/untitle/cmake-build-debug/data_output.txt", "w");
    if (!p) return printf("Error: Can't open output file.\n"), 1;

    fprintf(p, "%d\n", a);
    for (int i = 0; i < a; i++)
        fprintf(p, "%-25s %6d %8.2f\n", stu[i].name, stu[i].y, stu[i].g);

    fclose(p);
    free(stu);

    return 0;
}
