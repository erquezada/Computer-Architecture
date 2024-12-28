#include <stdio.h>

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

void duplicate(void) {
    if (sp > 0) {
        push(val[sp - 1]);
    } else {
        printf("Stack empty, can't duplicate\n");
    }
}

void swap(void) {
    if (sp > 1) {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    } else {
        printf("Stack too small to swap\n");
    }
}

void clear(void) {
    sp = 0;
    printf("Stack cleared\n");
}

int main() {
    // Test the functions here
    push(10.5);
    push(20.5);
    print_stack();  // Should print 20.5 10.5

    duplicate();
    print_stack();  // Should print 20.5 10.5 10.5

    swap();
    print_stack();  // Should print 10.5 20.5 10.5

    clear();
    print_stack();  // Should print "Stack is empty"

    return 0;
}
