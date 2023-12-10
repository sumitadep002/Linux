#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
pid_t pid  = fork();
if(pid==0)
{
while(1)
{
sleep(1);
printf("Hi This is child with pid:%d and ppid:%d\n",getpid(),getppid());
}
}
else
{
while(1){
sleep(1);
printf("Hi This is parent with pid: %d\n",getpid());
}
}
return 0;
}
