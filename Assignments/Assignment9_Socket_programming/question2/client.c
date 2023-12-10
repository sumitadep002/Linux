<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./client <server_ip> <port_number>\n");
        return 1;
    }

    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(client_socket);
        return 1;
    }

    printf("Connected to server at %s:%s\n", argv[1], argv[2]);

    while (1) {
        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));

        // Read input from user
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Send the message to server
        send(client_socket, buffer, strlen(buffer), 0);

        // If user enters "exit", close the client socket and exit the loop
        if (strcmp(buffer, "exit\n") == 0) {
            printf("Closing connection...\n");
            close(client_socket);
            break;
        }

        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));

        // Receive message from server
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            perror("Error receiving message from server");
            close(client_socket);
            return 1;
        }

        printf("Server: %s", buffer);
    }

    return 0;
}

=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./client <server_ip> <port_number>\n");
        return 1;
    }

    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(client_socket);
        return 1;
    }

    printf("Connected to server at %s:%s\n", argv[1], argv[2]);

    while (1) {
        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));

        // Read input from user
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Send the message to server
        send(client_socket, buffer, strlen(buffer), 0);

        // If user enters "exit", close the client socket and exit the loop
        if (strcmp(buffer, "exit\n") == 0) {
            printf("Closing connection...\n");
            close(client_socket);
            break;
        }

        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));

        // Receive message from server
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            perror("Error receiving message from server");
            close(client_socket);
            return 1;
        }

        printf("Server: %s", buffer);
    }

    return 0;
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
