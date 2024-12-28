#include <stdio.h>

#define TAB_WIDTH 8  // Set tab stop every 8 columns

// Function to replace tabs with spaces
void detab() {
    int c;
    int column = 0;  // Keep track of current column position

    while ((c = getchar()) != EOF) {
        if (c == '\t') {  // Tab found
            int spaces_to_insert = TAB_WIDTH - (column % TAB_WIDTH);
            for (int i = 0; i < spaces_to_insert; i++) {
                putchar(' ');  // Insert spaces
            }
            column += spaces_to_insert;
        } else {
            putchar(c);  // Output normal character
            column++;
            if (c == '\n') {
                column = 0;  // Reset column on newline
            }
        }
    }
}

int main() {
    detab();
    return 0;
}
