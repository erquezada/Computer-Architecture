#include <stdio.h>

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

int main() {
    float temp_fahrenheit = 100.0;
    float temp_celsius = 37.78;

    printf("%.2f Fahrenheit is %.2f Celsius\n", temp_fahrenheit, fahrenheit_to_celsius(temp_fahrenheit));
    printf("%.2f Celsius is %.2f Fahrenheit\n", temp_celsius, celsius_to_fahrenheit(temp_celsius));

    return 0;
}
