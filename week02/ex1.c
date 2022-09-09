#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int num1;
    unsigned int num2;
    long int num3;
    float num4;
    double num5;

    num1 = INT_MAX;
    num2 = USHRT_MAX;
    num3 = LONG_MAX;
    num4 = FLT_MAX;
    num5 = DBL_MAX;

    printf("%ld\n", sizeof(num1));
    printf("%d\n", num1);

    printf("%ld\n", sizeof(num2));
    printf("%d\n", num2);

    printf("%ld\n", sizeof(num3));
    printf("%ld\n", num3);

    printf("%ld\n", sizeof(num4));
    printf("%f\n", num4);

    printf("%ld\n", sizeof(num5));
    printf("%f\n", num5);

    return 0;
}