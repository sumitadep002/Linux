//2. Write a C program to add 50 bytes data at end of the existing hex file.

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int f;
char c='A';
f=open("2.hex",O_APPEND | O_CREAT | O_WRONLY);
for(int i=1;i<=50;i++,c++)
{
write(f,&c,1);
}
return 0;
}


