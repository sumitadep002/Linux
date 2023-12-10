<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 5

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./server <port_number>\n");
        return 1;
    }

    int server_socket, client_sockets[MAX_CLIENTS], max_clients = MAX_CLIENTS;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    int port = atoi(argv[1]);

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        close(server_socket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, max_clients) < 0) {
        perror("Error listening for connections");
        close(server_socket);
        return 1;
    }

    printf("Server started on port %d\n", port);

    int connected_clients = 0;
    int i;
    for (i = 0; i < max_clients; i++) {
        client_sockets[i] = 0;
    }

    while (1) {
        // Accept incoming connection from a client
        int new_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len);
        if (new_socket < 0) {
            perror("Error accepting connection");
            close(server_socket);
            return 1;
        }

        // Add the new client socket to the array
        for (i = 0; i < max_clients; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_socket;
                connected_clients++;
                printf("Client %d connected\n", i+1);
                break;
            }
        }

        // If maximum number of clients are connected, reject new connections
        if (connected_clients >= max_clients) {
            char reject_msg[] = "Maximum number of clients connected. Please try again later.\n";
            send(new_socket, reject_msg, strlen(reject_msg), 0);
            close(new_socket);
            printf("Maximum number of clients connected. New connection rejected.\n");
        }
    }

    // Close all client sockets
    for (i = 0; i < max_clients; i++) {
        if (client_sockets[i] > 0) {
            close(client_sockets[i]);
        }
    }

    // Close the server socket
    close(server_socket);

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
#define MAX_CLIENTS 5

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./server <port_number>\n");
        return 1;
    }

    int server_socket, client_sockets[MAX_CLIENTS], max_clients = MAX_CLIENTS;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    int port = atoi(argv[1]);

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        close(server_socket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, max_clients) < 0) {
        perror("Error listening for connections");
        close(server_socket);
        return 1;
    }

    printf("Server started on port %d\n", port);

    int connected_clients = 0;
    int i;
    for (i = 0; i < max_clients; i++) {
        client_sockets[i] = 0;
    }

    while (1) {
        // Accept incoming connection from a client
        int new_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len);
        if (new_socket < 0) {
            perror("Error accepting connection");
            close(server_socket);
            return 1;
        }

        // Add the new client socket to the array
        for (i = 0; i < max_clients; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_socket;
                connected_clients++;
                printf("Client %d connected\n", i+1);
                break;
            }
        }

        // If maximum number of clients are connected, reject new connections
        if (connected_clients >= max_clients) {
            char reject_msg[] = "Maximum number of clients connected. Please try again later.\n";
            send(new_socket, reject_msg, strlen(reject_msg), 0);
            close(new_socket);
            printf("Maximum number of clients connected. New connection rejected.\n");
        }
    }

    // Close all client sockets
    for (i = 0; i < max_clients; i++) {
        if (client_sockets[i] > 0) {
            close(client_sockets[i]);
        }
    }

    // Close the server socket
    close(server_socket);

    return 0;
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
