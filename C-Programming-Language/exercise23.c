#include <stdio.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000

// Function to check if we are inside a string or a character constant
bool inside_string_or_char(const char *code, int index) {
    bool in_string = false; // Flag for string literals
    bool in_char = false;   // Flag for character constants
    for (int i = 0; i <= index; i++) {
        if (code[i] == '"' && (i == 0 || code[i - 1] != '\\')) {
            in_string = !in_string; // Toggle in_string flag
        }
        if (code[i] == '\'' && (i == 0 || code[i - 1] != '\\')) {
            in_char = !in_char; // Toggle in_char flag
        }
    }
    return in_string || in_char;
}

// Function to remove comments from a C program
void remove_comments() {
    char c;
    char prev_char = '\0';
    bool in_block_comment = false;
    bool in_line_comment = false;

    while ((c = getchar()) != EOF) {
        // Check if we are in a block comment
        if (in_block_comment) {
            if (prev_char == '*' && c == '/') {
                in_block_comment = false; // End of block comment
            }
        }
        // Check if we are in a line comment
        else if (in_line_comment) {
            if (c == '\n') {
                in_line_comment = false; // End of line comment
                putchar(c);  // Print newline
            }
        }
        // Detect the start of a comment or string
        else if (prev_char == '/' && c == '/') {
            in_line_comment = true;  // Start of line comment
        } else if (prev_char == '/' && c == '*') {
            in_block_comment = true;  // Start of block comment
        } else if (!inside_string_or_char(&prev_char, 1)) {
            putchar(prev_char);  // Print non-comment characters
        }

        // Move to the next character
        prev_char = c;
    }
}

int main() {
    remove_comments();
    return 0;
}
