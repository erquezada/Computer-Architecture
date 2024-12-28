#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
int main() {
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;

    printf("Exercise 1-11: Testing Word Count Program\n");
    printf("Test cases: Empty input, multiple spaces, tabs, newlines, special characters.\n");
    printf("Enter input text (press Ctrl+D or Ctrl+Z to end input):\n");

    // Word count program (counts lines, words, characters)
    while ((c = getchar()) != EOF) {
        ++nc;  // Count characters
        
        if (c == '\n') {
            ++nl;  // Count lines
        }
        
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;  // End of a word
        } else if (state == OUT) {
            state = IN;   // New word started
            ++nw;         // Count words
        }
    }

    printf("Lines: %d, Words: %d, Characters: %d\n\n", nl, nw, nc);

    // Exercise 1-12: Print input one word per line
    printf("Exercise 1-12: Print input one word per line\n");
    printf("Enter input text (press Ctrl+D or Ctrl+Z to end input):\n");

    // Reset variables for word printing
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                putchar('\n');  // Print newline when a word ends
            }
            state = OUT;  // Out of a word
        } else {
            if (state == OUT) {
                state = IN;  // New word started
            }
            putchar(c);  // Print character
        }
    }
    
    // Final check for the last word in case there’s no space/newline at the end
    if (state == IN) {
        putchar('\n');
    }

    return 0;  // Return success
}
