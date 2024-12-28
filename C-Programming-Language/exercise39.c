#include <stdio.h>

void itob(int n, char s[], int b) {
    int i = 0;
    int sign = n;
    
    // Handle negative numbers for base-10, and base 16 if needed
    if (n < 0) {
        sign = -n;
        s[i++] = '-';
    }

    // Convert the number to the string
    do {
        int digit = sign % b;
        s[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';  // Use 'a' for digits 10-15
        sign /= b;
    } while (sign > 0);

    s[i] = '\0';

    // Reverse the string to get the correct order
    for (int j = 0; j < i / 2; j++) {
        char temp = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = temp;
    }
}

int main() {
    int n = 255;
    char s[50];
    itob(n, s, 16); // Hexadecimal
    printf("Hexadecimal result: %s\n", s);
    return 0;
}
