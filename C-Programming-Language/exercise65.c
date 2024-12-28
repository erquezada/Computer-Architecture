#include <stdio.h>
#include <stdlib.h>

void entab(int tab_stops[], int tab_count) {
    int c, i, col = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            // Check if we are at a tab stop
            for (i = 0; i < tab_count; i++) {
                if (col == tab_stops[i]) {
                    putchar('\t');
                    col = 0;  // reset column
                    break;
                }
            }
            if (i == tab_count) {
                putchar(c);
                col++;
            }
        } else {
            putchar(c);
            if (c == '\n') {
                col = 0;
            } else {
                col++;
            }
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

    entab(tab_stops, argc - 1);
    return 0;
}
