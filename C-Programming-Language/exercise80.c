#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 1000
#define MAXWORD 100

// Define the structure for the symbol table entry
struct nlist {
    struct nlist *next;   // Pointer to the next entry in the list
    char *name;           // Name of the identifier
    char *defn;           // Definition (value) of the identifier
};

// Hash table to store the symbol table
static struct nlist *hashtab[101];  // Hash table size (101 is a prime number)

// Function prototypes
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *name);
int getword(char *word, int lim);
void process_define(char *line);
void process_input();

// Hash function to compute the index for a given name
unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % 101;
}

// Function to look up a name in the hash table
struct nlist *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;  // Return the entry if found
    return NULL;  // Return NULL if not found
}

// Function to install a name and definition in the hash table
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    // Check if the name already exists
    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));  // Allocate memory for a new entry
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        // If the name exists, just update the definition
        free((void *) np->defn);
    }

    // Allocate memory for the definition and assign it
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

// Function to remove a name from the symbol table
void undef(char *name) {
    struct nlist *np, *prev;
    unsigned hashval = hash(name);

    // Traverse the hash table to find the name
    prev = NULL;
    for (np = hashtab[hashval]; np != NULL; prev = np, np = np->next) {
        if (strcmp(name, np->name) == 0) {
            if (prev == NULL) {
                hashtab[hashval] = np->next;  // If it's the first entry, update the head
            } else {
                prev->next = np->next;  // Otherwise, bypass the current entry
            }
            free((void *) np->name);
            free((void *) np->defn);
            free((void *) np);
            return;
        }
    }
    printf("Error: %s not found in the symbol table.\n", name);
}

// Function to get the next word from the input
int getword(char *word, int lim) {
    int c;
    char *w = word;

    while (isspace(c = getchar()))  // Skip whitespaces
        ;

    if (c == EOF)  // End of file
        return EOF;

    if (isalpha(c) || c == '_') {  // Word start (variable names)
        *w++ = c;
        while (isalnum(c = getchar()) || c == '_')  // Continue reading
            *w++ = c;
        *w = '\0';
        return word[0];
    }

    return c;  // Return the non-alphanumeric character
}

// Function to process the input lines and handle #define
void process_input() {
    char line[MAXLINE];

    while (fgets(line, sizeof(line), stdin) != NULL) {
        char word[MAXWORD];

        // Process each word in the line
        if (strncmp(line, "#define", 7) == 0) {
            process_define(line);  // Handle the #define directive
        } else {
            // Replace any defined macros
            char *ptr = line;
            while (*ptr != '\0') {
                if (isalpha(*ptr)) {
                    int i = 0;
                    while (isalnum(ptr[i]) || ptr[i] == '_') {
                        word[i] = ptr[i];
                        i++;
                    }
                    word[i] = '\0';

                    struct nlist *entry = lookup(word);
                    if (entry != NULL) {
                        printf("%s", entry->defn);  // Replace word with its definition
                    } else {
                        printf("%s", word);  // Print the word as-is
                    }

                    ptr += i;  // Skip over the word
                } else {
                    putchar(*ptr++);  // Print the non-alphanumeric character
                }
            }
        }
    }
}

// Function to process a #define directive
void process_define(char *line) {
    char name[MAXWORD];
    char defn[MAXLINE];
    int i = 0;
    
    sscanf(line + 7, "%s", name);  // Get the name after #define
    while (line[i] != '\n' && line[i] != '\0') {
        if (line[i] == ' ' || line[i] == '\t') {
            i++;
            break;
        }
        i++;
    }

    sscanf(line + i, "%[^\n]", defn);  // Get the definition
    
    install(name, defn);  // Install the definition in the symbol table
}

// Main function to process the input
int main() {
    process_input();
    return 0;
}
