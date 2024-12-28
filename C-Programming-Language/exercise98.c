#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOC 1024 * 1024 // Maximum allocation limit (1 MB)

void *safe_malloc(size_t size) {
    if (size == 0 || size > MAX_ALLOC) {
        fprintf(stderr, "Error: Invalid memory allocation size: %zu\n", size);
        return NULL;
    }
    void *ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
    }
    return ptr;
}

void safe_free(void *ptr) {
    if (!ptr) {
        fprintf(stderr, "Error: Attempt to free a NULL pointer.\n");
        return;
    }
    free(ptr);
}

int main() {
    void *block = safe_malloc(512);
    if (block) {
        printf("Memory allocated successfully.\n");
        safe_free(block);
        printf("Memory freed successfully.\n");
    }

    // Test invalid cases
    safe_free(NULL);
    safe_malloc(0);
    safe_malloc(MAX_ALLOC + 1);

    return 0;
}
