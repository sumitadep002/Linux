<<<<<<< HEAD
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<errno.h>
int main(int argc,char *argv[])
{
char buffer[1024];
if(argc==2)
printf("message as argument: %s\n",argv[1]);
strncpy(buffer,argv[1],sizeof(argv[1]));
printf("buffer: %s\n",buffer);
int server_socket;
struct sockaddr_in server_address;

//creating a socket
if((server_socket=socket(AF_INET,SOCK_STREAM,0))<0)
perror("socket creation");

else
perror("socket creation");

//address and port number configuration

bzero(&server_address,sizeof(server_address));
server_address.sin_family = AF_INET;
server_address.sin_port = htons(8080);
server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

//connection request
if(connect(server_socket,(struct sockaddr*)&server_address,sizeof(server_address))<0)
perror("error");

else
perror("connection status");

send(server_socket,&buffer,sizeof(buffer),0);
perror("message sent");
//close the socketf
close(server_socket);
perror("closing server socket");

return  0;
}

=======
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<errno.h>
int main(int argc,char *argv[])
{
char buffer[1024];
if(argc==2)
printf("message as argument: %s\n",argv[1]);
strncpy(buffer,argv[1],sizeof(argv[1]));
printf("buffer: %s\n",buffer);
int server_socket;
struct sockaddr_in server_address;

//creating a socket
if((server_socket=socket(AF_INET,SOCK_STREAM,0))<0)
perror("socket creation");

else
perror("socket creation");

//address and port number configuration

bzero(&server_address,sizeof(server_address));
server_address.sin_family = AF_INET;
server_address.sin_port = htons(8080);
server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

//connection request
if(connect(server_socket,(struct sockaddr*)&server_address,sizeof(server_address))<0)
perror("error");

else
perror("connection status");

send(server_socket,&buffer,sizeof(buffer),0);
perror("message sent");
//close the socketf
close(server_socket);
perror("closing server socket");

return  0;
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
