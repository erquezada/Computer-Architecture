#include <stdio.h>

#define swap(t, x, y) { \
    t temp = x;          \
    x = y;               \
    y = temp;            \
}

int main() {
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(int, a, b);  // Swap integers
    printf("After swap: a = %d, b = %d\n", a, b);
    
    double x = 3.14, y = 2.71;
    printf("Before swap: x = %.2f, y = %.2f\n", x, y);
    swap(double, x, y);  // Swap doubles
    printf("After swap: x = %.2f, y = %.2f\n", x, y);

    return 0;
}
