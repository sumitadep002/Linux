#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
int id,fd,i;

char a[]="abcdefghijklmnopqrstuvwxyz";

struct sembuf v;

id  = semget(3,5,IPC_CREAT|0600);
perror("semget");

fd=open("data",O_RDWR | O_APPEND,O_CREAT,0600);

v.sem_num = 1;
v.sem_op = 0;
v.sem_flg = 0;

printf("Before executing the semaphore..\n");

semop(id,&v,1);

semctl(id,1,SETVAL,1);

printf("After executing the semaphore..\n");

for(int i=0;a[i];1)
{
write(fd,&a[i],1);
sleep(1);
}

printf("Done..\n");
semctl(id,SETVAL,0);

return 0;
}
