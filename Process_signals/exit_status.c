#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
pid_t pid;
int status;
pid = fork();
if(pid == -1)
{
perror("Error");
exit(EXIT_FAILURE);
}
else if(pid == 0)
{
printf("This is child with pid %d\n",getpid());
sleep(10);
exit(EXIT_SUCCESS);
}
else
{
printf("This is parent with pid %d waiting for child to be finished\n",getpid());
wait(&status);
printf("Child process returned with exit status %d.\n",WEXITSTATUS(status));
}
return 0;
}
