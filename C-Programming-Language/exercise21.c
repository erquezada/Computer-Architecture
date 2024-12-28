#include <stdio.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000  // Maximum line length to process
#define FOLD_COLUMN 40       // Column at which to fold lines

// Function to fold long input lines
void fold_line(int fold_column) {
    int c;
    int column = 0;  // Track current column position
    char line[MAX_LINE_LENGTH];
    int line_length = 0;

    // Read the input line
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            // End of the current line
            if (line_length > 0) {
                // Process the line if it has content
                line[line_length] = '\0';  // Null-terminate the line
                fold_and_print(line, fold_column);
            }
            line_length = 0;  // Reset line length for the next line
        } else {
            if (line_length < MAX_LINE_LENGTH - 1) {
                line[line_length++] = c;  // Store the character in the buffer
            }
        }
    }

    // Process the last line if it doesn't end with a newline
    if (line_length > 0) {
        line[line_length] = '\0';  // Null-terminate the line
        fold_and_print(line, fold_column);
    }
}

// Function to fold the line and print
void fold_and_print(char *line, int fold_column) {
    int column = 0;
    int last_space = -1;  // Track the position of the last space or tab

    for (int i = 0; line[i] != '\0'; i++) {
        column++;
        
        if (line[i] == ' ' || line[i] == '\t') {
            last_space = i;  // Update last space position
        }
        
        // If the column exceeds fold_column, fold the line
        if (column > fold_column) {
            // If we found a space before the fold column, fold at that position
            if (last_space != -1) {
                line[last_space] = '\0';  // Cut the line at the last space
                printf("%s\n", line);     // Print the folded line
                // Move the rest of the line after the space to the start for the next fold
                memmove(line, &line[last_space + 1], strlen(&line[last_space + 1]) + 1);
            } else {
                // No space found before fold column, fold exactly at the column
                line[fold_column] = '\0';  // Cut the line at fold_column
                printf("%s\n", line);      // Print the folded line
                // Move the rest of the line to the start for the next fold
                memmove(line, &line[fold_column], strlen(&line[fold_column]) + 1);
            }
            column = 0;  // Reset column count for the next folded line
            last_space = -1;  // Reset last space position
        }
    }

    // Print any remaining part of the line that was not yet printed
    if (line[0] != '\0') {
        printf("%s\n", line);
    }
}

int main() {
    fold_line(FOLD_COLUMN);
    return 0;
}
