//5. Write a C program to display the content of the file of the specific line.



#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
int main()
{
//open the file in read mode
int fd = open("5.txt",O_RDWR,0600);
if(fd==-1)
{
perror("ERROR");
return 0;
}
else
{
char c;

if(read(fd,&c,1)<=0)
{
printf("File is empty!\n");
close(fd);
return 0;
}

lseek(fd,0,SEEK_SET);
int new_line_chars=1,line=0;
printf("Enter line number: ");
scanf("%d",&line);
while(line>0)
{
if(c=='\n')
new_line_chars++;

if(line == new_line_chars)
{
while(read(fd,&c,1)>0 && c!='\n')
{
write(1,&c,1);
}
break;
}
if(read(fd,&c,1)<=0)
break;
}
if(line>new_line_chars)
printf("file contains on %d lines\n",new_line_chars);
}

close(fd);
return 0;
}

