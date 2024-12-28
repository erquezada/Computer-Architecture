#include <stdio.h>
#include <string.h>

#define BUFSIZE 100  // Size of the buffer

static char buffer[BUFSIZE];  // Buffer to hold ungetch characters
static int buf_pos = 0;  // Position of the next character to be placed in buffer

// Push a character onto the input buffer
void ungetch(char c) {
    if (buf_pos >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buffer[buf_pos++] = c;
    }
}

// Push a string back into the input buffer in reverse order
void ungets(char s[]) {
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        ungetch(s[i]);
    }
}

// Function to simulate getch (getting character from the buffer or input)
char getch(void) {
    if (buf_pos > 0) {
        return buffer[--buf_pos];  // Return the last character pushed onto the buffer
    } else {
        return getchar();  // If the buffer is empty, get a character from standard input
    }
}

int main() {
    // Test ungets
    ungets("Hello");
    
    // Simulate reading from the input buffer
    char c;
    while ((c = getch()) != EOF) {
        putchar(c);  // Output the character to check if it was "un-gotten"
    }

    return 0;
}
