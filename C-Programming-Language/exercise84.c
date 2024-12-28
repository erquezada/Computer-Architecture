#include <stdarg.h>
#include <stdio.h>

void minscanf(char *fmt, ...) {
    va_list ap;
    char *p;
    int *ival;
    double *dval;
    char *sval;
    char cval;
    
    va_start(ap, fmt);  // Make ap point to the first unnamed argument

    for (p = fmt; *p; p++) {
        if (*p != '%') {
            continue;  // Skip non-format characters
        }

        switch (*++p) {
        case 'd':  // Read an integer (%d)
            ival = va_arg(ap, int *);
            if (scanf("%d", ival) != 1) {
                printf("Invalid input for integer\n");
            }
            break;

        case 'f':  // Read a floating point number (%f)
            dval = va_arg(ap, double *);
            if (scanf("%lf", dval) != 1) {
                printf("Invalid input for float\n");
            }
            break;

        case 's':  // Read a string (%s)
            sval = va_arg(ap, char *);
            if (scanf("%s", sval) != 1) {
                printf("Invalid input for string\n");
            }
            break;

        case 'c':  // Read a character (%c)
            ival = va_arg(ap, int *);
            if (scanf("%c", &cval) != 1) {
                printf("Invalid input for char\n");
            } else {
                *ival = cval;
            }
            break;

        default:
            printf("Unsupported format specifier\n");
            break;
        }
    }

    va_end(ap);  // Clean up when done
}

int main() {
    int i;
    double d;
    char str[100];
    
    minscanf("%d %f %s", &i, &d, str);
    
    printf("Read integer: %d\n", i);
    printf("Read float: %f\n", d);
    printf("Read string: %s\n", str);
    
    return 0;
}
