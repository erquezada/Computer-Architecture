#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20  // Maximum length of word in the histogram

// Function to print the histogram vertically
void print_histogram(int word_lengths[], int max_length) {
    // Find the maximum word length
    for (int i = max_length; i > 0; i--) {
        for (int j = 1; j <= MAX_WORD_LENGTH; j++) {
            if (word_lengths[j] >= i) {
                printf(" | ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    // Print the x-axis (word lengths)
    for (int i = 1; i <= MAX_WORD_LENGTH; i++) {
        printf(" ---");
    }
    printf("\n");

    // Print the word lengths below the bars
    for (int i = 1; i <= MAX_WORD_LENGTH; i++) {
        printf("  %2d", i);
    }
    printf("\n");
}

int main() {
    int c, length = 0;
    int word_lengths[MAX_WORD_LENGTH + 1] = {0};  // Array to store word lengths

    printf("Enter text (Ctrl+D to end input):\n");

    // Process each character in the input
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            length++;  // Count the length of a word
        } else if (length > 0) {
            if (length <= MAX_WORD_LENGTH) {
                word_lengths[length]++;  // Increment the count for the word length
            }
            length = 0;  // Reset length for the next word
        }
    }

    // If the last word didn't end with a non-alphabetic character, count it
    if (length > 0 && length <= MAX_WORD_LENGTH) {
        word_lengths[length]++;
    }

    // Print the vertical histogram
    print_histogram(word_lengths, MAX_WORD_LENGTH);

    return 0;
}
