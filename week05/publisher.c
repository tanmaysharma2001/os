#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

// <WRITE YOUR CODE HERE>
int main(int argc, char* argv[]) {
    int fd;

    //FIFO file path
    char * myfifo = "/tmp/ex1";

    // writing permission in mkfifo
    mkfifo(myfifo, 0666);

    char message[200];
    int n = atoi(argv[1]);

    fd = open(myfifo, O_WRONLY);

    while(1) {

        // enter the message
        fgets(message, 200, stdin);

        for (int i = 0; i < n; i++) {
            write(fd, message, strlen(message) + 1);
            sleep(n);
        }

    }

    close(fd);

    return 0;
}






// mkfifo reference 
// https://man7.org/linux/man-pages/man3/mkfifo.3.html