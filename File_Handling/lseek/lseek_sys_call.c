<<<<<<< HEAD
#include<sys/types.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int n,f,f1;
char buff[10];
f=open("seeking.txt",O_RDWR);
f=read(f,buff,10);
write(1,buff,10);
printf("\n");
lseek(f,10,SEEK_CUR);
read(f,buff,10);
write(1,buff,10);
}
=======
#include<sys/types.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int n,f,f1;
char buff[10];
f=open("seeking.txt",O_RDWR);
f=read(f,buff,10);
write(1,buff,10);
printf("\n");
lseek(f,10,SEEK_CUR);
read(f,buff,10);
write(1,buff,10);
}
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
