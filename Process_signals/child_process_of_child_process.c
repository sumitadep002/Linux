#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
pid_t process;

process=fork();

if(process<0)
printf("error");
else if(process==0)
{

pid_t process_child;
process_child = fork();

if(process_child<0)
printf("error");

else if(process_child==0)
{
printf("This is process->child->child having pid %d\n",getpid());
printf("my parents pid %d\n\n",getppid());
}

else
{
wait(NULL);
printf("This is process->child having pid %d\n",getpid());
printf("my parent's pid %d\n\n",getppid());
}

}


else
{
wait(NULL);
printf("This is  having pid %d\n",getpid());
printf("My child's having pid %d\n\n",process);
}
return 0;
}
