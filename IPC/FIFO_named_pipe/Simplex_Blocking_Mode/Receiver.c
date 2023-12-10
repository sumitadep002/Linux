#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
char message[100];
int p;
char c;
p=open("fifo",O_RDONLY);


while(read(p,message,100)>0)
{
write(1,"Received:",strlen("\nReceived:"));
write(1,message,strlen(message));
memset(message,'\0',100);
}


close(p);
perror("Closing fifo");
}
