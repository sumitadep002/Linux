<<<<<<< HEAD
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
void *thread_function(void *arg);
int main()
{
pthread_t a_thread;
pthread_create(&a_thread,NULL,thread_function,NULL);
pthread_join(a_thread,NULL);

printf("Inside Main Program\n");

for(int j=11;j<=15;j++)
{
printf("%d\n",j);
sleep(1);
}
return 0;
}

void *thread_function(void *arg)
{

printf("Inside thread:\n");

for(int i=1;i<=5;i++)
{
printf("%d\n",i);
sleep(1);
}

}
=======
#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
void *thread_function(void *arg);
int main()
{
pthread_t a_thread;
pthread_create(&a_thread,NULL,thread_function,NULL);
pthread_join(a_thread,NULL);

printf("Inside Main Program\n");

for(int j=11;j<=15;j++)
{
printf("%d\n",j);
sleep(1);
}
return 0;
}

void *thread_function(void *arg)
{

printf("Inside thread:\n");

for(int i=1;i<=5;i++)
{
printf("%d\n",i);
sleep(1);
}

}
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
