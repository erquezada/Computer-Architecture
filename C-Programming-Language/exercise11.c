#include <stdio.h>

#define MAX_CHARACTERS 128  // Maximum number of characters (ASCII range)

void print_histogram(int frequencies[]) {
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        if (frequencies[i] > 0) {
            // Print the character and its frequency as a horizontal bar
            printf("'%c' (%d): ", i, frequencies[i]);
            for (int j = 0; j < frequencies[i]; j++) {
                printf("#");
            }
            printf("\n");
        }
    }
}

int main() {
    int c;
    int frequencies[MAX_CHARACTERS] = {0};  // Array to store frequencies of characters

    printf("Enter text (Ctrl+D to end input):\n");

    // Read each character from the input
    while ((c = getchar()) != EOF) {
        frequencies[c]++;  // Increment the frequency for the character
    }

    // Print the histogram of character frequencies
    print_histogram(frequencies);

    return 0;
}
