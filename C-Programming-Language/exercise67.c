#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAB_STOPS 100

void entab(int start_col, int interval) {
    int c, col = 0;
    int tab_stops[MAX_TAB_STOPS];
    int tab_count = 0;

    // Generate tab stops based on start column and interval
    for (int i = start_col; tab_count < MAX_TAB_STOPS; i += interval) {
        tab_stops[tab_count++] = i;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            for (int i = 0; i < tab_count; i++) {
                if (col == tab_stops[i]) {
                    putchar('\t');
                    col = 0;
                    break;
                }
            }
            if (col != 0) {
                putchar(' ');
                col++;
            }
        } else {
            putchar(c);
            col++;
            if (c == '\n') col = 0;
        }
    }
}

void detab(int start_col, int interval) {
    int c, col = 0;
    int tab_stops[MAX_TAB_STOPS];
    int tab_count = 0;

    // Generate tab stops based on start column and interval
    for (int i = start_col; tab_count < MAX_TAB_STOPS; i += interval) {
        tab_stops[tab_count++] = i;
    }

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = tab_stops[0] - col;
            if (spaces < 0) spaces = tab_stops[0];
            for (int i = 0; i < spaces; i++) {
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
    int start_col = 1, interval = 8; // Default tab stop settings

    // Parse the options for shorthand "-m +n"
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] == 'm') {
            start_col = atoi(argv[++i]);
        } else if (argv[i][0] == '+' && argv[i][1] == 'n') {
            interval = atoi(argv[++i]);
        }
    }

    // Use default behavior if no shorthand is passed
    entab(start_col, interval);
    return 0;
}
