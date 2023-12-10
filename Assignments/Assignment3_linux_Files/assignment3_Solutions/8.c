//8. Write a c program to change to permission of the file to real/write/execute for current user.



#include<sys/stat.h>
#include<stdio.h>
int main(int argc, char *argv[])
{
int permission;
char *path=argv[1];

printf("Enter the permission for file: %s\n",path);
scanf("%o",&permission);

if(chmod(path,permission)==-1)
perror("ERROR:");
else
printf("File permission changed successfully to %o\n",permission);


return 0;
}
