<<<<<<< HEAD
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
int main()
{
    int socket_fd, client_fd[5];
    struct sockaddr_in server_addr, client_addr[5];
    socklen_t addr_size;
    char buffer[1024];

    // create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        perror("socket creation");
    else
        perror("socket creation");

    // configuring address and port number
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // fix here

    // binding
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        perror("binding");
    else
        perror("binding");

    // listening
    if (listen(socket_fd, 5) == -1)
        perror("listening");
    else
        perror("listening:");

    // accept
    for(int i=0;i<5;i++)
    {
    addr_size = sizeof(client_addr);
    if ((client_fd[i] = accept(socket_fd, (struct sockaddr *)&client_addr[i], &addr_size)) < 0)
        perror("accepting");
    else
        printf("\nclient[%d] accepting: %s",i ,strerror(errno)); // fix here
        
        recv(client_fd[i],&buffer,sizeof(buffer),0);
	printf("\nclient[%d] has sent: %s",i,buffer);
    }
    
    for(int i=0;i<5;i++)
    {
    close(client_fd[i]);
    printf("\nclosing cient[%d]: %s",i,strerror(errno));
    }
    
    
    return 0;
}

=======
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
int main()
{
    int socket_fd, client_fd[5];
    struct sockaddr_in server_addr, client_addr[5];
    socklen_t addr_size;
    char buffer[1024];

    // create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        perror("socket creation");
    else
        perror("socket creation");

    // configuring address and port number
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // fix here

    // binding
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        perror("binding");
    else
        perror("binding");

    // listening
    if (listen(socket_fd, 5) == -1)
        perror("listening");
    else
        perror("listening:");

    // accept
    for(int i=0;i<5;i++)
    {
    addr_size = sizeof(client_addr);
    if ((client_fd[i] = accept(socket_fd, (struct sockaddr *)&client_addr[i], &addr_size)) < 0)
        perror("accepting");
    else
        printf("\nclient[%d] accepting: %s",i ,strerror(errno)); // fix here
        
        recv(client_fd[i],&buffer,sizeof(buffer),0);
	printf("\nclient[%d] has sent: %s",i,buffer);
    }
    
    for(int i=0;i<5;i++)
    {
    close(client_fd[i]);
    printf("\nclosing cient[%d]: %s",i,strerror(errno));
    }
    
    
    return 0;
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
