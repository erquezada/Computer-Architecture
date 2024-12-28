#include <stdio.h>
#include <ctype.h>

int htoi(char s[]) {
    int i = 0, n = 0, hex_digit;

    // Check for optional "0x" or "0X" prefix
    if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X')) {
        i += 2; // Skip the "0x" or "0X"
    }

    // Convert hexadecimal string to integer
    while (s[i] != '\0') {
        // Convert the current character to a hex digit
        if (isdigit(s[i])) {
            hex_digit = s[i] - '0'; // '0' to '9'
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            hex_digit = s[i] - 'a' + 10; // 'a' to 'f'
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            hex_digit = s[i] - 'A' + 10; // 'A' to 'F'
        } else {
            return -1; // Invalid character in the string
        }

        // Shift the result to the left by 4 bits (multiply by 16)
        n = n * 16 + hex_digit;
        i++;
    }

    return n;
}

int main() {
    char hex_string[] = "0x1a3f";

    int result = htoi(hex_string);
    if (result != -1) {
        printf("The integer value of '%s' is %d\n", hex_string, result);
    } else {
        printf("Invalid hexadecimal string: %s\n", hex_string);
    }

    return 0;
}
