<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024 // Size of buffer for reading/writing

int main() {
    int pipe_fd[2];
    pid_t child_pid;
    char message[] = "Hello from parent process!"; // String to be copied

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process (Reader)
        char buffer[BUFFER_SIZE];
        ssize_t bytes_read;

        // Close write end of the pipe
        close(pipe_fd[1]);

        // Read from the pipe
        bytes_read = read(pipe_fd[0], buffer, BUFFER_SIZE);
        if (bytes_read > 0) {
            printf("Received message: %.*s\n", (int)bytes_read, buffer);
        } else if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Close read end of the pipe
        close(pipe_fd[0]);
    } else {
        // Parent process (Writer)
        ssize_t bytes_written;

        // Close read end of the pipe
        close(pipe_fd[0]);

        // Write to the pipe
        bytes_written = write(pipe_fd[1], message, strlen(message));
        if (bytes_written == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Close write end of the pipe
        close(pipe_fd[1]);
    }

    return 0;
}

=======
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024 // Size of buffer for reading/writing

int main() {
    int pipe_fd[2];
    pid_t child_pid;
    char message[] = "Hello from parent process!"; // String to be copied

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process (Reader)
        char buffer[BUFFER_SIZE];
        ssize_t bytes_read;

        // Close write end of the pipe
        close(pipe_fd[1]);

        // Read from the pipe
        bytes_read = read(pipe_fd[0], buffer, BUFFER_SIZE);
        if (bytes_read > 0) {
            printf("Received message: %.*s\n", (int)bytes_read, buffer);
        } else if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Close read end of the pipe
        close(pipe_fd[0]);
    } else {
        // Parent process (Writer)
        ssize_t bytes_written;

        // Close read end of the pipe
        close(pipe_fd[0]);

        // Write to the pipe
        bytes_written = write(pipe_fd[1], message, strlen(message));
        if (bytes_written == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Close write end of the pipe
        close(pipe_fd[1]);
    }

    return 0;
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
