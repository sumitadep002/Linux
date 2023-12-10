#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
static int count = 0;
void call_fork(int);
int main()
{

printf("This is main pid[%d]\n",getpid());
call_fork(4);

/*int count = 0 ;
if(fork()==0)
{

}
else
{
count++;
printf("This process[%d]\n",count);
}
waitpid(p[i],NULL,1);*/
return 0;
}

void call_fork(int n)
{
if(n==0)
{
return ;
}
if(fork()==0)
{
printf("This process pid[%d], ppid[%d]\n",getpid(),getppid());
call_fork(n-1);
exit(0);
}
else
{
wait(NULL);
//printf("This process pid[%d], ppid[%d]\n",getpid(),getppid());
}
}
