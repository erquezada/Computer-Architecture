#include <stdio.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 1000

// Stack structure for handling delimiter matching
typedef struct {
    char items[MAX_STACK_SIZE];
    int top;
} Stack;

// Stack operations
void init_stack(Stack* s) {
    s->top = -1;
}

bool is_stack_empty(Stack* s) {
    return s->top == -1;
}

bool push(Stack* s, char c) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->items[++(s->top)] = c;
        return true;
    }
    return false;
}

char pop(Stack* s) {
    if (!is_stack_empty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';  // Return null character if stack is empty
}

char peek(Stack* s) {
    if (!is_stack_empty(s)) {
        return s->items[s->top];
    }
    return '\0';  // Return null character if stack is empty
}

// Function to check if the character is a matching pair for a delimiter
bool is_matching_pair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

// Function to check if we're inside a string or a character constant
bool inside_string_or_char(const char* code, int index) {
    bool in_string = false; // Flag for string literals
    bool in_char = false;   // Flag for character constants
    for (int i = 0; i <= index; i++) {
        if (code[i] == '"' && (i == 0 || code[i - 1] != '\\')) {
            in_string = !in_string; // Toggle in_string flag
        }
        if (code[i] == '\'' && (i == 0 || code[i - 1] != '\\')) {
            in_char = !in_char; // Toggle in_char flag
        }
    }
    return in_string || in_char;
}

// Function to check for syntax errors in the input C code
void check_syntax_errors() {
    Stack stack;
    init_stack(&stack);

    int c, prev_char = '\0';
    bool in_line_comment = false;
    bool in_block_comment = false;
    int line_number = 1;

    while ((c = getchar()) != EOF) {
        // Handle line comments
        if (in_line_comment) {
            if (c == '\n') {
                in_line_comment = false; // End of line comment
            }
        }
        // Handle block comments
        else if (in_block_comment) {
            if (prev_char == '*' && c == '/') {
                in_block_comment = false; // End of block comment
            }
        }
        // Handle comment detection
        else if (prev_char == '/' && c == '/') {
            in_line_comment = true; // Start of line comment
        }
        else if (prev_char == '/' && c == '*') {
            in_block_comment = true; // Start of block comment
        }
        // Handle matching delimiters
        else if (!inside_string_or_char(&prev_char, 1)) {
            if (c == '(' || c == '[' || c == '{') {
                push(&stack, c); // Push opening delimiter onto stack
            } else if (c == ')' || c == ']' || c == '}') {
                if (is_stack_empty(&stack)) {
                    printf("Unmatched closing delimiter '%c' at line %d\n", c, line_number);
                    return;
                } else {
                    char last = pop(&stack);
                    if (!is_matching_pair(last, c)) {
                        printf("Mismatched delimiter '%c' and '%c' at line %d\n", last, c, line_number);
                        return;
                    }
                }
            }
        }

        // Handle newlines and increment line number
        if (c == '\n') {
            line_number++;
        }

        prev_char = c;
    }

    // After processing the entire code, check for any unmatched opening delimiters
    while (!is_stack_empty(&stack)) {
        char unmatched = pop(&stack);
        printf("Unmatched opening delimiter '%c'\n", unmatched);
    }
}

int main() {
    check_syntax_errors();
    return 0;
}
