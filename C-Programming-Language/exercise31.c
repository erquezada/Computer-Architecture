#include <stdio.h>

unsigned invert(unsigned x, int p, int n) {
    // Create a mask to select the n bits starting at position p
    unsigned mask = (~(~0U << n)) << (p - n + 1);

    // Invert the selected bits and combine with x
    return x ^ mask;
}

int main() {
    unsigned x = 0b1111111000000000; // Example value for x
    int p = 10; // Starting position for inversion
    int n = 4;  // Number of bits to invert

    unsigned result = invert(x, p, n);
    printf("Result after invert: %u\n", result); // Output result as unsigned integer

    return 0;
}
