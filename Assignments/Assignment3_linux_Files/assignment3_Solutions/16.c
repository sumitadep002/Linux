//16. Make two file descriptors of the same file using dup(). use both file descriptors to write different messages, and check if we can use them interchangeably.



#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
int main()
{
int fd1,fd2;


//open file and assign different file descriptor to them 
fd1 = open("16.txt",O_RDWR|O_TRUNC);
fd2 = open("16.txt",O_RDWR|O_TRUNC);


printf("fd1 %d and fd2 %d\n",fd1,fd2);

write(fd1,"this is written by fd1",strlen("this is written by fd1"));
write(fd1,"this is written by fd2",strlen("this is written by fd2"));



close (fd1);
close (fd2);
return 0;
}



//conclusion : even though two different file descriptor are pointing to the same file it does not make any such difference means we can use it interchangabely
