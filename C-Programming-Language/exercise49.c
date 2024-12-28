#include <stdio.h>
#include <string.h>  // For strtok()

#define MAXLINE 1000

char line[MAXLINE];

int main() {
    while (fgets(line, MAXLINE, stdin) != NULL) {
        // Tokenize the input from `line`
        char *token = strtok(line, " \t\n");  // Tokenize by space, tab, or newline

        // Process the tokens
        while (token != NULL) {
            printf("Token: %s\n", token);  // Example: print each token
            token = strtok(NULL, " \t\n");  // Get the next token
        }
    }
    return 0;
}
