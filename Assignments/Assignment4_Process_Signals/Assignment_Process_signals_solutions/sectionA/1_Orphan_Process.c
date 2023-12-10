/*
If Parent execute first then child, what happen? explain through program.
Ans: Child process will be withut Parent Process and That it called ORPHAN Process
To Prevent that to happen we can make Parent process wait until execution of child proccess
*/

// A C program to demonstrate working of
// fork() and process table entries.
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	int i;
	int pid = fork();

	if (pid == 0)
	{
		for (i=0; i<20; i++)
			printf("Child Process in execution\n");
	}
	else
	{
		//use below line to make parent wait until the execution of the child process
		//wait(NULL);
		printf("Parent has been executed\n");
	}
}

