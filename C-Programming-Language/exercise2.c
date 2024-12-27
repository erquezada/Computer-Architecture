#include <stdio.h>

// Exercise 1-1: Experimenting with missing parts

// Uncommenting the next line will cause an error due to missing #include <stdio.h>
// #include <stdio.h>

// Missing return type for main (will work in some compilers but gives warning)
int main() {  // Uncommenting 'int' will make the program better
    // Uncommenting the next line will cause an error since printf is undefined without #include <stdio.h>
    // printf("hello, ");

    // Leaving out printf entirely will cause no output
    // printf("hello, ");
    printf("hello, ");
    printf("world\n");

    // Missing return 0; will still work in some compilers but is bad practice
    // return 0; // Uncomment this to make the program proper in the C standard

// Exercise 1-2: Experimenting with \c (invalid escape sequence)
    printf("hello, world\c\n"); // \c is not a valid escape sequence
    // The program will either give a warning or print "\c" literally in the output

    return 0;
}
