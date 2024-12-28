#include <stdio.h>
#include <ctype.h>

// Space-efficient implementation
int isupper_space(char c) {
    return (c >= 'A' && c <= 'Z');
}

int main() {
    char test_char = 'A';
    if (isupper_space(test_char)) {
        printf("'%c' is uppercase\n", test_char);
    } else {
        printf("'%c' is not uppercase\n", test_char);
    }
    
    test_char = 'a';
    if (isupper_space(test_char)) {
        printf("'%c' is uppercase\n", test_char);
    } else {
        printf("'%c' is not uppercase\n", test_char);
    }
    
    return 0;
}
