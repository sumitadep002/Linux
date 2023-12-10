<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#define MSG_SIZE 1024 

struct Message {
    long msg_type;
    char msg_text[MSG_SIZE];
};

 

int main() {
    int msgid;
    key_t key = 1234;
    struct Message msg;
    pid_t pid = fork();

 

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

 

    msgid = msgget(key, IPC_CREAT | 0666);

 

    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

 

    if (pid > 0) { // parent process
        while (1) {
            printf("Enter message to child: ");
            fgets(msg.msg_text, MSG_SIZE, stdin);
            msg.msg_type = 1;
            msgsnd(msgid, &msg, strlen(msg.msg_text) + 1, 0);
            if (strcmp(msg.msg_text, "quit\n") == 0) {
                break;
            }
        }
    } else { // child process
        while (1) {
            msgrcv(msgid, &msg, MSG_SIZE, 1, 0);
            printf("Received message from parent (pid %d): %s", getpid(), msg.msg_text);
            if (strcmp(msg.msg_text, "quit\n") == 0) {
                break;
            }
            printf("Enter message to parent: ");
            fgets(msg.msg_text, MSG_SIZE, stdin);
            msg.msg_type = 1;
            msgsnd(msgid, &msg, strlen(msg.msg_text) + 1, 0);
        }
    }

 

    msgctl(msgid, IPC_RMID, NULL);

 

    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#define MSG_SIZE 1024 

struct Message {
    long msg_type;
    char msg_text[MSG_SIZE];
};

 

int main() {
    int msgid;
    key_t key = 1234;
    struct Message msg;
    pid_t pid = fork();

 

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

 

    msgid = msgget(key, IPC_CREAT | 0666);

 

    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

 

    if (pid > 0) { // parent process
        while (1) {
            printf("Enter message to child: ");
            fgets(msg.msg_text, MSG_SIZE, stdin);
            msg.msg_type = 1;
            msgsnd(msgid, &msg, strlen(msg.msg_text) + 1, 0);
            if (strcmp(msg.msg_text, "quit\n") == 0) {
                break;
            }
        }
    } else { // child process
        while (1) {
            msgrcv(msgid, &msg, MSG_SIZE, 1, 0);
            printf("Received message from parent (pid %d): %s", getpid(), msg.msg_text);
            if (strcmp(msg.msg_text, "quit\n") == 0) {
                break;
            }
            printf("Enter message to parent: ");
            fgets(msg.msg_text, MSG_SIZE, stdin);
            msg.msg_type = 1;
            msgsnd(msgid, &msg, strlen(msg.msg_text) + 1, 0);
        }
    }

 

    msgctl(msgid, IPC_RMID, NULL);

 

    return 0;
}
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
