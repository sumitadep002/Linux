#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
int main()
{
int p;
p=mkfifo("fifo",0600);
if(p==-1)
perror("ERROR");
else
printf("Created \"fifo\" successfully\n");
return 0;
}
