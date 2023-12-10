#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
char message[100];
int p,n;
p=open("fifo",O_WRONLY);
while(1)
{
write(1,"Send(e or E to Exit): ",strlen("Send(e or E to Exit): "));
read(0,message,100);
if(message[0]=='E' || message[0]=='e')
break;
write(p,message,strlen(message));
memset(message,'\0',100);
}
printf("Ended Communication\n");
close(p);
perror("Closing fifo");
}
