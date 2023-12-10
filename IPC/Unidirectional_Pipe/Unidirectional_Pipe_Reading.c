#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
FILE *wr;
char buffer[200];

wr=popen("ls","r");

fread(buffer,sizeof(char),200,wr);

write(1,buffer,200);

pclose(wr);
}
