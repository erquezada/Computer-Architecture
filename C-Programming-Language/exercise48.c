#include <stdio.h>

int buf = EOF; // One character pushback buffer

// Get a character from input or the pushback buffer
int getch(void) {
    int c = (buf != EOF) ? buf : getchar();
    buf = EOF;  // Reset the buffer after retrieving the character
    return c;
}

// Push a character back into the buffer if it's not already full
void ungetch(int c) {
    if (buf == EOF) {
        buf = c;
    } else {
        printf("ungetch: too many characters\n");
    }
}

int main() {
    // Testing the pushback functionality
    char c;
    printf("Enter a character: ");
    c = getch();  // Get a character
    printf("You entered: %c\n", c);

    // Push the character back into the buffer
    ungetch(c);

    // Now retrieve the character again
    c = getch();
    printf("Character after ungetch: %c\n", c);

    return 0;
}
