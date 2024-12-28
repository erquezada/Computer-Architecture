#include <stdio.h>
#include <math.h>

#define MAX_STACK_SIZE 100
double val[MAX_STACK_SIZE];  // Stack to hold values
int sp = 0;  // Stack pointer to track the top of the stack

void push(double value) {
    if (sp < MAX_STACK_SIZE) {
        val[sp++] = value;
    } else {
        printf("Stack full, can't push\n");
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("Stack empty, can't pop\n");
        return 0.0;  // Return a default value in case of error
    }
}

void handle_sin(void) {
    push(sin(pop()));
}

void handle_exp(void) {
    push(exp(pop()));
}

void handle_pow(void) {
    double op2 = pop();
    double op1 = pop();
    push(pow(op1, op2));
}

void print_stack(void) {
    if (sp == 0) {
        printf("Stack is empty\n");
    } else {
        for (int i = sp - 1; i >= 0; i--) {
            printf("%.8g ", val[i]);
        }
        printf("\n");
    }
}

int main() {
    // Example test of the functions
    push(3.0);
    handle_sin();
    print_stack();  // Should print the sine of 3.0

    push(2.0);
    handle_exp();
    print_stack();  // Should print e^2.0

    push(2.0);
    push(3.0);
    handle_pow();
    print_stack();  // Should print 2^3 (which is 8.0)

    return 0;
}
