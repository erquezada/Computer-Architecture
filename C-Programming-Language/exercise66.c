#include <stdio.h>
#include <stdlib.h>

void detab(int tab_stops[], int tab_count) {
    int c, col = 0, i;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            // Move to the next tab stop
            int spaces = tab_stops[0] - col;
            if (spaces < 0) spaces = tab_stops[0];
            for (i = 0; i < spaces; i++) {
                putchar(' ');
            }
            col = 0;
        } else {
            putchar(c);
            col++;
            if (c == '\n') col = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: Please provide tab stops as arguments.\n");
        return 1;
    }

    int tab_stops[argc - 1];
    for (int i = 1; i < argc; i++) {
        tab_stops[i - 1] = atoi(argv[i]);
    }

    detab(tab_stops, argc - 1);
    return 0;
}
