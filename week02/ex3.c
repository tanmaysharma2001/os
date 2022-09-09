#include <stdio.h>
#include <string.h>

void convert(long long int x, int s, int t)
{

    long long int decimal = 0;

    long long int decimalPlace = 1;
    while (x != 0)
    {
        int digit = x % 10;
        decimal += digit * decimalPlace;
        decimalPlace *= s;
        x /= 10;
    }

    char result[100];

    int index = 0;
    while (decimal != 0)
    {
        int digit = decimal % t;
        result[index] = digit + '0';
        decimal /= t;
        index++;
    }

    for(int i = strlen(result) - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    puts("");
}

int main()
{
    long long int x;
    int t;
    int s;

    scanf("%lld %d %d", &x, &s, &t);

    convert(x, s, t);
}