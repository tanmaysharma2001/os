#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>

int main() {
	int *pointer[10];
	struct rusage res;

	for(int i = 0; i < 10; i++) {
		pointer[i] = malloc(10 * 1024 * 1024);
		if(pointer[i] != NULL) {
			memset(pointer[i], 0, 10*1024*1024);
		}
		getrusage(RUSAGE_SELF, &res);
		printf("%s: %ld\n", "maximum resident set size", res
	}
}
