#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_LENGTH 20

struct file {
    char name[MAX_LENGTH];
    ino_t inodeNumber;
};

int main() {

    DIR* directory = opendir("/home/tanmay/Tanmay/os/week10/tmp");

    if(directory == NULL) {
        printf("Directory doesn't exists");
        return 0;
    }

    struct dirent*  currentEntry;

    struct stat s;

    struct file files[MAX_FILES];

    for(int i = 0; i < MAX_FILES; i++) {
        files[i].inodeNumber = 0;
    }

    int index = 0;

    while((currentEntry = readdir(directory)) != NULL) {

        if(currentEntry->d_name[0] == '.') {
            continue;
        }

        struct file currentFile = {};
        strcpy(currentFile.name, currentEntry->d_name);
        currentFile.inodeNumber = currentEntry->d_ino;
        files[index] = currentFile;
        index++;
	}

    (void) closedir(directory);

    printf("FILE\tHARDLINKS\n");

    for(int i = 0; i < index; i++) {
        int currentCounter = 0;
        for(int j = 0; j < index; j++) {
//            if(j == i) {
//                continue;
//            }
            if(files[i].inodeNumber == files[j].inodeNumber) {
                currentCounter++;
            }
        }
        printf("%s\t%d\n", files[i].name, currentCounter);
    }

    return 0;
}
