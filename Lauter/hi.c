#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ELEMENTS 100

// Function to check if a string is a palindrome
bool is_palindrome(const char* str) {
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Function to find the longest palindromic substring in a given string
char* find_longest_palindrome(const char* str) {
    int length = strlen(str);
    if (length == 0) return NULL;
    
    int maxLength = 1, start = 0;
    bool table[MAX_ELEMENTS][MAX_ELEMENTS] = {false};

    for (int i = 0; i < length; i++) {
        table[i][i] = true;
    }

    for (int i = 0; i < length - 1; i++) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= length; k++) {
        for (int i = 0; i < length - k + 1; i++) {
            int j = i + k - 1;
            if (table[i + 1][j - 1] && str[i] == str[j]) {
                table[i][j] = true;
                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    char* longestPalindrome = malloc((maxLength + 1) * sizeof(char));
    memcpy(longestPalindrome, str + start, maxLength);
    longestPalindrome[maxLength] = '\0';

    return longestPalindrome;
}

// Function to count the total number of palindromic substrings
int count_palindromic_substrings(const char* str) {
    int length = strlen(str);
    bool table[MAX_ELEMENTS][MAX_ELEMENTS] = {false};
    int count = 0;

    for (int i = 0; i < length; i++) {
        table[i][i] = true;
        count++;
    }

    for (int i = 0; i < length - 1; i++) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            count++;
        }
    }

    for (int k = 3; k <= length; k++) {
        for (int i = 0; i < length - k + 1; i++) {
            int j = i + k - 1;
            if (table[i + 1][j - 1] && str[i] == str[j]) {
                table[i][j] = true;
                count++;
            }
        }
    }

    return count;
}

// Function to find all unique palindromic substrings
void find_all_unique_palindromes(const char* str) {
    int length = strlen(str);
    bool table[MAX_ELEMENTS][MAX_ELEMENTS] = {false};

    for (int i = 0; i < length; i++) {
        table[i][i] = true;
        printf("%c\n", str[i]);
    }

    for (int i = 0; i < length - 1; i++) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            printf("%.*s\n", 2, str + i);
        }
    }

    for (int k = 3; k <= length; k++) {
        for (int i = 0; i < length - k + 1; i++) {
            int j = i + k - 1;
            if (table[i + 1][j - 1] && str[i] == str[j]) {
                table[i][j] = true;
                printf("%.*s\n", k, str + i);
            }
        }
    }
}

int main() {
    // Test cases for the additional functions
    const char* test_string = "babad";

    printf("Input: \"%s\"\n\n", test_string);

    // Test for longest palindromic substring
    char* longest = find_longest_palindrome(test_string);
    if (longest) {
        printf("Longest palindromic substring: \"%s\"\n", longest);
        free(longest);
    } else {
        printf("No palindromic substring found.\n");
    }

    // Test for checking if the entire string is a palindrome
    bool isWholePalindrome = is_palindrome(test_string);
    printf("Is the entire string a palindrome? %s\n", isWholePalindrome ? "Yes" : "No");

    // Test for counting total palindromic substrings
    int palindromeCount = count_palindromic_substrings(test_string);
    printf("Total number of palindromic substrings: %d\n", palindromeCount);

    // Test for finding all unique palindromic substrings
    printf("All unique palindromic substrings:\n");
    find_all_unique_palindromes(test_string);

    return 0;
}
