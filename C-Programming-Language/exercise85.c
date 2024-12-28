#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTACK 100
#define MAXLINE 100

double stack[MAXSTACK];
int sp = 0;

void push(double value) {
    if (sp < MAXSTACK) {
        stack[sp++] = value;
    } else {
        printf("Error: Stack full\n");
    }
}

double pop(void) {
    if (sp > 0) {
        return stack[--sp];
    } else {
        printf("Error: Stack empty\n");
        return 0.0;
    }
}

int main() {
    char line[MAXLINE];
    double op2;
    
    printf("Enter a postfix expression (e.g., 2 3 +):\n");
    
    while (fgets(line, MAXLINE, stdin)) {
        char *token = strtok(line, " \t\n");  // Tokenize by space, tab, or newline
        while (token != NULL) {
            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {  // Check if token is a number
                double num;
                if (sscanf(token, "%lf", &num) == 1) {
                    push(num);
                } else {
                    printf("Error: Invalid number\n");
                }
            } else {
                switch (token[0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0) {
                        push(pop() / op2);
                    } else {
                        printf("Error: Division by zero\n");
                    }
                    break;
                default:
                    printf("Error: Unknown operator %s\n", token);
                    break;
                }
            }
            token = strtok(NULL, " \t\n");  // Get next token
        }

        if (sp == 1) {
            printf("Result: %.8g\n", pop());  // Print the result
        } else {
            printf("Error: Invalid expression\n");
        }
    }

    return 0;
}
