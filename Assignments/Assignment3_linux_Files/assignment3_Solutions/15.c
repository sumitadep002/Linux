//15. Write a program to open a file in read mode. set the cursor to 10th position in file. Print the current position and read 6 bytes from the current cursor position. Print the bytes read.


#include<fcntl.h>
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
int fd,pos=0;
char *buff[10];
fd = open("15.txt",O_RDONLY);

//set the cursor at 10th byte 	
pos = lseek(fd,10,SEEK_SET);
printf("position of cursor: %d\n",pos);

read(fd,buff,6);
write(1,buff,6);

close(fd);
return 0;
}
