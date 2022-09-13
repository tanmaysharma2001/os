#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long int tribonacci(int n);

long long int tribonacci(int n)
{
    long long int num1 = 0;
    long long int num2 = 1;
    long long int num3 = 1;
    long long int curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            curr = num1;
        }
        else if (i == 1)
        {
            curr = num2;
        }
        else if (i == 2)
        {
            curr = num3;
        }
        else
        {
            curr = num3 + num2 + num1;
            num1 = num2;
            num2 = num3;
            num3 = curr;
        }
    }

    return curr;
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        int n = atoi(argv[i]);
        printf("%lld\n", tribonacci(n));
    }
}