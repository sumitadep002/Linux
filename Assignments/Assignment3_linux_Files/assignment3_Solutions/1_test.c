#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
int main()
{
int file;
file=open("a.txt",O_WRONLY | O_CREAT);
write(file,"Hello World",11);
printf("fd1=%d\n",file);

file=open("b.text",O_WRONLY | O_CREAT);
write(file,"Hello world",11);
printf("fd2=%d\n",file);

file=open("c.txt",O_WRONLY | O_CREAT);
write(file,"hello world",11);
printf("fd3=%d\n",file);
return 0;
}
