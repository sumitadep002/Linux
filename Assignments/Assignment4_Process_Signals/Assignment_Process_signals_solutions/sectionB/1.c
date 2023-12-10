/*
1. Create 5 children processes from a common parent and ensure that the
parent terminates after cleaning all the terminated children using waitpid().
The waitpid() must be called after all the children are created
and the parent has completed its work real work,if any. You must interpret
the exit code of the cleaned-up processes, using waitpid(), in parent process
– you must cover all the possible scenarios !!!
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{

printf("Parent process started\n");
pid_t p[5];
for(int i=0;i<5;i++)
{
p[i]=fork();
if(p[i]==0)
{
printf("[child] pid %d from [parent] pid %d\n",getpid(),getppid());
exit(0);
}
}

for(int i=0;i<=5;i++)
{

waitpid(p[i],NULL,0);
}
printf("Parent has been executed");
return 0;
}
