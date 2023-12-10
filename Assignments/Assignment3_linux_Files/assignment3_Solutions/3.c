//3. Write a C program to display a permission of the file

#include<stdio.h>
#include<errno.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
char *path = argv[1];
int rval;

//access will return F_OK uf file exists
//rval = access(path, F_OK);

if(access(path,F_OK) == F_OK)
{
printf("%s exists\n",path);

if(errno == EACCES)
{
printf("%s is not accessible\n",path);
return 0;
}

if(access(path,R_OK) == 0)
printf("%s is readable\n",path);
else
printf("%s is not readable\n",path);

if(access(path,W_OK)==0)
printf("%s is writable\n",path);
else
printf("%s is writable\n",path);

if(access(path,X_OK) == 0)
printf("%s is executable\n",path);
else
printf("%s is executable\n",path);

}
else
printf("%s does not exit\n",path);
return 0;
}
