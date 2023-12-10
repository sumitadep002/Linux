//prrocess which does not have any parent

#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
pid_t p;

p=fork();

if(p<0)
printf("error");
else if(p==0)
{
sleep(10);
printf("I am child having pid %d\n",getpid());
printf("My parent's pid %d\n",getppid());
}
else
{
sleep(2);
printf("I am Parent having pid %d\n",getpid());
printf("My child's having pid %d\n",p);
}
return 0;
}
