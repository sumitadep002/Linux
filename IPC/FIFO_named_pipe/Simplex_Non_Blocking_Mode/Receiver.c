#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
char message[100];
int p;
char c;
p=open("fifo",O_NONBLOCK,O_RDONLY);


read(p,message,100);
write(1,"Received:",strlen("Received:"));
write(1,message,strlen(message));

//close(p);
//perror("Closing fifo");
}
