#include <stdio.h>

void countBlanksTabsNewlines() {
    int c, blanks, tabs, newlines;
    blanks = tabs = newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
        } else if (c == '\t') {
            ++tabs;
        } else if (c == '\n') {
            ++newlines;
        }
    }

    printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", blanks, tabs, newlines);
}

void replaceMultipleBlanks() {
    int c, lastChar = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' || lastChar != ' ') {
            putchar(c);
        }
        lastChar = c;
    }
}

void makeTabsBackspacesVisible() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else {
            putchar(c);
        }
    }
}

int main() {
    int choice;

    printf("Choose an exercise to run:\n");
    printf("1. Count blanks, tabs, and newlines\n");
    printf("2. Replace multiple blanks with a single blank\n");
    printf("3. Make tabs, backspaces, and backslashes visible\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Consume the newline character left by scanf
    getchar();

    printf("Enter input (press Ctrl+D to end):\n");

    switch (choice) {
        case 1:
            countBlanksTabsNewlines();
            break;
        case 2:
            replaceMultipleBlanks();
            break;
        case 3:
            makeTabsBackspacesVisible();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
