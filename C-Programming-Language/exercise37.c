x#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]) {
    int i, j;
    i = 0;
    j = 0;
    
    while (s1[i] != '\0') {
        // If the current character is a '-', check if it's a valid range
        if (s1[i] == '-' && i > 0 && s1[i+1] != '\0' && ((isalnum(s1[i-1]) && isalnum(s1[i+1])) || (isalpha(s1[i-1]) && isalpha(s1[i+1])))) {
            // Valid range: expand the characters
            if (s1[i-1] < s1[i+1]) {
                for (char c = s1[i-1] + 1; c < s1[i+1]; c++) {
                    s2[j++] = c;
                }
            } else if (s1[i-1] > s1[i+1]) {
                for (char c = s1[i-1] - 1; c > s1[i+1]; c--) {
                    s2[j++] = c;
                }
            }
            i++; // Skip the next character as we've already expanded
        } else {
            // Copy the character as is to s2
            s2[j++] = s1[i];
        }
        i++;
    }
    s2[j] = '\0'; // Null-terminate the string
}

int main() {
    char s1[] = "a-zA-Z0-9-abc-d-e";
    char s2[100];
    
    expand(s1, s2);
    printf("Expanded: %s\n", s2);
    
    return 0;
}
