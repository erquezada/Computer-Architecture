#include <stdio.h>

// Time-efficient implementation using a lookup table
int isupper_time(char c) {
    // Lookup table for 'A' to 'Z'
    static int lookup[256] = { 0 };
    if (lookup['A'] == 0) {  // Only initialize once
        for (char ch = 'A'; ch <= 'Z'; ++ch) {
            lookup[ch] = 1; // Mark uppercase letters
        }
    }
    return lookup[(unsigned char)c]; // Access the lookup table in O(1) time
}

int main() {
    char test_char = 'A';
    if (isupper_time(test_char)) {
        printf("'%c' is uppercase\n", test_char);
    } else {
        printf("'%c' is not uppercase\n", test_char);
    }
    
    test_char = 'a';
    if (isupper_time(test_char)) {
        printf("'%c' is uppercase\n", test_char);
    } else {
        printf("'%c' is not uppercase\n", test_char);
    }
    
    return 0;
}
