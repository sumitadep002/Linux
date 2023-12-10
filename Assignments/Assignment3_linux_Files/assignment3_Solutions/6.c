//6. Write a program to read from a file and print the same.

//to use open() function 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//to use close(), read() and write()
#include <unistd.h>


int main()
{
//will be used as file descriptor
int fd;

//will work as temperary buffer container
char c;

//will open the file in ReadOnly Mode
fd = open("6.txt",O_RDONLY);

//will read one byte from the file and write that to the screen
while(read(fd,&c,1)==1)
write(1,&c,1);

//will close the file
close(fd);
return 0;
}
