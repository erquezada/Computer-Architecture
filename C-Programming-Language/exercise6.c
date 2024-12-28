#include <stdio.h>

/* Exercise 1-6: Verify that the expression getchar() != EOF is 0 or 1 */
/* Exercise 1-7: Write a program to print the value of EOF */

int main() {
    int c;

    /* Exercise 1-7: Print the value of EOF */
    printf("The value of EOF is: %d\n", EOF);

    /* Exercise 1-6: Verify getchar() != EOF */
    printf("Type some characters and press Enter, or press Ctrl+D (Linux/Mac) or Ctrl+Z (Windows) to send EOF.\n");
    printf("The expression getchar() != EOF evaluates to (0 or 1):\n");

    while ((c = getchar()) != EOF) {
        printf("Result: %d\n", c != EOF);
        putchar(c);
    }

    printf("Result after EOF: %d\n", c != EOF);

    return 0;
}
