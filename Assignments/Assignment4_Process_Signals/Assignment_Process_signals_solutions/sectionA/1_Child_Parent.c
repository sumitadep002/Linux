

// 1. Make a program for Executing a child process from parent process.

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>s
int main()
{
//This variable will store the Process ID
pid_t Child_PID;


//This will create the child process and will reutrn its Process ID
Child_PID=fork();


//print the error message if any
if(Child_PID<0)
perror("ERROR");

//Child_PID will be always 0
else if(Child_PID==0)
{
printf("Inside Child process\n");
printf("I am child having id %d\n",getpid());
printf("My parent's id is %d\n",getppid());
printf("Exting Child Process......\n");
}
else{
wait(NULL);
printf("Inside Parent process\n");
printf("I am Parent having id %d\n",getpid());
printf("My Child's id is %d\n",Child_PID);
printf("Exting Parent Process......\n");
} 

return 0;
}
