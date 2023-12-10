/*
Write a program to create a thread, thread routine should increment a number in infinite loop, main() should also increment a number and print the same. 
*/

#include<unistd.h>
#include<pthread.h>
#include<stdio.h>

void *fun1(void*);

int main(int argc,char *argv[])
{
int i = 5;
pthread_t thread1;
pthread_create(&thread1,NULL,fun1,(void *)&i);
pthread_join(thread1,NULL);
for(;1;i++)
printf("main: %d\n",i);
return 0;
}

void *fun1(void *arg)
{
int *int_ptr=(int*)arg;
int i = *int_ptr;
for(;1;i++)
{
sleep(1);
printf("thread: %d\n",i);
}
}

