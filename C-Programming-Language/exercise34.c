#include <stdio.h>

char lower(char c) {
    return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
}

int main() {
    char upper = 'G';
    char lower_case = lower(upper);
    printf("Original: %c, Lowercase: %c\n", upper, lower_case);
    
    upper = 'g'; // Test with a lowercase letter (no change)
    lower_case = lower(upper);
    printf("Original: %c, Lowercase: %c\n", upper, lower_case);
    
    return 0;
}
