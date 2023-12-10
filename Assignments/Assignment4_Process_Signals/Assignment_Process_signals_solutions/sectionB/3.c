#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
pid_t p[5];
for(int i=1;i<3;i++)
{
p[i]=fork();
if(p[i]==0)
{
char *args[] = {"/usr/bin/firefox","/usr/bin/gcc","/usr/bin/gedit", NULL};

// Execute the application using execvp
if (execvp(args[i], args) == -1)
{
	perror("execvp failed");
        exit(1);
}


}
}
for(int i=0;i<=5;i++)
waitpid(p[i],NULL,0);

return 0;
}
