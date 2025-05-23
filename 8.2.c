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

        // Remove newline if present
        int len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
            len--;
        }

        // Find last space (before GPA)
        int last_space = -1;
        for (int j = len - 1; j >= 0; j--) {
            if (buffer[j] == ' ') {
                last_space = j;
                break;
            }
        }

        // Find second last space (before year)
        int second_last_space = -1;
        for (int j = last_space - 1; j >= 0; j--) {
            if (buffer[j] == ' ') {
                second_last_space = j;
                break;
            }
        }

        if (last_space == -1 || second_last_space == -1) continue;

        // Parse year and GPA
        sscanf(buffer + second_last_space + 1, "%d %f", &stu[i].y, &stu[i].g);

        // Extract name
        strncpy(stu[i].name, buffer, second_last_space);
        stu[i].name[second_last_space] = '\0';
    }

    fclose(f);

/*file pointer*/
    FILE *p = fopen("D:/untitle/cmake-build-debug/data_student_A.txt", "w");
    FILE *b = fopen("D:/untitle/cmake-build-debug/data_student_B.txt", "w");
    FILE *c = fopen("D:/untitle/cmake-build-debug/data_student_C.txt", "w");
    FILE *d = fopen("D:/untitle/cmake-build-debug/data_student_D.txt", "w");
    FILE *e = fopen("D:/untitle/cmake-build-debug/data_student_F.txt", "w");

    if (!p || !b || !c || !d || !e) return printf("Error: Can't open one or more output files.\n"), 1;

    // Count students in each grade category
    int count_A = 0, count_B = 0, count_C = 0, count_D = 0, count_F = 0;

    for (int i = 0; i < a; i++) {
        if (stu[i].g >= 8.5) count_A++;
        else if (stu[i].g >= 7.0) count_B++;
        else if (stu[i].g >= 5.5) count_C++;
        else if (stu[i].g >= 4.0) count_D++;
        else count_F++;
    }

    // Write student counts to each file
    fprintf(p, "%d\n", count_A);
    fprintf(b, "%d\n", count_B);
    fprintf(c, "%d\n", count_C);
    fprintf(d, "%d\n", count_D);
    fprintf(e, "%d\n", count_F);

    printf("Total Students: %d\n", a);

    for (int i = 0; i < a; i++) {
        printf("Processing: %s %d %.2f\n", stu[i].name, stu[i].y, stu[i].g); // Debugging line

        if (stu[i].g >= 8.5) {
            printf("Writing to A\n");  // Debug
            fprintf(p, "%-25s %6d %8.2f\n", stu[i].name, stu[i].y, stu[i].g);
        }  if (stu[i].g >= 7.0 && stu[i].g < 8.5) {
            printf("Writing to B\n");  // Debug
            fprintf(b, "%-25s %6d %8.2f\n", stu[i].name, stu[i].y, stu[i].g);

        }  if (stu[i].g >= 5.5 && stu[i].g < 7.0) {
            printf("Writing to C\n");  // Debug
            fprintf(c, "%-25s %6d %8.2f\n", stu[i].name, stu[i].y, stu[i].g);

        }  if (stu[i].g >= 4.0 && stu[i].g < 5.5) {
            printf("Writing to D\n");  // Debug
            fprintf(d, "%-25s %6d %8.2f\n", stu[i].name, stu[i].y, stu[i].g);

        } if (stu[i].g < 4.0){
            printf("Writing to F\n");  // Debug
            fprintf(e, "%-25s %6d %8.2f\n", stu[i].name, stu[i].y, stu[i].g);

        }
    }

    // Close files
    fclose(p);
    fclose(b);
    fclose(c);
    fclose(d);
    fclose(e);

    free(stu);

    return 0;
}
