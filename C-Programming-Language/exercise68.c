#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 1000

void tail(FILE *file, int n) {
    char *lines[MAX_LINES];
    int line_count = 0;

    // Read lines into memory
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        if (line_count < MAX_LINES) {
            lines[line_count] = strdup(buffer);
        } else {
            free(lines[line_count % MAX_LINES]);
            lines[line_count % MAX_LINES] = strdup(buffer);
        }
        line_count++;
    }

    // Print the last n lines
    int start = line_count < n ? 0 : (line_count % MAX_LINES);
    for (int i = start; i < line_count && i < start + n; i++) {
        printf("%s", lines[i % MAX_LINES]);
    }
}

int main(int argc, char *argv[]) {
    int n = 10;  // Default number of lines
    if (argc > 1) {
        n = atoi(argv[1]);
    }

    tail(stdin, n);
    return 0;
}
