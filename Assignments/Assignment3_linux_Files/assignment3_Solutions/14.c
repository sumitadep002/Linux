//14. Open a file in current directory, print the file descriptor, and close the file descriptor(Print the success or failure for file close).


#include<errno.h>

#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
int fd;
fd=open("14.txt",O_RDONLY);

printf("File descriptor %d\n",fd);

close(fd);
perror("Closing file");
return 0;
}			
