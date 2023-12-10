<<<<<<< HEAD
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>

void *fun1();
void *fun2();
int shared=1;
pthread_mutex_t l;
int main()
{
pthread_mutex_init(&l,NULL); //(sem_t , 0 -shared between threads or non zero-shared between processess, unsigned int type initial value)
pthread_t thread1,thread2;
pthread_create(&thread1,NULL,fun1,NULL);
pthread_create(&thread2,NULL,fun2,NULL);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("Final value of shared var %d\n",shared);
return 0;
}
void *fun1()
{
printf("thread1 trying to aquiring lock\n");
pthread_mutex_lock(&l); 
printf("thread1 has aquired lock\n");
int x=shared;
printf("Thread1 reads the value shared as variable as %d\n",x);
x++;
printf("Local updation by  thread1: %d\n",x);
sleep(1);
shared= x;
printf("Value of shared variable updated by thread1 is : %d\n",shared);
pthread_mutex_unlock(&l);
printf("thread1 has released lock\n");
}
void *fun2()
{
printf("thread2 trying to aquiring lock\n");
pthread_mutex_lock(&l);
printf("thread2 has aquired lock\n");
int x=shared;
printf("Thread2 reads the alue shared as variable as %d\n",x);
x--;
printf("Local updation by  thread2: %d\n",x);
sleep(1);
shared= x;
printf("Value of shared variable updated by thread2 is : %d\n",shared);
pthread_mutex_unlock(&l);
printf("thread2 has released lock\n");
}
=======
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>

void *fun1();
void *fun2();
int shared=1;
pthread_mutex_t l;
int main()
{
pthread_mutex_init(&l,NULL); //(sem_t , 0 -shared between threads or non zero-shared between processess, unsigned int type initial value)
pthread_t thread1,thread2;
pthread_create(&thread1,NULL,fun1,NULL);
pthread_create(&thread2,NULL,fun2,NULL);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("Final value of shared var %d\n",shared);
return 0;
}
void *fun1()
{
printf("thread1 trying to aquiring lock\n");
pthread_mutex_lock(&l); 
printf("thread1 has aquired lock\n");
int x=shared;
printf("Thread1 reads the value shared as variable as %d\n",x);
x++;
printf("Local updation by  thread1: %d\n",x);
sleep(1);
shared= x;
printf("Value of shared variable updated by thread1 is : %d\n",shared);
pthread_mutex_unlock(&l);
printf("thread1 has released lock\n");
}
void *fun2()
{
printf("thread2 trying to aquiring lock\n");
pthread_mutex_lock(&l);
printf("thread2 has aquired lock\n");
int x=shared;
printf("Thread2 reads the alue shared as variable as %d\n",x);
x--;
printf("Local updation by  thread2: %d\n",x);
sleep(1);
shared= x;
printf("Value of shared variable updated by thread2 is : %d\n",shared);
pthread_mutex_unlock(&l);
printf("thread2 has released lock\n");
}
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
