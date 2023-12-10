#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig) {
    printf("Received signal %d\n", sig);
}

int main() {
    struct sigaction sa;

    // Set up the signal handlers
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
    sigaction(SIGQUIT, &sa, NULL);
    sigaction(SIGSTOP, &sa, NULL);
    sigaction(SIGTSTP, &sa, NULL);

    printf("Waiting for signals...\n");
    while (1) {
        sleep(1);
    }

    return 0;
}

