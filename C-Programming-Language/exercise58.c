#include <stdio.h>
#include <string.h>

int strend(const char *s, const char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_t > len_s)
        return 0;

    s += len_s - len_t;  // Move s to the start of the end part

    while (*s && *t) {
        if (*s != *t)
            return 0;
        s++;
        t++;
    }
    return 1;
}

int main() {
    char s[] = "Hello, world!";
    char t[] = "world!";
    
    printf("strend result: %d\n", strend(s, t));  // Output: 1
    
    return 0;
}
