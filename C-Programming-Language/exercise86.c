#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void compare_files(FILE *file1, FILE *file2) {
    char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
    int line_num = 1;

    // Read lines from both files
    while (fgets(line1, MAX_LINE_LENGTH, file1) != NULL &&
           fgets(line2, MAX_LINE_LENGTH, file2) != NULL) {
        if (strcmp(line1, line2) != 0) {  // If lines differ
            printf("First difference at line %d:\n", line_num);
            printf("File 1: %s", line1);
            printf("File 2: %s", line2);
            return;
        }
        line_num++;
    }

    // If one file has more lines, print the difference
    if (fgets(line1, MAX_LINE_LENGTH, file1) != NULL) {
        printf("File 1 has extra line %d: %s", line_num, line1);
    }
    if (fgets(line2, MAX_LINE_LENGTH, file2) != NULL) {
        printf("File 2 has extra line %d: %s", line_num, line2);
    }

    printf("No differences found.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");

    if (file1 == NULL) {
        perror("Error opening file1");
        return 1;
    }

    if (file2 == NULL) {
        perror("Error opening file2");
        fclose(file1);
        return 1;
    }

    compare_files(file1, file2);

    fclose(file1);
    fclose(file2);

    return 0;
}
