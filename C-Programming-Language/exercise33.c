#include <stdio.h>

unsigned bitcount(unsigned x) {
    unsigned count = 0;
    while (x) {
        x &= (x - 1);  // Clears the rightmost 1-bit
        count++;       // Increment count for each cleared 1-bit
    }
    return count;
}

int main() {
    unsigned x = 29;  // Example value (binary: 11101)
    printf("The number of 1-bits in %u is: %u\n", x, bitcount(x));
    return 0;
}
