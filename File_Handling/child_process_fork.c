<<<<<<< HEAD
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<unistd.h>
int main()
{
pid_t q;
q=fork();
if(q<0)
printf("error");
else if(q==0)
{
printf("child having pid %d\n",getpid());
printf("My parent's pid is %d\n",getppid());
}
else
{
printf("Parent having pid %d\n",getpid());
printf("My child's pid is %d\n",q);
}
}
=======
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<unistd.h>
int main()
{
pid_t q;
q=fork();
if(q<0)
printf("error");
else if(q==0)
{
printf("child having pid %d\n",getpid());
printf("My parent's pid is %d\n",getppid());
}
else
{
printf("Parent having pid %d\n",getpid());
printf("My child's pid is %d\n",q);
}
}
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
