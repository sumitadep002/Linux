//4. Write a C program to reverse the content of the file


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd_in, fd_out, nbytes;
    off_t end_pos;
    char buf;

    fd_in = open("4.txt", O_RDONLY);
    if (fd_in == -1) {
        perror("Error opening input file");
        return 1;
    }

    // Move the file pointer to the end of the file
    end_pos = lseek(fd_in, 0, SEEK_END);
    if (end_pos == (off_t)-1) {
    	//means file is empty
        perror("Error seeking input file");
        return 1;
    }

    // Open the output file in read-write mode
    fd_out = open("4_rev.txt", O_RDWR|O_CREAT,0600);
    if (fd_out == -1) {
        perror("Error opening output file");
        close(fd_in);
        return 1;
    }

    // read a character from the end of 4.txt store it to buf and store buf data to the 4_reversed.txt
    while (end_pos >= 0) {
        end_pos--;
        lseek(fd_in, end_pos, SEEK_SET);
        nbytes = read(fd_in, &buf, 1);
        if (nbytes == -1) {
            perror("Error reading input file");
            close(fd_in);
            close(fd_out);
            return 1;
        }
        nbytes = write(fd_out, &buf, 1);
        if (nbytes == -1) {
            perror("Error writing output file");
            close(fd_in);
            close(fd_out);
            return 1;
        }
    }

    printf("Content reversed successfully\n");

    close(fd_in);
    close(fd_out);

    return 0;
}

