#include <stdio.h>
#include <string.h>

void pattern1(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void pattern2(int n) {
    int mid = n/2 + n%2;

    int arr[n];

    for(int i = 0; i < mid; i++) {
        arr[i] = i+1;
        arr[n-i-1] = i+1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < arr[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void pattern3(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    pattern3(n);
}