#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100
#define PARENS 1
#define BRACKETS 2
#define NAME 3
#define STAR 4
#define CONST 5
#define VOLATILE 6
#define EOF -1

char out[MAXTOKEN];
char token[MAXTOKEN];

int gettoken() {
    // Placeholder for token retrieval logic
    return EOF;
}

void dcl() {
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF) {
        strcpy(out, token);

        while ((type = gettoken()) != '\n' && type != EOF) {
            if (type == CONST || type == VOLATILE) {
                // Add qualifiers like const or volatile
                strcat(out, token);
            } else if (type == PARENS || type == BRACKETS) {
                strcat(out, token);
            } else if (type == STAR) {
                sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else {
                printf("invalid input at %s\n", token);
                return;
            }
        }

        printf("%s\n", out);
    }
}

int main() {
    dcl();
    return 0;
}
