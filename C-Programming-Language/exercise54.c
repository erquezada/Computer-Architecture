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

// Function to get a floating-point number from input
int getfloat(float *pf) {
    int c, sign;
    float power;

    // Skip whitespace
    while (isspace(c = getch())) {
        ;
    }

    // Check for optional sign
    sign = (c == '-') ? -1 : (c == '+') ? 1 : 0;
    if (c == '-' || c == '+') {
        c = getch();
    }

    // Check if first character is a digit
    for (*pf = 0.0; isdigit(c); c = getch()) {
        *pf = *pf * 10.0 + (c - '0');
    }

    // Process the decimal point, if any
    if (c == '.') {
        c = getch();
        for (power = 1.0; isdigit(c); c = getch()) {
            *pf = *pf * 10.0 + (c - '0');
            power *= 10.0;
        }
        *pf /= power;
    }

    // Apply the sign
    *pf *= (sign == -1) ? -1 : 1;

    // Push back the non-digit character
    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

int main() {
    float x;
    printf("Enter a floating-point number: ");
    if (getfloat(&x)) {
        printf("You entered: %.2f\n", x);
    } else {
        printf("Invalid input\n");
    }
    return 0;
}
