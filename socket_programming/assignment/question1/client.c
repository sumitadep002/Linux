<<<<<<< HEAD
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error in socket. Exiting...");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP address of the server

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error in connection. Exiting...");
        exit(1);
    }

    // Continuous communication with server
    while (1) {
        printf("Enter a message to send to server (or 'q' to quit): ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Send data to server
        send(sockfd, buffer, strlen(buffer), 0);

        // Receive acknowledgment from server
        recv(sockfd, buffer, BUFFER_SIZE, 0);
        printf("Server: %s", buffer);

        // Check for quit command
        if (buffer[0] == 'q') {
            break;
        }
    }

    // Close the socket
    close(sockfd);
    return 0;
}
=======
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error in socket. Exiting...");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP address of the server

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error in connection. Exiting...");
        exit(1);
    }

    // Continuous communication with server
    while (1) {
        printf("Enter a message to send to server (or 'q' to quit): ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Send data to server
        send(sockfd, buffer, strlen(buffer), 0);

        // Receive acknowledgment from server
        recv(sockfd, buffer, BUFFER_SIZE, 0);
        printf("Server: %s", buffer);

        // Check for quit command
        if (buffer[0] == 'q') {
            break;
        }
    }

    // Close the socket
    close(sockfd);
    return 0;
}
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
