//2. open a file that does not exist(print the file descriptor value) and print the error number. Hint: use
#include<errno.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(int arc,char *argv[])
{

//extern int errno;
int fd;

fd=open("random_file_name_which_does_not_exist",O_RDONLY);

perror("ERROR");

printf("ERROR number %d\nFile descripter %d\n",errno,fd);

close(fd);
return 0;
}
