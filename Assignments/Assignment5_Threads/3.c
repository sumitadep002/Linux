/*
3. Make a program to check how two threads simultaneous works. One thread incrementing even number & print it on console and simultaneously 
   second thread incrementing odd number & print it on console.
*/
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
void *fun1();
void *fun2();
int main()
{
pthread_t thread1,thread2;			//declare thread
pthread_create(&thread1,NULL,fun1,NULL);	//launch thread1
pthread_create(&thread2,NULL,fun2,NULL);	//launch thraed2
pthread_join(thread2,NULL);			//hold program main program until thread 1 is finitshed		
pthread_join(thread1,NULL);			//hold program main program until thread 2 is finished
return 0;
}
void *fun1()
{
sleep(1);
for(int i=2;i<=10;i+=2)
printf("thread1: %d\n",i);
}
void *fun2()
{

for(int i=1;i<=10;i+=2)
printf("thread2: %d\n",i);
}

