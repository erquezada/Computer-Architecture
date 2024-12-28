#include <stdio.h>
#include <ctype.h>
#include <math.h>
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

int getfloat(float *pf) {
    int c, sign;
    float power;

    while (isspace(c = getch()))  // Skip white space
        ;

    if (!isdigit(c) && c != '+' && c != '-' && c != '.') {  // Not a valid start
        ungetch(c);  // Push back non-valid character
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')  // Handle sign characters
        c = getch();

    *pf = 0.0;
    while (isdigit(c)) {  // Process digits before decimal point
        *pf = 10.0 * (*pf) + (c - '0');
        c = getch();
    }

    if (c == '.') {  // Process digits after decimal point
        c = getch();
        power = 1.0;
        while (isdigit(c)) {
            *pf = 10.0 * (*pf) + (c - '0');
            power *= 10.0;
            c = getch();
        }
        *pf /= power;  // Adjust for decimal place
    }

    if (c == 'e' || c == 'E') {  // Process exponent
        int exp_sign = 1;
        int exponent = 0;
        c = getch();
        if (c == '-') {
            exp_sign = -1;
            c = getch();
        } else if (c == '+')
            c = getch();
        while (isdigit(c)) {
            exponent = 10 * exponent + (c - '0');
            c = getch();
        }
        *pf *= (exp_sign == 1) ? pow(10, exponent) : pow(10, -exponent);
    }

    *pf *= sign;
    return c;
}

int main() {
    float x;
    while (getfloat(&x) != 0) {
        printf("Read float: %.4f\n", x);
    }
    return 0;
}
