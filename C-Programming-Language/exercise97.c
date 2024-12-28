#include <stdlib.h>
#include <string.h>

void *my_calloc(size_t n, size_t size) {
    size_t total_size = n * size;
    void *ptr = malloc(total_size);

    if (ptr) {
        memset(ptr, 0, total_size); // Initialize memory to zero
    }

    return ptr;
}

int main() {
    int *arr = (int *)my_calloc(5, sizeof(int));
    if (arr) {
        for (int i = 0; i < 5; i++) {
            printf("arr[%d] = %d\n", i, arr[i]);
        }
        free(arr);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
