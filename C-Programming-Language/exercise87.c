#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void find_pattern(FILE *file, char *pattern, char *filename) {
    char line[MAX_LINE_LENGTH];
    int line_num = 1;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (strstr(line, pattern) != NULL) {
            if (filename) {
                printf("In file %s:\n", filename);
            }
            printf("Line %d: %s", line_num, line);
        }
        line_num++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <pattern> [file1 file2 ...]\n", argv[0]);
        return 1;
    }

    char *pattern = argv[1];

    if (argc == 2) {
        // No files, read from standard input
        find_pattern(stdin, pattern, NULL);
    } else {
        // Files provided as arguments
        for (int i = 2; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                perror("Error opening file");
                continue;
            }
            find_pattern(file, pattern, argv[i]);
            fclose(file);
        }
    }

    return 0;
}
