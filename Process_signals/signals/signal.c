#include<signal.h>
#include<stdio.h>
#include<unistd.h>
void ouch(int sig)
{
printf("OUCH! - yout have hit CTRL+C\nsignal %d\n",sig);
}
int main()
{
struct sigaction act;
act.sa_handler = ouch;
sigemptyset(&act.sa_mask);
act.sa_flags = 0;
sigaction(SIGINT,&act,0);
while(1){
sleep(1);
printf("Hello world\n");
}
return 0;
}
