//1. Write a C program create new file, open it and write “Hello world” string to it.

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
int file;
//open 1.txt file in writeonly mode and create if it does not exist
file=open("1.txt",O_WRONLY | O_CREAT);
//wrtie 11 characters from passed string into the file
write(file,"Hello World",11);

return 0;
}
