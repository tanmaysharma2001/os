#include <stdio.h>
#include <string.h>

int isConvertible(long long int x, int s) {
    char strring[256];
    int lengthOfString = sprintf(strring, "%lld", x);

    int flag = 1;

    for(int i = 0; i < strlen(strring); i++) {
        int currentNumber = strring[i] - '0';
        if(currentNumber >= s) {
            flag = 0;
            break;
        }
    }

    return flag;
}

void convert(long long int x, int s, int t)
{

    if(!isConvertible(x, s)) {
        printf("Cannot Convert!\n");
        return;
    }

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