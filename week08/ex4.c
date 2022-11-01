#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>

int main()
{
    // pointer to an array of 10 pointers
    void *pointer[10];
    struct rusage res;

    for (int i = 0; i < 10; i++)
    {
        pointer[i] = calloc(10 * 1024 * 1024, 1);

        // if (pointer[i] != NULL)
        // {
        //     memset(pointer[i], 0, 10 * 1024 * 1024);
        // }

        getrusage(RUSAGE_SELF, &res);

        printf("Memory usage: %ld kilobytes\n", res.ru_maxrss);

        sleep(1);
    }

    // need to free the memory
    for (int i = 0; i < 10; i++)
    {
        free(pointer[i]);
    }

    return EXIT_SUCCESS;
}