<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./server <port_number>\n");
        return 1;
    }

    int port_number = atoi(argv[1]);

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Bind the socket to the specified port number
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_number);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        close(server_socket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 1) < 0) {
        perror("Error listening for connections");
        close(server_socket);
        return 1;
    }

    printf("Server is listening for incoming connections on port %d\n", port_number);

    // Accept incoming connections and communicate with clients
    client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len);
    if (client_socket < 0) {
        perror("Error accepting connection");
        close(server_socket);
        return 1;
    }

    printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while (1) {
        // Receive message from client
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
            perror("Error receiving message from client");
            close(client_socket);
            close(server_socket);
            return 1;
        }

        if (strcmp(buffer, "exit") == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Client: %s", buffer);

        // Send message to client
        printf("Server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
            perror("Error sending message to client");
            close(client_socket);
            close(server_socket);
            return 1;
        }
    }

    // Close sockets
    close(client_socket);
    close(server_socket);

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
    if (argc != 2) {
        printf("Usage: ./server <port_number>\n");
        return 1;
    }

    int port_number = atoi(argv[1]);

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Bind the socket to the specified port number
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_number);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        close(server_socket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 1) < 0) {
        perror("Error listening for connections");
        close(server_socket);
        return 1;
    }

    printf("Server is listening for incoming connections on port %d\n", port_number);

    // Accept incoming connections and communicate with clients
    client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len);
    if (client_socket < 0) {
        perror("Error accepting connection");
        close(server_socket);
        return 1;
    }

    printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while (1) {
        // Receive message from client
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
            perror("Error receiving message from client");
            close(client_socket);
            close(server_socket);
            return 1;
        }

        if (strcmp(buffer, "exit") == 0) {
            printf("Client disconnected\n");
            break;
        }

        printf("Client: %s", buffer);

        // Send message to client
        printf("Server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
            perror("Error sending message to client");
            close(client_socket);
            close(server_socket);
            return 1;
        }
    }

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
