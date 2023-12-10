#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main()
{
int max_ind,msqid;
struct msqid_ds ds;
struct msginfo msginfo;
//will return the (number of message queues present in the directory - 1)
max_ind = msgctl(0,MSG_INFO,(struct msqid_ds *) &msginfo);

printf("No of active message queues in Present Directory: %d\n",max_ind);

for(int i=0;i<max_ind;i++)
{
msqid = msgctl(i,MSG_STAT,&ds);
if(msqid<0)
{
perror("ERROR");
return 0;
}
if(msgctl(msqid,IPC_RMID,0)<0)
{
perror("ERROR");
}
}

printf("All the message Queues are deleted");

return 0;
}
