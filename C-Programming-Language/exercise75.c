#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

int buf[BUFSIZE];  // Buffer for ungetch
int bufp = 0;      // Next free position in buf

// Function to push character back onto input
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

// Function to get a character from input
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// Function to get an integer from input
int getint(int *pn) {
    int c, sign;

    // Skip whitespace
    while (isspace(c = getch())) {
        ;
    }

    // Check for + or - sign
    sign = (c == '-') ? -1 : (c == '+') ? 1 : 0;

    // If a sign is found but no digits follow, return 0
    if (sign) {
        c = getch();  // Get the next character
        if (!isdigit(c)) {
            ungetch(c);  // Push the sign back if it's not followed by a digit
            return 0;
        }
    } else if (!isdigit(c)) {  // If the first character isn't a digit, it's invalid
        return 0;
    }

    // Accumulate the number
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = *pn * 10 + (c - '0');
    }

    // Apply the sign
    *pn *= sign;

    // Push back the non-digit character
    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

int main() {
    int x;
    printf("Enter an integer: ");
    if (getint(&x)) {
        printf("You entered: %d\n", x);
    } else {
        printf("Invalid input\n");
    }
    return 0;
}
