<<<<<<< HEAD
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[BUFFER_SIZE];

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error in socket. Exiting...");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the specified IP address and port number
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error in binding. Exiting...");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 1) == 0) {
        printf("Listening...\n");
    } else {
        printf("Error in listening. Exiting...\n");
        exit(1);
    }

    addr_size = sizeof(new_addr);
    // Accept a new connection
    new_sockfd = accept(sockfd, (struct sockaddr*)&new_addr, &addr_size);

    // Continuous communication with client
    while (1) {
        // Receive data from client
        recv(new_sockfd, buffer, BUFFER_SIZE, 0);
        printf("Client: %s", buffer);

        // Send acknowledgment to client
        send(new_sockfd, buffer, strlen("Server: Message received.\n"), 0);
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
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[BUFFER_SIZE];

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error in socket. Exiting...");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the specified IP address and port number
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error in binding. Exiting...");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 1) == 0) {
        printf("Listening...\n");
    } else {
        printf("Error in listening. Exiting...\n");
        exit(1);
    }

    addr_size = sizeof(new_addr);
    // Accept a new connection
    new_sockfd = accept(sockfd, (struct sockaddr*)&new_addr, &addr_size);

    // Continuous communication with client
    while (1) {
        // Receive data from client
        recv(new_sockfd, buffer, BUFFER_SIZE, 0);
        printf("Client: %s", buffer);

        // Send acknowledgment to client
        send(new_sockfd, buffer, strlen("Server: Message received.\n"), 0);
    }

    // Close the socket
    close(sockfd);
    return 0;
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
