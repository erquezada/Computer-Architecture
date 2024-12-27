#include <stdio.h>
#include "draw.h" // project-related declarations

int main() 
{
    puts("Welcome!");

    int running = 1; // Flag for the main loop
    while (running) {
        fputs("Select a shape to print (Triangle = t, Square = s, Chars = c, CustomChars = k, Arrow = a) or 'q' to quit\n> ", stdout);
        fflush(stdout); // Ensure prompt is displayed immediately

        int c;
        while ((c = getchar()) == '\n'); // Skip newlines

        switch (c) {
        case 't':
            puts("You selected triangle:");
            print_triangle(5, 7);
            break;
        case 's':
            puts("You selected square:");
            print_square(5, 5);
            break;
        case 'c':
            puts("You selected chars:");
            for (char ch = 'A'; ch < 'D'; ch++)
                print_char_11x16(ch);
            break;
        case 'k':
            puts("You selected custom characters:");
            for (char ch = 'A'; ch < 'D'; ch++)
                print_char_5x7(ch);
            break;
        case 'a':
            puts("You selected arrow:");
            print_triangle(5, 7);
            print_square(9, 7);
            break;
        case 'q':
            puts("Bye!");
            running = 0; // Exit the loop
            break;
        default:
            printf("Unrecognized option '%c', please try again!\n", c);
        }
    }

    return 0;
}
