#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
pid_t p[5];
for(int i=0;i<5;i++)
{
p[i]=fork();
if(p[i]==0)
{
printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
exit(0);
}
}
for(int i=0;i<=5;i++)
waitpid(p[i],NULL,0);
return 0;
}
