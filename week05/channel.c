#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MESSAGE_SIZE 200

int main() {
    int fd[2];

    // fd[0] -- read
    // fd[1] -- write

    if (pipe(fd) == -1) {
        puts("An error occured while opening the pipe!");
    }

    pid_t publisher = fork();

    if (publisher == 0) {
//        close(fd[0]);
        char message[MESSAGE_SIZE];
        while(1) {
            fgets(message, MESSAGE_SIZE, stdin);
            write(fd[1], &message, MESSAGE_SIZE * sizeof(char));
        }
//        close(fd[1]);
    } else {
//        close(fd[1]);
        char message[MESSAGE_SIZE];
        while(1) {
            read(fd[0], &message, MESSAGE_SIZE * sizeof(char));
            printf("Got message from child: %s", message);
        }
//        close(fd[0]);
    }

    return 0;
}



// pipe reference 
// https://man7.org/linux/man-pages/man2/pipe.2.html
