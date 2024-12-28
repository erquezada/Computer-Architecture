#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    char line[MAX_LINE_LENGTH];
    
    // Read each line until end of file (EOF)
    while (fgets(line, sizeof(line), stdin)) {
        // Check the length of the line (excluding the newline character)
        if (strlen(line) > 80) {
            printf("%s", line);
        }
    }

    return 0;
}
