#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
//file descriptor
char str[20];
int fd[2],n;
char buffer[100];
pid_t p;
pipe(fd);
p=fork();
if(p>0)
{
wait(NULL);
read(fd[0],buffer,20);
printf("Received: %s",buffer);
}
else
{
printf("Send: ");
fgets(str,20,stdin);
write(fd[1],str,strlen(str));
}

return 0;
}
