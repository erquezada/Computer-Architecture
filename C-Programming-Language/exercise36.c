#include <stdio.h>

void escape(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\n': 
                s[j++] = '\\'; s[j++] = 'n';
                break;
            case '\t': 
                s[j++] = '\\'; s[j++] = 't';
                break;
            case '\\': 
                s[j++] = '\\'; s[j++] = '\\';
                break;
            default:
                s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0'; // Null-terminate the string
}

void unescape(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (t[i] != '\0') {
        if (t[i] == '\\' && (t[i+1] == 'n' || t[i+1] == 't' || t[i+1] == '\\')) {
            switch (t[i+1]) {
                case 'n': 
                    s[j++] = '\n';
                    break;
                case 't': 
                    s[j++] = '\t';
                    break;
                case '\\': 
                    s[j++] = '\\';
                    break;
            }
            i++; // Skip the next character as it's part of the escape sequence
        } else {
            s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0'; // Null-terminate the string
}

int main() {
    char s[100], t[] = "Hello\tWorld\nThis is a \\test string.";
    char u[100];

    // Test escape function
    escape(s, t);
    printf("Escaped: %s\n", s);

    // Test unescape function
    unescape(u, s);
    printf("Unescaped: %s\n", u);

    return 0;
}
