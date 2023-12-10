#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
printf("pid1: %d\n",getpid());
if(fork()==0)
{
printf("child pid: %d and parentpid: %d\n",getpid(),getppid());
}
else
{
printf("parent pid: %d and my parent's pid: %d\n",getpid(),getppid());
}
return 0;
}

