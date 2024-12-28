#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

int getch(void);
void ungetch(int);

int getword(char *word, int lim) {
    int c, d;
    char *w = word;

    // Skip whitespace characters
    while (isspace(c = getch()))
        ;

    // Handle comments
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

    // Handle preprocessor directives (e.g., #define, #include)
    if (c == '#') {
        while ((c = getch()) != '\n' && c != EOF)
            ; // Skip the entire preprocessor directive
        return getword(word, lim); // Restart after the preprocessor line
    }

    // If it's the start of a string literal, skip the string
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

#define BUFSIZE 100

char buf[BUFSIZE];  // Buffer for ungetch
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int main() {
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF) {
        printf("%s\n", word);
    }
    return 0;
}
