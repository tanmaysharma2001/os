#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// <WRITE YOUR CODE HERE>

int main() {
    int fd1;

    char * myfifo = "/tmp/ex1";

    mkfifo(myfifo, 0666);

    char message[200];
    fd1 = open(myfifo, O_RDONLY);
    

    while(1) {
        read(fd1, message, 200);

        printf("%s", message);
        sleep(1);
    }
    close(fd1);
    
    return 0;
}








// mkfifo reference 
// https://man7.org/linux/man-pages/man3/mkfifo.3.html