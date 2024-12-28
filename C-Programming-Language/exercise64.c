#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_STACK_SIZE 100

// Stack for storing numbers
double stack[MAX_STACK_SIZE];
int stack_pos = 0;

// Push a number onto the stack
void push(double value) {
    if (stack_pos < MAX_STACK_SIZE) {
        stack[stack_pos++] = value;
    } else {
        printf("Error: Stack overflow.\n");
        exit(1);
    }
}

// Pop a number from the stack
double pop() {
    if (stack_pos > 0) {
        return stack[--stack_pos];
    } else {
        printf("Error: Stack underflow.\n");
        exit(1);
    }
}

// Evaluate the expression
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: No expression provided.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (isdigit(argv[i][0])) {
            // If it's a number, push it to the stack
            push(atof(argv[i]));
        } else {
            // If it's an operator, pop operands and apply the operator
            double op2 = pop();
            double op1 = pop();
            switch (argv[i][0]) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    if (op2 != 0) {
                        push(op1 / op2);
                    } else {
                        printf("Error: Division by zero.\n");
                        return 1;
                    }
                    break;
                default:
                    printf("Error: Unknown operator %s.\n", argv[i]);
                    return 1;
            }
        }
    }

    // The result is the last value on the stack
    printf("Result: %.2f\n", pop());
    return 0;
}
