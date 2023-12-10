<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>

#define MSG_SIZE 50 // Maximum size of message to be written to pipe

int main() {
    int pipefd[2];
    pid_t pid;
    char message[MSG_SIZE];

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("Failed to create pipe");
        exit(1);
    }

    // Fork a child process
    pid = fork();
    if (pid < 0) {
        perror("Failed to fork process");
        exit(1);
    } else if (pid == 0) {
        // Child process

        // Close the read end of the pipe
        close(pipefd[0]);

        // Write a message to the pipe
        char *childMessage = "Hello from child process!";
        write(pipefd[1], childMessage, MSG_SIZE);
        printf("Child process wrote: %s\n", childMessage);

        // Close the write end of the pipe
        close(pipefd[1]);

        exit(0);
    } else {
    wait(NULL);
        // Parent process

        // Close the write end of the pipe
        close(pipefd[1]);

        // Read the message from the pipe
        int bytesRead = read(pipefd[0], message, MSG_SIZE);
        printf("Parent process read: %.*s\n", bytesRead, message);

        // Close the read end of the pipe
        close(pipefd[0]);
    }

    return 0;
}

=======
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>

#define MSG_SIZE 50 // Maximum size of message to be written to pipe

int main() {
    int pipefd[2];
    pid_t pid;
    char message[MSG_SIZE];

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("Failed to create pipe");
        exit(1);
    }

    // Fork a child process
    pid = fork();
    if (pid < 0) {
        perror("Failed to fork process");
        exit(1);
    } else if (pid == 0) {
        // Child process

        // Close the read end of the pipe
        close(pipefd[0]);

        // Write a message to the pipe
        char *childMessage = "Hello from child process!";
        write(pipefd[1], childMessage, MSG_SIZE);
        printf("Child process wrote: %s\n", childMessage);

        // Close the write end of the pipe
        close(pipefd[1]);

        exit(0);
    } else {
    wait(NULL);
        // Parent process

        // Close the write end of the pipe
        close(pipefd[1]);

        // Read the message from the pipe
        int bytesRead = read(pipefd[0], message, MSG_SIZE);
        printf("Parent process read: %.*s\n", bytesRead, message);

        // Close the read end of the pipe
        close(pipefd[0]);
    }

    return 0;
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
