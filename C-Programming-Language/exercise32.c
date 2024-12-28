#include <stdio.h>

unsigned rightrot(unsigned x, int n) {
    int word_size = sizeof(x) * 8; // Get the number of bits in the integer
    n = n % word_size; // Ensure n is within the range of the word size

    // Perform the right rotation
    return (x >> n) | (x << (word_size - n));
}

int main() {
    unsigned x = 0b1111111000000000; // Example value for x
    int n = 4; // Number of positions to rotate right

    unsigned result = rightrot(x, n);
    printf("Result after rightrot: %u\n", result); // Output result as unsigned integer

    return 0;
}
