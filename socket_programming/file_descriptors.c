<<<<<<< HEAD
#include<sys/types.h>
#include<stdio.h>
#include<sys/socket.h>
int main()
{
int fd1,fd2;
fd1=socket(PF_INET,SOCK_STREAM,0);
fd2=socket(PF_INET,SOCK_DGRAM,0);
printf("fd1=%d\nfd2=%d",fd1,fd2);
return 0;
}
=======
#include<sys/types.h>
#include<stdio.h>
#include<sys/socket.h>
int main()
{
int fd1,fd2;
fd1=socket(PF_INET,SOCK_STREAM,0);
fd2=socket(PF_INET,SOCK_DGRAM,0);
printf("fd1=%d\nfd2=%d",fd1,fd2);
return 0;
}
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
