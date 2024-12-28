#include <stdio.h>

void squeeze(char s1[], char s2[]) {
    int i, j;
    i = j = 0;

    while (s1[i] != '\0') {
        // Check if the current character of s1 matches any character in s2
        int found = 0;
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                found = 1;
                break;
            }
        }

        // If character is not found in s2, move it to the result
        if (!found) {
            s1[i - j] = s1[i];
        }

        i++;
    }

    // Null-terminate the modified string
    s1[i - j] = '\0';
}

int main() {
    char s1[] = "hello world";
    char s2[] = "lo";

    printf("Original s1: %s\n", s1);
    squeeze(s1, s2);
    printf("Modified s1: %s\n", s1);

    return 0;
}
