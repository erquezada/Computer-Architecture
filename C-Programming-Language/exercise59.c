#include <stdio.h>

void strncpy_ptr(char *s, const char *t, size_t n) {
    while (n-- && (*s++ = *t++))  // Copy up to n characters
        ;
    while (n-- > 0)  // Null-terminate if t is shorter than n
        *s++ = '\0';
}

void strncat_ptr(char *s, const char *t, size_t n) {
    while (*s)  // Move to the end of string s
        s++;
    while (n-- && (*s++ = *t++))  // Append up to n characters
        ;
    *s = '\0';
}

int strncmp_ptr(const char *s, const char *t, size_t n) {
    while (n-- && *s && (*s == *t)) {
        s++;
        t++;
    }
    return (n == 0) ? 0 : *s - *t;  // Return 0 if strings are equal up to n characters
}

int main() {
    char s[100] = "Hello";
    char t[] = "world";
    
    strncpy_ptr(s, t, 3);
    printf("strncpy result: %s\n", s);  // Output: Hel
    
    strncat_ptr(s, t, 3);
    printf("strncat result: %s\n", s);  // Output: Helwor
    
    printf("strncmp result: %d\n", strncmp_ptr(s, t, 3));  // Output: 0
    
    return 0;
}
