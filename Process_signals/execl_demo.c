#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
printf("before\n");
execl("/bin/ps","ps",NULL);
printf("After");
return 0;
}
