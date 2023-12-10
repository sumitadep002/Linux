#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int count = 1 ;
int main()
{

if(count > 5 )
return 0;
create_child:
if(fork()==0)
{
printf("Process_pid[%d], ppid[%d]\n",getpid(),getppid());
count++;
if(count<=5)
goto create_child;
}
else
{
wait(NULL);
//printf("Process_pid[%d], ppid[%d]\n",getpid(),getppid());
}


return 0;
}


