<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 5

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./display_ips <ip_address> <port_number>\n");
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Bind the socket to the specified IP address and port number
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    server_addr.sin_port = htons(port_number);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        close(server_socket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Error listening for connections");
        close(server_socket);
        return 1;
    }

    printf("Server is listening for incoming connections on %s:%d\n", ip_address, port_number);

    // Accept incoming connections and display client IP addresses and port numbers
    int client_count = 0;
    while (client_count < MAX_CLIENTS) {
        client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Error accepting connection");
            close(server_socket);
            return 1;
        }

        char *client_ip = inet_ntoa(client_addr.sin_addr);
        int client_port = ntohs(client_addr.sin_port);

        printf("Client %d connected from %s:%d\n", client_count + 1, client_ip, client_port);

        close(client_socket);
        client_count++;
    }

    close(server_socket);

    return 0;
}

=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 5

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./display_ips <ip_address> <port_number>\n");
        return 1;
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Bind the socket to the specified IP address and port number
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);
    server_addr.sin_port = htons(port_number);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        close(server_socket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Error listening for connections");
        close(server_socket);
        return 1;
    }

    printf("Server is listening for incoming connections on %s:%d\n", ip_address, port_number);

    // Accept incoming connections and display client IP addresses and port numbers
    int client_count = 0;
    while (client_count < MAX_CLIENTS) {
        client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Error accepting connection");
            close(server_socket);
            return 1;
        }

        char *client_ip = inet_ntoa(client_addr.sin_addr);
        int client_port = ntohs(client_addr.sin_port);

        printf("Client %d connected from %s:%d\n", client_count + 1, client_ip, client_port);

        close(client_socket);
        client_count++;
    }

    close(server_socket);

    return 0;
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
