#include <stdio.h>
#include <string.h>

int main()
{
    char in[256];
    printf("Enter a String : ");
    // fgets(in, sizeof(in), stdin);

    char c;

    int i = 0;
    while(scanf("%c", &c) && c != '\n') {
        in[i] = c;
        i++;
    }

    // printf("%s\n", in);
    
    printf("The string in reverse is: ");

    int flag = 0;

    for (int i = strlen(in) - 1; i >= 0; i--)
    {
        if(flag == 1) {
            putchar(in[i]);
        }
        else {
            if(in[i] == '.') {
                flag = 1;
            }
        }
    }
    printf("\n");
    return 0;
}