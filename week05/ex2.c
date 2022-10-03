#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <string.h>

struct Thread
{
    int id;
    int i;
    char message[256];
};

void *routine(void *args)
{
    struct Thread* currentThread = (struct Thread*) args;

    printf("Thread id: %d says: %s\n", currentThread->id, currentThread->message);

    return 0;

}

int main()
{
    int n;
    scanf("%d", &n);

    struct Thread threads[n];

    for (int i = 0; i < n; i++)
    {
        struct Thread thread;

        thread.i = i;
        thread.id = i + 1;
        char str1[] = "Hello from thread ";
        char str2[10];
        sprintf(str2, "%d", i);
        strcat(str1, str2);
        strcpy(thread.message, str1);

        threads[i] = thread;
    }

    pthread_t pthreads[n];

    for (int i = 0; i < n; i++)
    {
        if (pthread_create(&pthreads[i], NULL, &routine, &threads[i]) != 0)
        {
            printf("Failed to create a thread!");
            return EXIT_SUCCESS;
        }
        printf("Thread %d is created.\n", i);
        pthread_join(pthreads[i], NULL);

    }

    return EXIT_SUCCESS;
}
