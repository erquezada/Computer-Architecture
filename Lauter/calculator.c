#include <stdio.h>

// Static inline functions for basic arithmetic
static inline int add(int a, int b) { return a + b; }
static inline int subtract(int a, int b) { return a - b; }
static inline int product(int a, int b) { return a * b; }

// Function to divide two integers with error handling
float divide(int a, int b) {
    return (b != 0) ? (float)a / b : 0.0f;
}

int main() {
    int a, b;
    printf("Enter two integers (separated by space): ");
    scanf("%d %d", &a, &b);
    
    // Perform operations
    int sum = add(a, b);
    int difference = subtract(a, b);
    int prod = product(a, b);
    float quotient = divide(a, b);
    
    // Display results
    printf("The sum of %d + %d = %d\n", a, b, sum);
    printf("The difference between %d - %d = %d\n", a, b, difference);
    printf("The product of %d * %d = %d\n", a, b, prod);
    
    // Division result only if valid
    if (b != 0) {
        printf("The quotient of %d / %d = %.2f\n", a, b, quotient);
    } else {
        printf("Error: Division by zero is undefined.\n");
    }

    return 0;
}
