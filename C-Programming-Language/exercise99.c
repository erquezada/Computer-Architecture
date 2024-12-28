#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 1024

static char free_list[HEAP_SIZE];
static char *freep = free_list;

void *bmalloc(size_t size) {
    if (freep + size <= free_list + HEAP_SIZE) {
        void *p = freep;
        freep += size;
        return p;
    }
    return NULL;
}

void bfree(void *p, size_t n) {
    if (p >= (void *)free_list && (char *)p + n <= free_list + HEAP_SIZE) {
        memmove(freep, p, n);
        freep += n;
    } else {
        fprintf(stderr, "Error: Cannot free invalid block.\n");
    }
}

int main() {
    char static_block[256];
    printf("Adding static block to the free list...\n");
    bfree(static_block, sizeof(static_block));

    printf("Allocating memory from free list...\n");
    void *block = bmalloc(128);
    if (block) {
        printf("Memory allocated successfully.\n");
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
