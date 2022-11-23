#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>


int main() {
	DIR* root;
	
	root = opendir("/");
	
	struct dirent* currentEntry;
	
	while ((currentEntry = readdir(root)) != NULL) {
		printf("-> %s\n", currentEntry->d_name);
	}
	
}
