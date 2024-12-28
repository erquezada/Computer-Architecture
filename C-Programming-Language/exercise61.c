#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 1000
#define MAXLEN 1000

// Function to read a line from input
int getline_custom(char *line, int maxlen) {
    int c, i;
    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

// Function to read lines and store them in the array provided by main
int readlines(char *lines[], int maxlines) {
    int len, nlines = 0;
    char line[MAXLEN];
    
    while ((len = getline_custom(line, MAXLEN)) > 0) {
        if (nlines >= maxlines) {
            return -1;  // Too many lines
        } else {
            lines[nlines] = malloc(len + 1);  // Allocate memory for the line
            if (lines[nlines] == NULL) {
                return -1;  // Memory allocation failed
            }
            strcpy(lines[nlines], line);
            nlines++;
        }
    }
    return nlines;
}

void writelines(char *lines[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        printf("%s", lines[i]);
    }
}

int main() {
    char *lines[MAXLINES];  // Array of pointers to hold the lines
    int nlines;

    nlines = readlines(lines, MAXLINES);  // Read lines into array
    if (nlines >= 0) {
        writelines(lines, nlines);  // Print the lines
    } else {
        printf("Error: Unable to read lines.\n");
    }

    // Free allocated memory
    for (int i = 0; i < nlines; i++) {
        free(lines[i]);
    }

    return 0;
}
