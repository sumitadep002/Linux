<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_NUM_STRINGS 100
#define MAX_STRING_LENGTH 100

typedef struct {
    int numStrings;
    char strings[MAX_NUM_STRINGS][MAX_STRING_LENGTH];
} SharedMemory;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <numStrings> <string1> <string2> ... <stringN>\n", argv[0]);
        return 1;
    }

    int numStrings = atoi(argv[1]);
    if (numStrings <= 0 || numStrings > MAX_NUM_STRINGS) {
        printf("Invalid number of strings. Must be between 1 and %d.\n", MAX_NUM_STRINGS);
        return 1;
    }

    // Create a unique key for shared memory
    key_t key = ftok("shared_memory_key", 1);
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    // Create a shared memory segment
    int shmid = shmget(key, sizeof(SharedMemory), IPC_CREAT | 0666);
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

    // Write the number of strings and strings to the shared memory segment
    shm->numStrings = numStrings;
    for (int i = 0; i < numStrings; i++) {
        strncpy(shm->strings[i], argv[i + 2], MAX_STRING_LENGTH - 1);
        shm->strings[i][MAX_STRING_LENGTH - 1] = '\0';
    }

    printf("Number of strings written to shared memory: %d\n", numStrings);

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

#define MAX_NUM_STRINGS 100
#define MAX_STRING_LENGTH 100

typedef struct {
    int numStrings;
    char strings[MAX_NUM_STRINGS][MAX_STRING_LENGTH];
} SharedMemory;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <numStrings> <string1> <string2> ... <stringN>\n", argv[0]);
        return 1;
    }

    int numStrings = atoi(argv[1]);
    if (numStrings <= 0 || numStrings > MAX_NUM_STRINGS) {
        printf("Invalid number of strings. Must be between 1 and %d.\n", MAX_NUM_STRINGS);
        return 1;
    }

    // Create a unique key for shared memory
    key_t key = ftok("shared_memory_key", 1);
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    // Create a shared memory segment
    int shmid = shmget(key, sizeof(SharedMemory), IPC_CREAT | 0666);
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

    // Write the number of strings and strings to the shared memory segment
    shm->numStrings = numStrings;
    for (int i = 0; i < numStrings; i++) {
        strncpy(shm->strings[i], argv[i + 2], MAX_STRING_LENGTH - 1);
        shm->strings[i][MAX_STRING_LENGTH - 1] = '\0';
    }

    printf("Number of strings written to shared memory: %d\n", numStrings);

    // Detach the shared memory segment from the process's address space
    if (shmdt(shm) == -1) {
        perror("shmdt");
        return 1;
    }

    return 0;
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
