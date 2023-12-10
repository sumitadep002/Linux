#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
int common_fd;
if(fork()==0)
{
common_fd = open("child_writes_parent_reads.txt",O_WRONLY|O_CREAT);
write(common_fd,"Hi there i am child\n",21);
close(common_fd);
exit(0);
}
else
{
wait(NULL);
common_fd = open("child_writes_parent_reads.txt",O_RDONLY|O_CREAT);
char c;
while(read(common_fd,&c,1)>0)
{
write(1,&c,1);
}
close(common_fd);
}
return 0;
}
