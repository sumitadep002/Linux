<<<<<<< HEAD
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "myfifo" // Name of the named FIFO
#define BUFFER_SIZE 1024   // Buffer size for reading/writing data

int main() {
    int fd1, fd2, bytesRead, bytesWritten;
    char buffer[BUFFER_SIZE];

    // Create the named FIFO
    mkfifo(FIFO_NAME, 0666);
int 
    // Open file1 for reading
    fd1 = open("file1.txt", O_RDONLY);
    if (fd1 == -1) {
        perror("Error opening file1");
        return 1;
    }

    // Open file2 for writing
    fd2 = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd2 == -1) {
        perror("Error opening file2");
        close(fd1);
        unlink(FIFO_NAME);
        return 1;
    }

    // Open the named FIFO for reading
    int fifo_fd = open(FIFO_NAME, O_RDONLY);
    if (fifo_fd == -1) {
        perror("Error opening named FIFO");
        close(fd1);
        close(fd2);
        unlink(FIFO_NAME);
        return 1;
    }

    // Copy data from file1 to file2 using the named FIFO
    while ((bytesRead = read(fd1, buffer, sizeof(buffer))) > 0) {
        // Write data to file2
        bytesWritten = write(fd2, buffer, bytesRead);
        if (bytesWritten == -1) {
            perror("Error writing to file2");
            close(fd1);
            close(fd2);
            close(fifo_fd);
            unlink(FIFO_NAME);
            return 1;
        }

        // Write data to the named FIFO
        bytesWritten = write(fifo_fd, buffer, bytesRead);
        if (bytesWritten == -1) {
            perror("Error writing to named FIFO");
            close(fd1);
            close(fd2);
            close(fifo_fd);
            unlink(FIFO_NAME);
            return 1;
        }
    }

    // Close file descriptors
    close(fd1);
    close(fd2);
    close(fifo_fd);

    // Remove the named FIFO
    unlink(FIFO_NAME);

    printf("File contents copied successfully from file1 to file2 using named FIFO.\n");

    return 0;
}

=======
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "myfifo" // Name of the named FIFO
#define BUFFER_SIZE 1024   // Buffer size for reading/writing data

int main() {
    int fd1, fd2, bytesRead, bytesWritten;
    char buffer[BUFFER_SIZE];

    // Create the named FIFO
    mkfifo(FIFO_NAME, 0666);
int 
    // Open file1 for reading
    fd1 = open("file1.txt", O_RDONLY);
    if (fd1 == -1) {
        perror("Error opening file1");
        return 1;
    }

    // Open file2 for writing
    fd2 = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd2 == -1) {
        perror("Error opening file2");
        close(fd1);
        unlink(FIFO_NAME);
        return 1;
    }

    // Open the named FIFO for reading
    int fifo_fd = open(FIFO_NAME, O_RDONLY);
    if (fifo_fd == -1) {
        perror("Error opening named FIFO");
        close(fd1);
        close(fd2);
        unlink(FIFO_NAME);
        return 1;
    }

    // Copy data from file1 to file2 using the named FIFO
    while ((bytesRead = read(fd1, buffer, sizeof(buffer))) > 0) {
        // Write data to file2
        bytesWritten = write(fd2, buffer, bytesRead);
        if (bytesWritten == -1) {
            perror("Error writing to file2");
            close(fd1);
            close(fd2);
            close(fifo_fd);
            unlink(FIFO_NAME);
            return 1;
        }

        // Write data to the named FIFO
        bytesWritten = write(fifo_fd, buffer, bytesRead);
        if (bytesWritten == -1) {
            perror("Error writing to named FIFO");
            close(fd1);
            close(fd2);
            close(fifo_fd);
            unlink(FIFO_NAME);
            return 1;
        }
    }

    // Close file descriptors
    close(fd1);
    close(fd2);
    close(fifo_fd);

    // Remove the named FIFO
    unlink(FIFO_NAME);

    printf("File contents copied successfully from file1 to file2 using named FIFO.\n");

    return 0;
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
