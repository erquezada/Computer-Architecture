#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000  /* initial buffer size for input lines */

/* function declarations */
int getline_dynamic(char **line);
void copy(char *to, const char *from);

/* print the longest input */
int main() {
    int len;            /* current line length */
    int max = 0;        /* maximum length seen so far */
    char *line = NULL;  /* pointer to dynamically allocated memory for the current input line */
    char *longest = NULL;  /* pointer to dynamically allocated memory for the longest line */

    while ((len = getline_dynamic(&line)) > 0) {
        if (len > max) {
            max = len;
            if (longest) {  /* free the old longest line if it exists */
                free(longest);
            }
            longest = malloc(len + 1);  /* allocate memory for the new longest line */
            if (longest == NULL) {
                printf("Memory allocation failed\n");
                return 1;
            }
            copy(longest, line);  /* copy the current line to the longest line */
        }
    }

    if (max > 0) {  /* there was a line */
        printf("Longest line (length %d):\n%s", max, longest);
        free(longest);  /* free the memory allocated for the longest line */
    }

    free(line);  /* free the memory allocated for the current line */
    return 0;
}

/* getline_dynamic: read a line into dynamically allocated memory, return length */
int getline_dynamic(char **line) {
    int c, i = 0;
    int capacity = MAXLINE;  /* initial buffer size */

    *line = malloc(capacity);
    if (*line == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    while ((c = getchar()) != EOF && c != '\n') {
        (*line)[i++] = c;

        /* If the line exceeds the current capacity, reallocate memory */
        if (i >= capacity) {
            capacity *= 2;  /* double the capacity */
            *line = realloc(*line, capacity);
            if (*line == NULL) {
                printf("Memory reallocation failed\n");
                return -1;
            }
        }
    }

    if (c == '\n') {
        (*line)[i++] = c;  /* save the newline character */
    }
    (*line)[i] = '\0';  /* null-terminate the string */

    return i;  /* return the length of the line */
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char *to, const char *from) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
