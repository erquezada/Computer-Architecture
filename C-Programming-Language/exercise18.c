#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to reverse the string s
void reverse(char *s) {
    int length = strlen(s);
    int i, j;
    char temp;
    
    // Swap characters from start and end until the middle
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    
    // Read each line until end of file (EOF)
    while (fgets(line, sizeof(line), stdin)) {
        // Reverse the line
        reverse(line);
        // Print the reversed line
        printf("%s", line);
    }

    return 0;
}
