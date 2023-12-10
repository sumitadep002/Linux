//9. Write a C program to find specific file in a specific directory using the file name passed in command line argument.

//to use opendir
#include <sys/types.h>
#include <dirent.h>


#include <stdio.h>

#include <string.h>
int main(int argc, char *argv[]) {
    char *directory_path;
    char *file_name;
    DIR *directory;
    struct dirent *entry;

    if (argc != 3) {
        printf("Usage: %s <file_name> <directory path>\n", argv[0]);
        return 1;
    }

    file_name = argv[1];
    directory_path = argv[2];  // default to current directory

    directory = opendir(directory_path);

    if (directory == NULL) {
        printf("Error while opening directory\n");
        return 0;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, file_name) == 0) {
            printf("File found: %s/%s\n", directory_path, file_name);
            closedir(directory);
            return 0;
        }
    }

    printf("File not found\n");
    closedir(directory);

    return 0;
}

