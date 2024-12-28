#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 80  // Maximum line length before wrapping

// Function to print a character in a readable form
void print_char(char c) {
    if (isprint(c)) {
        putchar(c);  // Print graphic characters as they are
    } else {
        // Print non-graphic characters in octal
        printf("\\%03o", (unsigned char)c);
    }
}

// Function to break long lines and print input sensibly
void process_input() {
    int c;
    int line_length = 0;  // Counter for the current line length

    while ((c = getchar()) != EOF) {
        // If we exceed the maximum line length, break the line
        if (line_length >= MAX_LINE_LENGTH) {
            putchar('\n');
            line_length = 0;  // Reset line length counter
        }

        // Print the character sensibly
        print_char(c);
        line_length++;
    }
}

int main() {
    process_input();  // Process and print the input
    return 0;
}
