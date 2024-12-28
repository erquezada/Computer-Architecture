#include <stdio.h>
#include <ctype.h>

int btoi(char s[]) {
    int i = 0, n = 0, binary_digit;

    // Check for optional "0b" or "0B" prefix
    if (s[i] == '0' && (s[i+1] == 'b' || s[i+1] == 'B')) {
        i += 2; // Skip the "0b" or "0B"
    }

    // Convert binary string to integer
    while (s[i] != '\0') {
        // Convert the current character to a binary digit
        if (s[i] == '0') {
            binary_digit = 0;
        } else if (s[i] == '1') {
            binary_digit = 1;
        } else {
            return -1; // Invalid character in the string
        }

        // Shift the result to the left by 1 bit (multiply by 2)
        n = n * 2 + binary_digit;
        i++;
    }

    return n;
}

int main() {
    char binary_string[] = "0b1101";

    int result = btoi(binary_string);
    if (result != -1) {
        printf("The integer value of '%s' is %d\n", binary_string, result);
    } else {
        printf("Invalid binary string: %s\n", binary_string);
    }

    return 0;
}
