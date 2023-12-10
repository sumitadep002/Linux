#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
void *shm;
char buffer[100];
int shmid;
shmid = shmget((key_t)1122,1024,0600);
//1122 is key
printf("ID=%d,key=1122\n",shmid);
shm = shmat(shmid,NULL,0);
printf("Data from Shared Memory: %s",(char*)shm);
return 0;
}
