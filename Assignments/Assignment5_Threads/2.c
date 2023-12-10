/*
2. Create two threads, print its PIDs & PPIDs.
*/

#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
void* fun1();
void* fun2();
int main()
{
printf("main PID %d\n",getpid());
pthread_t thread1,thread2;			//declare thread
pthread_create(&thread1,NULL,fun1,NULL);	//launch thread1
pthread_create(&thread2,NULL,fun2,NULL);	//launch thraed2
pthread_join(thread1,NULL);			//hold program main program until thread 1 is finitshed		
pthread_join(thread2,NULL);			//hold program main program until thread 2 is finished
return 0;
}

void* fun1()
{
pthread_t p =  pthread_self();
printf("Thread1 thread_id: %lu\n",p);
}
void* fun2()
{
pthread_t p =  pthread_self();
printf("Thread2 thread_id: %lu\n",p);
}
