#include <stdio.h>

#define TAB_WIDTH 8  // Set tab stop every 8 columns

// Function to replace strings of blanks with the minimum number of tabs and blanks
void entab() {
    int c;
    int space_count = 0;  // Count spaces in a row
    int column = 0;  // Track current column position

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            // Increment space count for consecutive spaces
            space_count++;
            column++;
        } else {
            // Output spaces and/or tabs if there were any spaces
            if (space_count > 0) {
                // First, try to insert tabs
                int tabs = space_count / TAB_WIDTH;
                int remaining_spaces = space_count % TAB_WIDTH;

                // Print the required number of tabs
                for (int i = 0; i < tabs; i++) {
                    putchar('\t');
                }

                // Print the remaining spaces to fill up to the tab stop
                for (int i = 0; i < remaining_spaces; i++) {
                    putchar(' ');
                }

                column += space_count;  // Update the column count
                space_count = 0;  // Reset space count
            }
            putchar(c);  // Output the current non-space character
            column++;

            if (c == '\n') {
                column = 0;  // Reset column on newline
            }
        }
    }
}

int main() {
    entab();
    return 0;
}
