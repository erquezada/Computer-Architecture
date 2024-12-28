#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

// Static variable to hold the last character read
static int last_char = EOF;

// Function to get the next operator or operand
int getop(char s[]) {
    int i = 0;
    int c;

    // Check if there's a stored character from the last call
    if (last_char != EOF) {
        c = last_char;
        last_char = EOF;  // Clear the stored character after using it
    } else {
        c = getchar();  // Otherwise, read a new character
    }

    // Skip any whitespace characters
    while (isspace(c)) {
        c = getchar();
    }

    // If the character is a digit, it's part of a number
    if (isdigit(c)) {
        // Save the digit into the string
        while (isdigit(s[i] = c)) {
            i++;
            c = getchar();
        }
        s[i] = '\0';  // Null-terminate the string
        if (c != EOF) {
            last_char = c;  // If we stopped on a non-digit, store it for later
        }
        return '0';  // Indicate it's a number
    }

    // If it's an operator, just return it
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return c;
    }

    // Return EOF if there's no valid input
    return c;
}

// Example main function to test getop
int main() {
    char s[MAXLINE];
    int type;

    while ((type = getop(s)) != EOF) {
        if (type == '0') {
            printf("Operand: %s\n", s);
        } else {
            printf("Operator: %c\n", type);
        }
    }

    return 0;
}
