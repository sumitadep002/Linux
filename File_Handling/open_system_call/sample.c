<<<<<<< HEAD
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
int fd,n;
char buff[50];
fd=open("test.txt", O_RDONLY);
int f=open("target.txt",O_CREAT|O_WRONGLY,642);
n=read(fd,buff,10);
write(1,buff,10);
}
=======
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
int fd,n;
char buff[50];
fd=open("test.txt", O_RDONLY);
int f=open("target.txt",O_CREAT|O_WRONGLY,642);
n=read(fd,buff,10);
write(1,buff,10);
}
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
