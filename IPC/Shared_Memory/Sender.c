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
shmid = shmget((key_t)1122,1024,0600|IPC_CREAT);
//1122 is key
printf("ID=%d,key=1122\n",shmid);
shm = shmat(shmid,NULL,0);
memset(shm,'\0',1024);
write(1,"Send: ",strlen("Send: "));
read(0,buffer,100);
strcpy(shm,buffer);
return 0;
}
