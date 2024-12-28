#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 1) {
        printf("Usage: %s\n", argv[0]);
        return 1;  // Error: the program expects no arguments
    }

    // Check if the program name contains "toupper" or "tolower"
    int is_to_upper = 0;
    char *program_name = argv[0];

    if (strstr(program_name, "toupper") != NULL) {
        is_to_upper = 1;  // Convert to uppercase
    } else if (strstr(program_name, "tolower") != NULL) {
        is_to_upper = 0;  // Convert to lowercase
    } else {
        printf("Program name must contain 'toupper' or 'tolower'\n");
        return 1;  // Error: program name does not match expected pattern
    }

    // Process input
    char c;
    while ((c = getchar()) != EOF) {
        if (is_to_upper) {
            putchar(toupper(c));  // Convert character to uppercase
        } else {
            putchar(tolower(c));  // Convert character to lowercase
        }
    }

    return 0;
}
