#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 1000

int reverse_flag = 0;
int numeric_flag = 0;
int fold_flag = 0;
int directory_flag = 0;
int field_flag = 0;
int field_index = 0;

void to_lowercase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);  // Convert each character to lowercase
        str++;
    }
}

int compare(const void *a, const void *b) {
    char *str_a = *(char **)a;
    char *str_b = *(char **)b;

    // Extract the field if field flag is set
    if (field_flag) {
        for (int i = 0; i < field_index; i++) {
            while (*str_a && !isspace(*str_a)) str_a++;
            while (*str_a && isspace(*str_a)) str_a++;
            while (*str_b && !isspace(*str_b)) str_b++;
            while (*str_b && isspace(*str_b)) str_b++;
        }
    }

    // Directory order: only letters, numbers, and spaces matter
    if (directory_flag) {
        while (*str_a && !isalnum(*str_a) && !isspace(*str_a)) str_a++;
        while (*str_b && !isalnum(*str_b) && !isspace(*str_b)) str_b++;
    }

    // Fold case: convert to lowercase for comparison
    if (fold_flag) {
        to_lowercase(str_a);  // Convert to lowercase
        to_lowercase(str_b);  // Convert to lowercase
    }

    // Numeric comparison
    if (numeric_flag) {
        double num_a = atof(str_a);
        double num_b = atof(str_b);
        return reverse_flag ? (num_b - num_a) : (num_a - num_b);
    }

    // Standard lexicographical comparison
    return reverse_flag ? strcmp(str_b, str_a) : strcmp(str_a, str_b);
}

void sort_lines(char *lines[], int line_count) {
    qsort(lines, line_count, sizeof(char *), compare);
}

int main(int argc, char *argv[]) {
    char *lines[MAX_LINES];
    int line_count = 0;

    // Parse command-line flags
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-r") == 0) {
            reverse_flag = 1;
        } else if (strcmp(argv[i], "-n") == 0) {
            numeric_flag = 1;
        } else if (strcmp(argv[i], "-f") == 0) {
            fold_flag = 1;
        } else if (strcmp(argv[i], "-d") == 0) {
            directory_flag = 1;
        } else if (strcmp(argv[i], "-k") == 0 && i + 1 < argc) {
            field_flag = 1;
            field_index = atoi(argv[++i]) - 1;  // field_index is zero-based
        } else {
            lines[line_count++] = argv[i];
        }
    }

    // Sort lines based on options
    sort_lines(lines, line_count);

    // Output sorted lines
    for (int i = 0; i < line_count; i++) {
        printf("%s\n", lines[i]);
    }

    return 0;
}
