/*
 Write a program to create a thread, thread routine should increment a number in infinite loop. 

*/

#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
void *fun1();
void *fun2();
int main()
{
pthread_t thread1;
pthread_create(&thread1,NULL,fun1,NULL);
pthread_join(thread1,NULL);

return 0;
}
void *fun1()
{
for(int i=1;1;i++)
{
sleep(1);
printf("thread: %d\n",i);
}
}

