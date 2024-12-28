#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]) {
    int i, j;
    int lastIndex = -1;
    
    // Loop through the string s
    for (i = strlen(s) - 1; i >= 0; i--) {
        // Check if the substring t starts at position i
        for (j = 0; t[j] != '\0' && s[i + j] == t[j]; j++) {
            // Continue to match the rest of t
        }
        
        // If we found the whole substring t
        if (t[j] == '\0') {
            lastIndex = i; // Record the index of the last occurrence
            break; // We found the last occurrence, no need to continue
        }
    }
    
    return lastIndex; // Return the index of the rightmost occurrence
}

int main() {
    char s[] = "This is a simple example. This is a test.";
    char t[] = "is";
    
    int index = strindex(s, t);
    if (index != -1) {
        printf("The rightmost occurrence of \"%s\" is at position: %d\n", t, index);
    } else {
        printf("The substring \"%s\" was not found.\n", t);
    }
    
    return 0;
}
