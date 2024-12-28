#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int len = strlen(s);
    
    // Base case: If string is empty or has one character, return
    if (len <= 1) {
        return;
    }
    
    // Swap the first and last characters
    char temp = s[0];
    s[0] = s[len - 1];
    s[len - 1] = temp;
    
    // Recursive call: Reverse the inner substring (without first and last characters)
    s[len - 1] = '\0';  // Temporarily null-terminate to avoid overflow in recursion
    reverse(s + 1);  // Recurse on the substring from the second character
    s[len - 1] = temp;  // Restore the last character
}

int main() {
    char str[] = "Hello, World!";
    
    reverse(str);
    printf("Reversed string: %s\n", str);  // Output: "!dlroW ,olleH"
    
    return 0;
}
