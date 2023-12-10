#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void signal_handler(int signal_number)
{
printf("received signal %d\n",signal_number);
}

int main(void)
{
//register the signal handler function for SIGINT
signal(SIGINT, signal_handler);

printf("Signal demonstration program running...\n");
printf("Press Cntrl+C to send SIGINT signal\n");

while(1)
{
sleep(1);
}
return 0;
}
