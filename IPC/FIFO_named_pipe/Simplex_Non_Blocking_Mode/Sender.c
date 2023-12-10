#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
char message[100]="Dulhan ki vidaayi kaa waqt badal na hai";
int p;
p=open("fifo",O_NONBLOCK,O_WRONLY);

//write(1,"Send: ",strlen("Send: "));
//read(0,message,100);
write(p,message,strlen(message));
printf("Ended Communication\n");
//close(p);
//perror("Closing fifo\n");
}
