#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

struct Thread {
    int id;
    int i;
    char message[256];
};

int main(){

    int n;
    
	struct Thread threads[n];

	return EXIT_SUCCESS;
}
