#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNAME 100
#define MAXDEF 200

// Structure for storing the symbol table entries
struct entry {
    char name[MAXNAME];
    char definition[MAXDEF];
    struct entry *next;
};

// Symbol table
struct entry *symtable = NULL;

// Function to look up a name in the symbol table
struct entry *lookup(char *name) {
    struct entry *e = symtable;
    while (e != NULL) {
        if (strcmp(name, e->name) == 0)
            return e; // Found the entry
        e = e->next;
    }
    return NULL; // Not found
}

// Function to install a new name-definition pair into the symbol table
void install(char *name, char *definition) {
    struct entry *e = (struct entry *)malloc(sizeof(struct entry));
    if (e == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(e->name, name);
    strcpy(e->definition, definition);
    e->next = symtable; // Insert at the beginning of the list
    symtable = e;
}

// Function to remove a name-definition pair from the symbol table
void undef(char *name) {
    struct entry *e = symtable;
    struct entry *prev = NULL;
    while (e != NULL) {
        if (strcmp(name, e->name) == 0) {
            if (prev == NULL) { // Removing the first entry
                symtable = e->next;
            } else {
                prev->next = e->next; // Bypass the current entry
            }
            free(e); // Free the memory of the removed entry
            printf("Removed: %s\n", name);
            return;
        }
        prev = e;
        e = e->next;
    }
    printf("Name '%s' not found in the symbol table.\n", name);
}

int main() {
    // Test the implementation
    install("PI", "3.14159");
    install("MAXLEN", "100");
    
    // Look up and print definitions
    struct entry *e = lookup("PI");
    if (e != NULL)
        printf("Found: %s = %s\n", e->name, e->definition);
    
    // Remove "PI" from the symbol table
    undef("PI");
    
    // Attempt to look up "PI" after removal
    e = lookup("PI");
    if (e == NULL)
        printf("PI is no longer in the table.\n");

    return 0;
}
