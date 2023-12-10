#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
int main()
{
//generate a message queu by providing key and permissions using msgget
int msgid = msgget((key_t)1005,IPC_CREAT|0600);

printf("msgid %d",msgid);

return 0;
}
