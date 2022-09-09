#include <stdio.h>
#include <string.h>

int count(char *inputString, char c);
void countAll(char *inputString);

int count(char *inputString, char c) {
    
    int freq = 0;

    for(int i = 0; i < strlen(inputString); i++) {
        if(inputString[i] == c) {
            freq++;
        }
    }

    return freq;
}

void countAll(char *inputString) {

    for(int i = 0; i < strlen(inputString) - 1; i++) {
        if(inputString[i] == '-') {
            continue;
        }
        printf("%c: ", inputString[i]);
        int freq = 1;
        for(int j = i + 1; j < strlen(inputString) - 1; j++) {
            if(inputString[i] == inputString[j]) {
                inputString[j] = '-';
                freq++;
            }
        }
        printf("%d ", freq);
    }

}

int main() {

    printf("Enter the string: ");
    char in[100];

    fgets(in, sizeof(in), stdin);

    printf("Enter the character: ");
    char c;

    scanf("%c", &c);

    int result = count(in, c);

    printf("%d\n", result);

    countAll(in);

}