#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof_extended(char s[]) {
    double val, power;
    int i, sign, exp_sign, exponent;

    // Initialize variables
    val = 0.0;  // The value to return
    power = 1.0; // To handle the decimal point
    sign = 1;    // Positive sign by default
    exponent = 0; // Exponent to be added after parsing

    // Skip leading whitespaces
    for (i = 0; isspace(s[i]); i++);

    // Handle sign of the number
    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Parse the integer part before the decimal point
    for (; isdigit(s[i]); i++) {
        val = val * 10.0 + (s[i] - '0');
    }

    // Parse the decimal part (if any)
    if (s[i] == '.') {
        i++;
        for (power = 1.0; isdigit(s[i]); i++) {
            val = val * 10.0 + (s[i] - '0');
            power *= 10.0;
        }
    }

    // Apply the decimal scaling
    val = sign * val / power;

    // Handle the exponent part (e or E)
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        // Handle optional sign of the exponent
        exp_sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            exp_sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Parse the exponent
        for (exponent = 0; isdigit(s[i]); i++) {
            exponent = exponent * 10 + (s[i] - '0');
        }

        // Adjust the value based on the exponent
        val *= pow(10.0, exp_sign * exponent);
    }

    return val;
}

int main() {
    char s[] = "123.45e-6";
    printf("The value of '%s' is %g\n", s, atof_extended(s));
    return 0;
}
