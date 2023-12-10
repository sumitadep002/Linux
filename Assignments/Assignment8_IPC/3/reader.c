<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    int numStrings;
    char strings[MAX_STRING_LENGTH][MAX_STRING_LENGTH];
} SharedMemory;

void printMemoryAddresses(SharedMemory *shm) {
    printf("Memory addresses of reversed strings in shared memory:\n");
    for (int i = 0; i < shm->numStrings; i++) {
        printf("%s: %p\n", shm->strings[i], shm->strings[i]);
    }
}

void reverseStrings(SharedMemory *shm) {
    for (int i = 0; i < shm->numStrings; i++) {
        int len = strlen(shm->strings[i]);
        for (int j = 0; j < len / 2; j++) {
            char temp = shm->strings[i][j];
            shm->strings[i][j] = shm->strings[i][len - 1 - j];
            shm->strings[i][len - 1 - j] = temp;
        }
    }
}

int main() {
    // Create a unique key for shared memory
    key_t key = ftok("shared_memory_key", 1);
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    // Get the shared memory segment created by the first program
    int shmid = shmget(key, sizeof(SharedMemory), 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach the shared memory segment to the process's address space
    SharedMemory *shm = (SharedMemory *) shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        return 1;
    }

    printf("Number of strings read from shared memory: %d\n", shm->numStrings);

    reverseStrings(shm);

    printf("Strings reversed and stored in shared memory at address: %p\n", shm);

    printMemoryAddresses(shm);

    // Detach the shared memory segment from the process's address space
    if (shmdt(shm) == -1) {
        perror("shmdt");
        return 1;
    }

    return 0;
}

=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    int numStrings;
    char strings[MAX_STRING_LENGTH][MAX_STRING_LENGTH];
} SharedMemory;

void printMemoryAddresses(SharedMemory *shm) {
    printf("Memory addresses of reversed strings in shared memory:\n");
    for (int i = 0; i < shm->numStrings; i++) {
        printf("%s: %p\n", shm->strings[i], shm->strings[i]);
    }
}

void reverseStrings(SharedMemory *shm) {
    for (int i = 0; i < shm->numStrings; i++) {
        int len = strlen(shm->strings[i]);
        for (int j = 0; j < len / 2; j++) {
            char temp = shm->strings[i][j];
            shm->strings[i][j] = shm->strings[i][len - 1 - j];
            shm->strings[i][len - 1 - j] = temp;
        }
    }
}

int main() {
    // Create a unique key for shared memory
    key_t key = ftok("shared_memory_key", 1);
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    // Get the shared memory segment created by the first program
    int shmid = shmget(key, sizeof(SharedMemory), 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach the shared memory segment to the process's address space
    SharedMemory *shm = (SharedMemory *) shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        perror("shmat");
        return 1;
    }

    printf("Number of strings read from shared memory: %d\n", shm->numStrings);

    reverseStrings(shm);

    printf("Strings reversed and stored in shared memory at address: %p\n", shm);

    printMemoryAddresses(shm);

    // Detach the shared memory segment from the process's address space
    if (shmdt(shm) == -1) {
        perror("shmdt");
        return 1;
    }

    return 0;
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
