<<<<<<< HEAD
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
unsigned int port = 0x1234;
unsigned int net_port;
net_port = htons(port);
printf("port without conversion: %x",port);
printf("\nnet_port after conversion: %x",net_port);


return 0;
}
=======
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
unsigned int port = 0x1234;
unsigned int net_port;
net_port = htons(port);
printf("port without conversion: %x",port);
printf("\nnet_port after conversion: %x",net_port);


return 0;
}
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
