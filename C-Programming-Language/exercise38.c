#include <stdio.h>
#include <limits.h>

void itoa(int n, char s[]) {
    int i = 0;
    int sign = n;
    
    // Handle the edge case of the smallest negative number
    if (n == INT_MIN) {
        s[i++] = '-';
        n = -(n + 1); // Take the positive value of n, adjusting for the overflow
    } else if (n < 0) {
        sign = -n;
        s[i++] = '-';
    }

    // Convert the number to a string
    do {
        s[i++] = sign % 10 + '0';
        sign /= 10;
    } while (sign > 0);

    s[i] = '\0';

    // Reverse the string
    for (int j = 0; j < i / 2; j++) {
        char temp = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = temp;
    }
}

int main() {
    int n = INT_MIN;
    char s[50];
    itoa(n, s);
    printf("itoa result: %s\n", s);
    return 0;
}
