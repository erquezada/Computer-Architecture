#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100
#define MAXLINE 500

// Noise words to ignore
char *noise[] = {"the", "and", "but", "or", "if", "then", "else", NULL};

// Function to get the next word
int getword(char *word, int lim);

int is_noise_word(char *word);

int main() {
    char word[MAXWORD];
    int line_number = 1;
    // A simple hash table to store words and line numbers
    while (getword(word, MAXWORD) != EOF) {
        if (!is_noise_word(word)) {
            printf("%s found at line %d\n", word, line_number);
        }
    }
    return 0;
}

// Check if the word is a noise word
int is_noise_word(char *word) {
    for (int i = 0; noise[i] != NULL; i++) {
        if (strcmp(word, noise[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
