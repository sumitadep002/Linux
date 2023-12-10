//13. write a program to open a file and print the file descriptor(Create the file if it does not exist). print error message in case of failure.


#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>


int main(int argc,char *argv[])
{
int fd;
if(argc==1)
printf("Usage: %s <filename>",argv[0]);

else
{
char *filename=argv[1];
fd=open(filename,O_WRONLY|O_CREAT);
if(fd == -1)
perror("ERROR");
else
{
printf("\nFile Descripter %d\n",errno);
close(fd);
}

}

return 0;
}
