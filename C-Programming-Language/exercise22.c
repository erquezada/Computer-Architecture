#include <stdio.h>
#include <string.h>

#define FOLD_COLUMN 40  // Column width after unfolding

// Function to unfold short lines into longer ones
void unfold_line(int fold_column) {
    int c;
    char line[1000];   // Buffer for current line
    char output[1000]; // Buffer for unfolded output
    int line_length = 0;
    int output_length = 0;

    // Read lines one by one
    while (fgets(line, sizeof(line), stdin)) {
        line_length = strlen(line);
        
        // If the line has content and it's shorter than fold_column, combine it with output
        if (line_length < fold_column) {
            // If output has content, add a space to separate lines
            if (output_length > 0) {
                output[output_length++] = ' ';
            }
            // Append the current line to the output
            for (int i = 0; i < line_length; i++) {
                output[output_length++] = line[i];
            }
        } else {
            // If the line is long enough, output it as is
            if (output_length > 0) {
                // Print the accumulated output
                output[output_length] = '\0';
                printf("%s\n", output);
                output_length = 0;  // Reset the output buffer
            }
            // Print the current long line directly
            printf("%s", line);
        }
    }

    // Output any remaining text in the buffer
    if (output_length > 0) {
        output[output_length] = '\0';
        printf("%s\n", output);
    }
}

int main() {
    unfold_line(FOLD_COLUMN);
    return 0;
}
