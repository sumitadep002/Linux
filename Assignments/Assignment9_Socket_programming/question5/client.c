<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./client <server_ip_address> <server_port_number>\n");
        return 1;
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

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
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(client_socket);
        return 1;
    }

    printf("Connected to server at %s:%d\n", server_ip, server_port);

    while (1) {
        // Send message to server
        printf("Client: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
            perror("Error sending message to server");
            close(client_socket);
            return 1;
        }

        if (strcmp(buffer, "exit\n") == 0) {
            printf("Disconnected from server\n");
            break;
        }

        // Receive message from server
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
            perror("Error receiving message from server");
            close(client_socket);
            return 1;
        }

        printf("Server: %s", buffer);
    }

    // Close the client socket
    close(client_socket);

    return 0;
}

=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./client <server_ip_address> <server_port_number>\n");
        return 1;
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

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
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(client_socket);
        return 1;
    }

    printf("Connected to server at %s:%d\n", server_ip, server_port);

    while (1) {
        // Send message to server
        printf("Client: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
            perror("Error sending message to server");
            close(client_socket);
            return 1;
        }

        if (strcmp(buffer, "exit\n") == 0) {
            printf("Disconnected from server\n");
            break;
        }

        // Receive message from server
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
            perror("Error receiving message from server");
            close(client_socket);
            return 1;
        }

        printf("Server: %s", buffer);
    }

    // Close the client socket
    close(client_socket);

    return 0;
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
