<<<<<<< HEAD
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
int fd1=open("test_dup.txt",O_RDWR|O_CREAT);
write(fd1,"sumit adep",10);
//int fd2=dup(fd1);
//write(fd2,"sumit adep",10);
/*write(fd1,"vishal adep",11);
*/return 0;
}
=======
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
int fd1=open("test_dup.txt",O_RDWR|O_CREAT);
write(fd1,"sumit adep",10);
//int fd2=dup(fd1);
//write(fd2,"sumit adep",10);
/*write(fd1,"vishal adep",11);
*/return 0;
}
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
