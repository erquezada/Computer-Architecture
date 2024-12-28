#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100

// Buffer and ungetch to handle input characters
char buf[BUFSIZE];
int bufp = 0;
int getch(void);
void ungetch(int);

// Function to get the next word
int getword(char *word, int lim);

// Function to compare variable names and group them based on first 'n' characters
void group_variables(int n);

int main(int argc, char *argv[]) {
    int n = 6; // Default number of characters to compare
    
    if (argc > 1) {
        n = atoi(argv[1]); // Get 'n' from command-line argument
    }

    group_variables(n);
    return 0;
}

// Function to get the next character from the input
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// Function to put a character back into the input
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

// Function to get a word from input (ignoring comments and string literals)
int getword(char *word, int lim) {
    int c, d;
    char *w = word;

    // Skip whitespace characters
    while (isspace(c = getch()))
        ;

    // Handle comments (single-line and multi-line)
    if (c == '/') {
        if ((d = getch()) == '/') { // Single-line comment
            while ((c = getch()) != '\n' && c != EOF)
                ;
            return getword(word, lim); // Restart after the comment
        } else if (d == '*') { // Multi-line comment
            while (1) {
                if ((c = getch()) == EOF)
                    return EOF;
                if (c == '*' && (d = getch()) == '/') {
                    break;
                } else {
                    ungetch(d);
                }
            }
            return getword(word, lim); // Restart after the comment
        } else {
            ungetch(c);
            ungetch(d);
        }
    }

    // Handle string literals
    if (c == '"') {
        while ((c = getch()) != '"' && c != EOF)
            if (c == '\\') getch(); // Skip escaped characters
        return getword(word, lim); // Restart after the string literal
    }

    // Handle identifiers or keywords
    if (isalpha(c) || c == '_') { // Start of an identifier
        *w++ = c;
        while (isalnum(c = getch()) || c == '_')
            *w++ = c;
        *w = '\0';
        ungetch(c);
        return word[0]; // Return the first character as the word's identifier
    }

    // Handle numbers (not required to be full words, but included for completeness)
    if (isdigit(c)) {
        *w++ = c;
        while (isdigit(c = getch()))
            *w++ = c;
        *w = '\0';
        ungetch(c);
        return word[0]; // Return the first character as the word's identifier
    }

    // Return the character if it's a single character
    if (c != EOF)
        return c;

    return EOF; // End of file or input
}

// Function to group variables by the first 'n' characters
void group_variables(int n) {
    char word[MAXWORD];
    char group[BUFSIZE][MAXWORD];
    int group_count = 0;
    
    // Map to store variable names by the first 'n' characters
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) || word[0] == '_') {
            // Group variable names by the first 'n' characters
            char prefix[n + 1];
            strncpy(prefix, word, n);
            prefix[n] = '\0';

            // Check if this prefix already exists in the group list
            int found = 0;
            for (int i = 0; i < group_count; i++) {
                if (strncmp(group[i], prefix, n) == 0) {
                    printf("%s\n", word); // Print the variable name
                    found = 1;
                    break;
                }
            }

            if (!found) {
                // Add to the group
                strcpy(group[group_count], word);
                group_count++;
            }
        }
    }
}
