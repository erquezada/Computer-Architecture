#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    // Integer types
    printf("Integer types ranges:\n");

    // char (signed and unsigned)
    printf("Signed char range: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char range: 0 to %u\n", UCHAR_MAX);

    // short (signed and unsigned)
    printf("Signed short range: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short range: 0 to %u\n", USHRT_MAX);

    // int (signed and unsigned)
    printf("Signed int range: %d to %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int range: 0 to %u\n", UINT_MAX);

    // long (signed and unsigned)
    printf("Signed long range: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long range: 0 to %lu\n", ULONG_MAX);

    // Floating-point types
    printf("\nFloating-point types ranges:\n");

    // float
    printf("Float range: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("Float precision: %d digits\n", FLT_DIG);

    // double
    printf("Double range: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("Double precision: %d digits\n", DBL_DIG);

    // long double
    printf("Long double range: %Le to %Le\n", LDBL_MIN, LDBL_MAX);
    printf("Long double precision: %d digits\n", LDBL_DIG);

    return 0;
}
