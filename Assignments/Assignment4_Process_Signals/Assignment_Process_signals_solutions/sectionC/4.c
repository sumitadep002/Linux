/*
Write a program and do the following :using sigaction API, handle SIGINT, SIGTERM, SIGQUIT,
SIGSTOP,SIGTSTP and SIGKILL. Install dummy handlers for the mentioned signals Using
sigaction() system call API !!!

ctrl+c: This command sends a SIGINT signal to the process currently running in the foreground, causing it to terminate.

ctrl+z: This command sends a SIGTSTP signal to the process currently running in the foreground, causing it to pause. The process can later be resumed with the fg or bg commands.

ctrl+\: This command sends a SIGQUIT signal to the process currently running in the foreground, causing it to terminate and generate a core dump.

ctrl+s: This command stops the output to the screen, but the process continues to run in the background.

SIGSTP (signal stop) is a user-initiated signal that is typically sent using the ctrl+z key combination. It tells the process to suspend its execution and move to the background, allowing the user to interact with the shell or start other processes. The process can be resumed later with the fg command.

SIGSTOP (signal stop) is a system-initiated signal that is used to immediately stop the execution of a process, without any chance for it to perform any cleanup or save any state. This signal cannot be caught or ignored by the process and can only be resumed by sending a SIGCONT signal. SIGSTOP is often used by system administrators to pause or halt processes temporarily.
*/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void signal_interrupt(int signal_number)
{
printf(" received signal %d\n",signal_number);
}

void signal_terminate(int signal_number)
{
printf(" received signal %d\n",signal_number);
}

void signal_quit(int signal_number)
{
printf(" received signal %d\n",signal_number);
}

void signal_stop_system_initiated(int signal_number)
{
printf(" received signal %d\n",signal_number);
}

void signal_stop_user_initiated(int signal_number)
{
printf(" received signal %d\n",signal_number);
}

void signal_kill(int signal_number)
{
printf(" received signal %d\n",signal_number);
}

int main(void)
{
//register the signal handler function for SIGINT
signal(SIGINT, signal_interrupt);
signal(SIGTERM, signal_terminate);
signal(SIGQUIT, signal_quit);
signal(SIGSTOP, signal_stop_system_initiated);
signal(SIGTSTP, signal_stop_user_initiated);
signal(SIGKILL, signal_kill);

printf("Signal demonstration program running...\n");


while(1)
{
sleep(1);
}
return 0;
}

