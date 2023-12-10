/*
2. Understanding of mutex.
   - Write a program to create two threads. 
   - One thread will write A to Z a file "temp.txt"
   - Other thread will write a to z to the same file "temp.txt"
   - Restriction is, A to Z or a to z should be continuous pattern, whichever is started first.
   - Identify why and where mutex should be used. 
   - If required, protect the critical region.
*/
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<fcntl.h>
void *fun1();
void *fun2();
int fd;
pthread_mutex_t l;
int main()
{
pthread_mutex_init(&l,NULL);
pthread_t thread1,thread2;
pthread_create(&thread1,NULL,fun1,NULL);
pthread_create(&thread2,NULL,fun2,NULL);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
return 0;
}

void *fun1()
{
//aquire the resource
pthread_mutex_lock(&l);
int fd=open("temp.txt",O_WRONLY | O_CREAT );
if(fd==-1)
printf("Thread1: Could not open the file\n");
char c='A';
for(c = 'A';c<='Z';c++)
write(fd,&c,1);
close(fd);
//release the resource
pthread_mutex_unlock(&l);
}
void *fun2()
{
sleep(1);
//aquire the resource
pthread_mutex_lock(&l);
int fd=open("temp.txt",O_WRONLY | O_CREAT );
if(fd==-1)
printf("Thread2: Could not open the file\n");
char c='a';
for(c = 'a';c<='z';c++)
write(fd,&c,1);
close(fd);
//release the resource
pthread_mutex_unlock(&l);
}
