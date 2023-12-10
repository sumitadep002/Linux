/*2. Create 5 processes but not from the common parent. Meaning, each child
creates a new process. clean-up the children using waitpid(). waitpid()
must be called after all the children are created and the parent has
completed its work real work,if any. You must interpret the exit code of thecleaned-up processes, using waitpid(), in the parent process
– you must cover all the possible scenarios !!!
*/
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
pid_t p=fork();
for(int i=1;i<4;i++)
{
if((p=fork())>0)
{
waitpid(p,NULL,0);
exit(0);
}
else
printf("%d %d\n",getpid(),getppid());
}
exit(0);
}

