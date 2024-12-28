#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100
#define PARENS 1
#define BRACKETS 2
#define NAME 3
#define STAR 4
#define EOF -1

char out[MAXTOKEN];
char token[MAXTOKEN];

int gettoken() {
    // Placeholder function, you need to define the actual tokenization logic
    // Return the type of the token or EOF when done
    return EOF;
}

void undcl() {
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n' && type != EOF) {
            if (type == PARENS || type == BRACKETS) {
                strcat(out, token);
            } else if (type == '*') {
                sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else {
                printf("invalid input at %s\n", token);
                return; // Exit on invalid input
            }
        }
        printf("%s\n", out); // Output the declaration
    }
}

int main() {
    undcl();
    return 0;
}
