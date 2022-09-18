#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE_DIRECTORIES 8
#define MAX_SIZE_FILES 256
#define MAX_SIZE_NAME 63
#define MAX_SIZE_DATA 1024
#define MAX_SIZE_PATH 2048

struct File {
    int id;
    char name[MAX_SIZE_NAME];
    int size;
    char data[MAX_SIZE_DATA];
    char path[MAX_SIZE_PATH];
};

// Operations on Files
void add_to_file(struct File *file, const char *str);

void append_to_file(struct File *file, const char *str);

void pwd_file(struct File *file);

void add_to_file(struct File *file, const char *str) {
    strncpy(file->data, str, sizeof(file->data) / sizeof(file->data[0]));
    file->size = strlen(file->data);
}

void append_to_file(struct File *file, const char *str) {

    for (int j = 0; j < strlen(str); j++) {
        int size = strlen(file->data);

        file->data[size] = str[j];
    }
}

void pwd_file(struct File *file) {
    printf("%s", file->path);
}



struct Directory {
    struct File *files[MAX_SIZE_FILES];
    struct Directory *sub_directories[MAX_SIZE_DIRECTORIES];
    int nf;
    int nd;
    char path[MAX_SIZE_PATH];
};



void appendTwoStrings(const char* string1, const char* string2, char* result) {

    int size = strlen(result);

    for(int i = 0; i < strlen(string1); i++) {
        result[size] = string1[i];
        size++;
    }

    for(int i = 0; i < strlen(string2); i++) {
        result[size] = string2[i];
        size++;
    }
}


// Operations on Directories

// while adding the file to a directory, we can also
// get the path of the file...!
void add_file(struct File *file, struct Directory *dir) {
    char path[MAX_SIZE_PATH] = {0};
    appendTwoStrings(dir->path, file->name, path);
    strncpy(file->path, path, strlen(path));
    file->id = dir->nf + 1;
    dir->files[dir->nf++] = file;
}

void pwd(struct Directory *dir) {

    for (int i = 0; i < (dir->nf); i++) {
        printf("%s%s\n", dir->path, dir->files[i]->name);
    }

    for (int i = 0; i < dir->nd; i++) {
        pwd(dir->sub_directories[i]);
    }
}



// Additional Operations

void createDirectory(struct Directory* directory, const char* dirName, const char* dirPath) {
    struct Directory dir;
    strncpy(dir.path, dirPath, strlen(dirPath));
    dir.nd = 0;
    dir.nf = 0;
    *directory = dir;
}

void createSubDirectory(struct Directory* parentDir, struct Directory* directory, const char* dirName) {
    struct Directory dir;
    dir.nf = 0;
    dir.nd = 0;
    char path[2048] = {0};
    appendTwoStrings(parentDir->path, dirName, path);
    strncpy(dir.path, path, strlen(path));
    printf("%s %s\n", dirName, dir.path);
    *directory = dir;
    parentDir->sub_directories[parentDir->nd++] = directory;
}

void create_file(struct File* file, const char* fileName) {
    struct File newFile;
    strncpy(newFile.name, fileName, strlen(fileName));
    *file = newFile;
}

int main() {

    struct Directory root;
    createDirectory(&root, "root", "/");


    struct Directory home;
    createSubDirectory(&root, &home, "home/");


    struct Directory bin;
    createSubDirectory(&root, &bin, "bin/");

    struct File bash;
    create_file(&bash, "bash");
    add_file(&bash, &bin);

    struct File ex3_1;
    create_file(&ex3_1, "ex3_1.c");
    add_to_file(&ex3_1, "int printf(const char * format, ...);");
    add_file(&ex3_1, &home);

    struct File ex3_2;
    create_file(&ex3_2, "ex3_2.c");
    add_to_file(&ex3_2, "//This is a comment in C language");
    add_file(&ex3_2, &home);

    add_to_file(&bash, "Bourne Again Shell!!");

    append_to_file(&ex3_1, "int main(){printf('Hello World!')}");

    pwd_file(&bash);

    return 0;
}