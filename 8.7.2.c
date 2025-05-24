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

    // Sort students by GPA in descending order (highest to lowest)
    for (int i = 0; i < a - 1; i++) {
        for (int j = 0; j < a - i - 1; j++) {
            if (stu[j].g < stu[j + 1].g) {
                // Swap students
                Stu temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }

    // Open single output file
    FILE *output = fopen("D:/untitle/cmake-build-debug/data_output_sorted.txt", "w");
    if (!output) return printf("Error: Can't open output file.\n"), 1;

    // Write number of students
    fprintf(output, "%d\n", a);

    printf("Total Students: %d\n", a);
    printf("Students sorted by GPA (descending order):\n");

    // Write all students to single output file in GPA ascending order
    for (int i = 0; i < a; i++) {
        fprintf(output, "%-25s %6d %8.2f\n", stu[i].name, stu[i].y, stu[i].g);
        printf("%-25s %6d %8.2f\n", stu[i].name, stu[i].y, stu[i].g);
    }

    // Close file
    fclose(output);
    free(stu);

    printf("\nAll students have been written to data_output_sorted.txt in descending GPA order.\n");

    return 0;
}
