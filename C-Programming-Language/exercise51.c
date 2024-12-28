#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int len = strlen(s);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itoa(int n, char s[]) {
    int i = 0;
    // Base case: If n is zero, just return
    if (n == 0) {
        s[i] = '0';
        s[i + 1] = '\0';
        return;
    }
    
    // Recursively call itoa
    if (n < 0) {  // Handle negative numbers
        s[i++] = '-';
        n = -n;
    }
    
    // Recursive case: Move the digits into the string
    if (n / 10 != 0) {
        itoa(n / 10, s + 1);  // Recurse for all but the last digit
    }
    
    // Append the current digit to the string
    s[i] = (n % 10) + '0';  // Convert last digit to character
    s[i + 1] = '\0';  // Null-terminate the string
}

int main() {
    int num = -12345;
    char str[100];

    itoa(num, str);
    printf("Converted integer: %s\n", str);  // Output: -12345
    return 0;
}
