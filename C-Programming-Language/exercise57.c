#include <stdio.h>

void strcat_ptr(char *s, const char *t) {
    while (*s)  // Move to the end of string s
        s++;
    while (*t)  // Copy characters from t to s
        *s++ = *t++;
    *s = '\0';  // Null-terminate the resulting string
}

int main() {
    char s[100] = "Hello, ";
    char t[] = "world!";
    
    strcat_ptr(s, t);
    printf("Resulting string: %s\n", s);  // Output: Hello, world!
    
    return 0;
}
