#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void minprintf(char *fmt, ...) {
    va_list ap;  // Points to each unnamed argument in turn
    char *p, *sval;
    int ival;
    double dval;
    unsigned uval;
    
    va_start(ap, fmt);  // Make ap point to the 1st unnamed argument

    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        switch (*++p) {
        case 'd':  // Handle signed integer (%d)
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        
        case 'u':  // Handle unsigned integer (%u)
            uval = va_arg(ap, unsigned);
            printf("%u", uval);
            break;

        case 'f':  // Handle floating point number (%f)
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;

        case 's':  // Handle string (%s)
            for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;

        case 'c':  // Handle character (%c)
            ival = va_arg(ap, int);  // Characters are promoted to int
            putchar(ival);
            break;

        case 'x':  // Handle hexadecimal (lowercase) (%x)
            ival = va_arg(ap, int);
            printf("%x", ival);
            break;

        case 'X':  // Handle hexadecimal (uppercase) (%X)
            ival = va_arg(ap, int);
            printf("%X", ival);
            break;

        case 'p':  // Handle pointer address (%p)
            sval = va_arg(ap, char *);
            printf("%p", sval);
            break;

        case '%':  // Handle percent sign (%%)
            putchar('%');
            break;

        default:
            putchar('%');
            putchar(*p);  // Print unsupported specifiers literally
            break;
        }
    }

    va_end(ap);  // Clean up when done
}

int main() {
    int i = 42;
    double d = 3.14159;
    char *str = "Hello, World!";
    
    minprintf("Integer: %d\n", i);
    minprintf("Unsigned: %u\n", i);
    minprintf("Floating point: %f\n", d);
    minprintf("String: %s\n", str);
    minprintf("Character: %c\n", 'A');
    minprintf("Hexadecimal (lower): %x\n", i);
    minprintf("Hexadecimal (upper): %X\n", i);
    minprintf("Pointer address: %p\n", str);
    minprintf("Literal percent: %%\n");

    return 0;
}
