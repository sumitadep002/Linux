<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

#define SHARED_MEM_SIZE 1024 // Size of shared memory

typedef struct {
    int flag; 
    char message[SHARED_MEM_SIZE]; // Shared message
} SharedData;

int main() {
    int fd;
    SharedData* shared_data;
    pid_t child_pid;

    // Create a shared memory object
    fd = shm_open("/my_shared_memory", O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    // Set the size of the shared memory object
    if (ftruncate(fd, sizeof(SharedData)) == -1) {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    // Map the shared memory object into the process's address space
    shared_data = (SharedData*)mmap(NULL, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shared_data == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process (Reader)
        while (1) {
            if (shared_data->flag == 1) {
                // Data is available, read from shared memory and print
                printf("Received message: %s\n", shared_data->message);

                // Reset flag after reading
                shared_data->flag = 0;
            }
            sleep(1);
        }
    } else {
        // Parent process (Writer)
        while (1) {
            // Write data to shared memory
            strcpy(shared_data->message, "Hello from parent process!");
            shared_data->flag = 1;

            sleep(2);
        }
    }

    // Unmap shared memory
    if (munmap(shared_data, sizeof(SharedData)) == -1) {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    // Close shared memory object
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    // Unlink shared memory object
    if (shm_unlink("/my_shared_memory") == -1) {
        perror("shm_unlink");
        exit(EXIT_FAILURE);
    }

    return 0;
}

=======
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

#define SHARED_MEM_SIZE 1024 // Size of shared memory

typedef struct {
    int flag; 
    char message[SHARED_MEM_SIZE]; // Shared message
} SharedData;

int main() {
    int fd;
    SharedData* shared_data;
    pid_t child_pid;

    // Create a shared memory object
    fd = shm_open("/my_shared_memory", O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    // Set the size of the shared memory object
    if (ftruncate(fd, sizeof(SharedData)) == -1) {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    // Map the shared memory object into the process's address space
    shared_data = (SharedData*)mmap(NULL, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shared_data == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process (Reader)
        while (1) {
            if (shared_data->flag == 1) {
                // Data is available, read from shared memory and print
                printf("Received message: %s\n", shared_data->message);

                // Reset flag after reading
                shared_data->flag = 0;
            }
            sleep(1);
        }
    } else {
        // Parent process (Writer)
        while (1) {
            // Write data to shared memory
            strcpy(shared_data->message, "Hello from parent process!");
            shared_data->flag = 1;

            sleep(2);
        }
    }

    // Unmap shared memory
    if (munmap(shared_data, sizeof(SharedData)) == -1) {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    // Close shared memory object
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    // Unlink shared memory object
    if (shm_unlink("/my_shared_memory") == -1) {
        perror("shm_unlink");
        exit(EXIT_FAILURE);
    }

    return 0;
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
