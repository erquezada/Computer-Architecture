#include <stdio.h>

int any(char s1[], char s2[]) {
    int i, j;

    // Iterate through each character of s1
    for (i = 0; s1[i] != '\0'; i++) {
        // Check if the current character of s1 matches any character in s2
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i; // Return the index if a match is found
            }
        }
    }

    return -1; // Return -1 if no characters from s2 are found in s1
}

int main() {
    char s1[] = "hello world";
    char s2[] = "wo";

    int result = any(s1, s2);
    if (result != -1) {
        printf("The first match occurs at index: %d\n", result);
    } else {
        printf("No characters from s2 found in s1\n");
    }

    return 0;
}
