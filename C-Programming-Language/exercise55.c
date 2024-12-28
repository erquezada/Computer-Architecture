#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];  // Buffer for ungetch
int bufp = 0;       // Next free position in buf

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()))  // Skip white space
        ;

    if (!isdigit(c) && c != '+' && c != '-') {  // Not a number
        ungetch(c);  // Push back non-number character
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')  // Handle sign characters
        c = getch();

    if (!isdigit(c)) {  // If there's no digit after sign
        ungetch(c);  // Push back the non-digit character
        return 0;
    }

    *pn = 0;
    while (isdigit(c)) {
        *pn = 10 * (*pn) + (c - '0');
        c = getch();
    }

    *pn *= sign;
    return c;
}

int main() {
    int x;
    while (getint(&x) != 0) {
        printf("Read integer: %d\n", x);
    }
    return 0;
}
