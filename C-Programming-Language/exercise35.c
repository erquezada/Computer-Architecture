#include <stdio.h>

int binsearch(int x, int v[], int n) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = low + (high - low) / 2; // To avoid overflow in case of large values
        if (x == v[mid]) {
            return mid; // Found match
        } else {
            // One test, adjust bounds
            low = (x < v[mid]) ? low : mid + 1;   // x is less than v[mid], move high
            high = (x > v[mid]) ? high : mid - 1;  // x is greater than v[mid], move low
        }
    }

    return -1; // No match
}

int main() {
    int v[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(v) / sizeof(v[0]);
    int x = 7;
    
    int result = binsearch(x, v, n);
    
    if (result != -1) {
        printf("Found %d at index %d\n", x, result);
    } else {
        printf("%d not found\n", x);
    }

    return 0;
}
