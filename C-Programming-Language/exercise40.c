#include <stdio.h>
#include <string.h>

void itoa_width(int n, char s[], int width) {
    int i = 0;
    int sign = n;
    
    // Handle negative numbers
    if (n < 0) {
        sign = -n;
        s[i++] = '-';
    }

    // Convert the number to the string
    do {
        s[i++] = sign % 10 + '0';
        sign /= 10;
    } while (sign > 0);

    s[i] = '\0';

    // Reverse the string to get the correct order
    for (int j = 0; j < i / 2; j++) {
        char temp = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = temp;
    }

    // Padding with spaces if necessary
    int len = strlen(s);
    if (len < width) {
        // Shift the string to the right to make space for padding
        for (int j = len; j >= 0; j--) {
            s[j + (width - len)] = s[j];
        }
        for (int j = 0; j < (width - len); j++) {
            s[j] = ' ';
        }
    }
}

int main() {
    int n = -42;
    char s[50];
    itoa_width(n, s, 10);  // Minimum width of 10
    printf("Padded result: '%s'\n", s);
    return 0;
}
