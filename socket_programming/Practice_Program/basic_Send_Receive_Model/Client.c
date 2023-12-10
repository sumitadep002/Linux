

#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>

int main(int argc,char *argv[])
{

char message_buffer[20];

//create a socket
int sd=socket(AF_INET6,SOCK_STREAM,0);

//address parameters
struct sockaddr_in addr;
addr.sin_family = AF_INET;
addr.sin_port = htons(8080);//htons is conversion function
addr.sin_addr.s_addr = INADDR_ANY; //will be ready to go with random address

//binding: with IP and port number
//bind(sd,(const struct sockaddr *)&addr,sizeof(addr));

//connect
connect(sd,(const struct sockaddr *)&addr,sizeof(addr));
perror("ERROR");
recv(sd,message_buffer,20,0);
printf("Data received from server: %s\n",message_buffer);

close(sd);

return 0;
}
