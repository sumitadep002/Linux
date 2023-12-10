/*
6. Make a program where parent and child processes simultaneously works. Parent will write capital ’ABC
D..’ into file & child process will write small ’abcd ..’ into the file.
*/
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
int main()
{
int fd;
fd=open("6.txt",O_RDWR | O_APPEND | O_CREAT);
pid_t process;
process = fork();

if(process == 0 )
{
//this will allow switching between child and parent process
sleep(1);
for(char c='a';c<='z';c++)
write(fd,&c,1);
exit(0);
}
else
{
//this will allow switching between child and parent process
sleep(1);
for(char c='A';c<='Z';c++)
write(fd,&c,1);
}
close(fd);
return 0;
}
