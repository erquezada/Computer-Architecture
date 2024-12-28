#include <stdio.h>
#include <math.h>

#define VAR_COUNT 26

double variables[VAR_COUNT] = {0.0};  // 26 variables for a-z
double last_printed_value = 0.0;  // Most recent printed value

// Set the value of a variable (a-z)
void set_variable(char var, double value) {
    if (var >= 'a' && var <= 'z') {
        variables[var - 'a'] = value;
    } else {
        printf("Invalid variable name: %c\n", var);
    }
}

// Get the value of a variable (a-z)
double get_variable(char var) {
    if (var >= 'a' && var <= 'z') {
        return variables[var - 'a'];
    } else {
        printf("Invalid variable name: %c\n", var);
        return NAN;  // Return NaN for invalid variable access
    }
}

// Print the value of a variable (a-z)
void print_variable(char var) {
    double value = get_variable(var);
    if (!isnan(value)) {
        printf("%c = %.8g\n", var, value);
        last_printed_value = value;  // Update last printed value
    }
}

int main() {
    set_variable('a', 3.14);
    set_variable('b', 2.718);
    
    print_variable('a');  // Should print a = 3.14
    print_variable('b');  // Should print b = 2.718

    set_variable('c', 9.81);
    print_variable('c');  // Should print c = 9.81

    print_variable('z');  // Should print "Invalid variable name: z" if not set

    return 0;
}
