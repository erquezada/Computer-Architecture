#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // Create a mask to clear the n bits starting at position p in x
    unsigned mask = (~0U << (p + 1)) | ~(~0U << (p - n + 1));

    // Clear the n bits in x at position p, then set the n bits from y
    return (x & mask) | ((y & ~(~0U << n)) << (p - n + 1));
}

int main() {
    unsigned x = 0b1111111000000000; // Example value for x
    unsigned y = 0b1101; // Example value for y
    int p = 10; // Starting position for bit modification
    int n = 4;  // Number of bits to modify

    unsigned result = setbits(x, p, n, y);
    printf("Result after setbits: %u\n", result); // Output result as unsigned integer

    return 0;
}
