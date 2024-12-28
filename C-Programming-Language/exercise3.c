#include <stdio.h>

/* Print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */
int main() {
    int fahr, celsius;
    int lower, upper, step;

    // Initialize range and step size
    lower = 0;   // lower limit of temperature scale
    upper = 300; // upper limit
    step = 20;   // step size

    // Print the heading
    printf("Fahrenheit to Celsius Conversion Table\n");
    printf("-------------------------------------\n");
    printf("Fahrenheit\tCelsius\n");

    // Calculate and print the table
    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%10d\t%7d\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
