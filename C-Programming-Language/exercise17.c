#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to remove trailing spaces and tabs from a line
void remove_trailing_whitespaces(char *line) {
    int length = strlen(line);
    int i;

    // Iterate backwards and remove trailing blanks or tabs
    for (i = length - 1; i >= 0 && (line[i] == ' ' || line[i] == '\t'); i--) {
        line[i] = '\0'; // Replace with null terminator
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    
    // Read each line until end of file (EOF)
    while (fgets(line, sizeof(line), stdin)) {
        // Remove trailing spaces and tabs
        remove_trailing_whitespaces(line);

        // Check if the line is not blank after trimming
        if (strlen(line) > 0) {
            printf("%s\n", line);  // Print the non-blank line
        }
    }

    return 0;
}
