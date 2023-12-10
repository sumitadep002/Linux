<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>
int main()
{
//create socket
int server_socket,client_socket;
char msg[1024];
int str_len;

struct sockaddr_in server_address;
struct sockaddr_in client-address;

socklen_t clnt_addr_sz;
if(argc!=2)
{
printf("Usage : %s <IP>  <port>\n",argv[0]);
exit(1);
}
server_socket = socket(AF_INET,SOCK_STREAM,0);
if(server_socket==-1)
perror("erro");
memset(&serve_adress,0,sizeof(server_address));
server_address.sin_family=AF_INET;
server_address.sin_addr.s_addr = htonl(argv[1]));
server_address.sin_port = htons(atoi(argv[2]));

//binding
if(bind(server_socket)==-1)
perror("error");

//listening

return 0;
}
=======
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>
int main()
{
//create socket
int server_socket,client_socket;
char msg[1024];
int str_len;

struct sockaddr_in server_address;
struct sockaddr_in client-address;

socklen_t clnt_addr_sz;
if(argc!=2)
{
printf("Usage : %s <IP>  <port>\n",argv[0]);
exit(1);
}
server_socket = socket(AF_INET,SOCK_STREAM,0);
if(server_socket==-1)
perror("erro");
memset(&serve_adress,0,sizeof(server_address));
server_address.sin_family=AF_INET;
server_address.sin_addr.s_addr = htonl(argv[1]));
server_address.sin_port = htons(atoi(argv[2]));

//binding
if(bind(server_socket)==-1)
perror("error");

//listening

return 0;
}
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
