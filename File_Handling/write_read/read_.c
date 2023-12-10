<<<<<<< HEAD
#include<unistd.h>
#include<stdio.h>
int main()
{
char b[30];
int n=0,w=0;
n=read(0,b,30);
w=write(1,b,n);
printf("\nnumber of char in r=%d and in w=%d",n,w);
}
=======
#include<unistd.h>
#include<stdio.h>
int main()
{
char b[30];
int n=0,w=0;
n=read(0,b,30);
w=write(1,b,n);
printf("\nnumber of char in r=%d and in w=%d",n,w);
}
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
