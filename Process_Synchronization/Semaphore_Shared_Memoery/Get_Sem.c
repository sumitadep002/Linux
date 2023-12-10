#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{

int id,val;
if(argc!=2)
{
printf("Usage: %s <num>\n",argv[0]);
return 0;
}

//2 is the key 5 is the number of semaphores
id = semget(2,5,IPC_CREAT | 0600);
printf("id =%d\n",id);
val = semctl(id,atoi(argv[1]),GETVAL);
printf("val =%d\n",val);

return 0;
}
