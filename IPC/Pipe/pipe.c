<<<<<<< HEAD
#include "header.h"
int main()
{
int p[2],ret;
ret = pipe(p);
if(ret < 0)
{
perror("pipe");
return 0;
}
printf("p[0] =%d p[1] =%d\n",p[0],p[1]);
if(fork()==0)
{
while(1)
{
char a[20];
printf("Before reading in the child...\n");
read(p[0],a,20);
printf("After reading in child: %s\n",a);
}
}
else
{
while(1)
{
sleep(2);
char a[20];
printf("Enter the data..\n");
scanf("%s",a);
write(p[1],a,strlen(a));
}
}
return 0;
}
=======
#include "header.h"
int main()
{
int p[2],ret;
ret = pipe(p);
if(ret < 0)
{
perror("pipe");
return 0;
}
printf("p[0] =%d p[1] =%d\n",p[0],p[1]);
if(fork()==0)
{
while(1)
{
char a[20];
printf("Before reading in the child...\n");
read(p[0],a,20);
printf("After reading in child: %s\n",a);
}
}
else
{
while(1)
{
sleep(2);
char a[20];
printf("Enter the data..\n");
scanf("%s",a);
write(p[1],a,strlen(a));
}
}
return 0;
}
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
