/*
few steps for socket programming

1. Socket Creation
2. Binding
3. Listening
4. Accept
5. Connect
*/
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>



int main(int argc,char *argv[])
{
//create a socket
//AF_INET6,SOCK_STREAM(TCP) and 0 
int sd=socket(AF_INET6,SOCK_STREAM,0);

struct sockaddr_in addr;

addr.sin_family = AF_INET;
addr.sin_port = htons(8080);//htons is conversion function
addr.sin_addr.s_addr = INADDR_ANY; //will be ready to go with random address
//binding: with IP and port number
bind(sd,(const struct sockaddr *)&addr,sizeof(addr));


//listen upto 5 clients
listen(sd,5);

//accept: incomingconnection from the client
int cd = accept(sd,NULL,NULL);

//send the message on the client address
send(cd,"Hi there",sizeof("Hi there"),0);

close(sd);

return 0;
}
