<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/types.h>
int main()
{
char add1[]="132.186.151.255";
char add2[]="156.241.184.240";
unsigned long conv_add1 = inet_addr(add1);
unsigned long conv_add2 = inet_addr(add2);
printf("%#lx\n",conv_add1);
printf("%#lx",conv_add2);
return 0;
}
=======
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/types.h>
int main()
{
char add1[]="132.186.151.255";
char add2[]="156.241.184.240";
unsigned long conv_add1 = inet_addr(add1);
unsigned long conv_add2 = inet_addr(add2);
printf("%#lx\n",conv_add1);
printf("%#lx",conv_add2);
return 0;
}
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
