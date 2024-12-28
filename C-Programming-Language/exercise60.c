#include <stdio.h>

// Pointer version of reverse
void reverse_ptr(char *s) {
    char *end = s;
    while (*end)  // Move to the end of the string
        end++;
    end--;  // Move back to the last valid character
    
    while (s < end) {
        char temp = *s;
        *s = *end;
        *end = temp;
        s++;  // Increment s after the assignment
        end--;  // Decrement end after the assignment
    }
}

int main() {
    // Declare the string
    char s[] = "Hello, World";

    // Call reverse_ptr to reverse the string
    reverse_ptr(s);
    
    // Print the reversed string
    printf("Reversed string: %s\n", s);
    
    return 0;
}
