<<<<<<< HEAD
#include "header.h"
void *transmit();
void *receive();


int main()
{
pthread_t t1,t2;
pthread_create(&t1,NULL,transmit,NULL);
pthread_create(&t2,NULL,receive,NULL);
while(1);

return 0;
}



void *receive()
{
char buff[20];
int fd;
mkfifo("f2",0666);
fd=open("f2",0666);
while(1)
{
read(fd,buff,20);
printf("data: %s\n",buff);
}
}


void *transmit()
{
char buff[20];
int fd;
mkfifo("f1",0666);
fd=open("f1",O_RDWR|O_CREAT,0666);
while(1)
{
printf("Enter the string: \n");
scanf("%s",buff);
write(fd,buff,strlen(buff)+1);
}
}

=======
#include "header.h"
void *transmit();
void *receive();


int main()
{
pthread_t t1,t2;
pthread_create(&t1,NULL,transmit,NULL);
pthread_create(&t2,NULL,receive,NULL);
while(1);

return 0;
}



void *receive()
{
char buff[20];
int fd;
mkfifo("f2",0666);
fd=open("f2",0666);
while(1)
{
read(fd,buff,20);
printf("data: %s\n",buff);
}
}


void *transmit()
{
char buff[20];
int fd;
mkfifo("f1",0666);
fd=open("f1",O_RDWR|O_CREAT,0666);
while(1)
{
printf("Enter the string: \n");
scanf("%s",buff);
write(fd,buff,strlen(buff)+1);
}
}

>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
