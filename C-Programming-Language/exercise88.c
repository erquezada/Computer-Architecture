#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

void print_file(FILE *file, char *filename) {
    char line[MAX_LINE_LENGTH];
    static int page_count = 1;

    printf("\n===== %s =====\n", filename);  // Title with the file name

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (line == NULL || line[0] == '\0') {
            continue;
        }

        printf("%s", line);

        // Check if we need to start a new page
        if (ftell(file) > 50) { // Arbitrary page limit for the file
            printf("\f");  // Form feed character to start a new page
            page_count++;
            printf("Page %d\n", page_count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1 file2 ...>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            perror("Error opening file");
            continue;
        }
        print_file(file, argv[i]);
        fclose(file);
    }

    return 0;
}
