#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXTOKEN 100
#define PARENS 1
#define BRACKETS 2
#define NAME 3
#define STAR 4
#define EOF -1

char out[MAXTOKEN];
char token[MAXTOKEN];

// Placeholder for gettoken, you would define the actual tokenization logic
int gettoken() {
    // Return appropriate tokens or EOF here
    return EOF;
}

void dcl() {
    int type;
    
    while ((type = gettoken()) != EOF) {
        if (type == STAR) {
            // Handle the '*' case: pointer, add to the output
            strcat(out, "pointer to ");
        } else if (type == NAME) {
            // Handle the name (type identifier) case
            strcpy(out, token);
            return; // Once NAME is found, stop processing
        } else {
            // If we encounter an invalid token, skip it and continue
            printf("Invalid token: %s\n", token);
            while ((type = gettoken()) != EOF && type != '\n') {
                // Skip tokens until a valid one is found
            }
            return;
        }
    }
}

int main() {
    dcl();
    return 0;
}
