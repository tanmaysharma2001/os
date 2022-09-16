#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(const int* const p) {
    for(int i = 0; i < 5; i++) {
        int* value = (int *)(p+i);
        *value = 2022 - *value;
    }
}

int main() {
    const int x = 10;

    const int* q = &x;

    const int* const p = (int *)malloc(5*sizeof(int));

    for(int i = 0; i < 5; i++) {
        int* value = (int *) (p+i);
        *value = x;
    }

    printf("Enter the ages:\n");

    for(int i = 0; i < 5; i++) {
        int value;
        scanf("%d", &value);

        int* cellValue = (int *)(p+i);
        *cellValue = value;
    }

    foo(p);

    for(int i = 0; i < 5; i++) {
        printf("Birthyear of %d: %d\n", (i+1), *(p+i));
    }

    free((int *)p);

    return 0;

}