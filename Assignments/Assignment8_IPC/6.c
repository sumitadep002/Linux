<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PIPE_NAME "my_pipe" // Name of the named pipe

// Structure for storing name, address, and phone number
struct Contact {
    char name[50];
    char address[100];
    char phone[15];
};

int main() {
    int pipe_fd;
    pid_t child_pid;
    struct Contact my_contact; // Structure to be copied

    // Create a named pipe
    if (mkfifo(PIPE_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    // Create a child process for writing to the pipe
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process (Writer)
        ssize_t bytes_written;
        strcpy(my_contact.name, "sumit");
        strcpy(my_contact.address, "khambhatm anand, gujarat");
        strcpy(my_contact.phone, "46165198165");

        // Open the named pipe for writing
        pipe_fd = open(PIPE_NAME, O_WRONLY);
        if (pipe_fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Write the structure to the pipe
        bytes_written = write(pipe_fd, &my_contact, sizeof(struct Contact));
        if (bytes_written == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Close the named pipe
        close(pipe_fd);
    } else {
        // Create another child process for reading from the pipe
        child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (child_pid == 0) {
            // Child process (Reader)
            ssize_t bytes_read;
            struct Contact received_contact;

            // Open the named pipe for reading
            pipe_fd = open(PIPE_NAME, O_RDONLY);
            if (pipe_fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }

            // Read the structure from the pipe
            bytes_read = read(pipe_fd, &received_contact, sizeof(struct Contact));
            if (bytes_read > 0) {
                printf("Received Contact:\n");
                printf("Name: %s\n", received_contact.name);
                printf("Address: %s\n", received_contact.address);
                printf("Phone: %s\n", received_contact.phone);
            } else if (bytes_read == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // Close the named pipe
            close(pipe_fd);
        } else {
            // Parent process
            // Wait for both child processes to complete
            wait(NULL);
            wait(NULL);

            // Remove the named pipe
            if (unlink(PIPE_NAME) == -1) {
                perror("unlink");
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}

=======
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PIPE_NAME "my_pipe" // Name of the named pipe

// Structure for storing name, address, and phone number
struct Contact {
    char name[50];
    char address[100];
    char phone[15];
};

int main() {
    int pipe_fd;
    pid_t child_pid;
    struct Contact my_contact; // Structure to be copied

    // Create a named pipe
    if (mkfifo(PIPE_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    // Create a child process for writing to the pipe
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process (Writer)
        ssize_t bytes_written;
        strcpy(my_contact.name, "sumit");
        strcpy(my_contact.address, "khambhatm anand, gujarat");
        strcpy(my_contact.phone, "46165198165");

        // Open the named pipe for writing
        pipe_fd = open(PIPE_NAME, O_WRONLY);
        if (pipe_fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Write the structure to the pipe
        bytes_written = write(pipe_fd, &my_contact, sizeof(struct Contact));
        if (bytes_written == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Close the named pipe
        close(pipe_fd);
    } else {
        // Create another child process for reading from the pipe
        child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (child_pid == 0) {
            // Child process (Reader)
            ssize_t bytes_read;
            struct Contact received_contact;

            // Open the named pipe for reading
            pipe_fd = open(PIPE_NAME, O_RDONLY);
            if (pipe_fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }

            // Read the structure from the pipe
            bytes_read = read(pipe_fd, &received_contact, sizeof(struct Contact));
            if (bytes_read > 0) {
                printf("Received Contact:\n");
                printf("Name: %s\n", received_contact.name);
                printf("Address: %s\n", received_contact.address);
                printf("Phone: %s\n", received_contact.phone);
            } else if (bytes_read == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // Close the named pipe
            close(pipe_fd);
        } else {
            // Parent process
            // Wait for both child processes to complete
            wait(NULL);
            wait(NULL);

            // Remove the named pipe
            if (unlink(PIPE_NAME) == -1) {
                perror("unlink");
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
