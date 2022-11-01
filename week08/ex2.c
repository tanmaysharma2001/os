// ex2
// In the operating system, si and so fields are the indication that
// the main memory has no space left, i.e., full and now the swap space will be used
// for storing the programs. But as observed from the command's result,
// the fields have values 0, indicates that the main memory is not currently full 
// (during the 10 seconds of the program) hence they are 0 and swapping will not be done.

// ex3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    // pointer to an array of 10 pointers
    int *pointer[10];

    for(int i = 0; i < 10; i++) {
        pointer[i] = (int *)malloc(10 * 1024 * 1024);

        if(pointer[i] != NULL) {
            memset(pointer[i], 0, 10*1024*1024);
        }
        sleep(1);
    }

    // need to free the memory
    for(int i = 0; i < 10; i++) {
        free(pointer[i]);
    }

    return EXIT_SUCCESS;

}