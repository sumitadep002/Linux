/*
what is zombie process? How can you overcome ? Explain through program
Ans: A Process which has been executed BUT still it has Presesnce in Process Table
*/
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
			printf("Child Process in Execution\n");
	}
	else
	{
		printf("This is parent Process\n");
		while(1);
	}
}

