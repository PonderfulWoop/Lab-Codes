#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/ipc.h>

struct msg_struct{
    long int type;
    char num[256];
};

int main(){
    int running = 1;
    struct msg_struct msg;
    int msgid;

    char buff[256];
    msgid = msgget((key_t)1234, 0666|IPC_CREAT);
    if(msgid == -1)
        exit(EXIT_FAILURE);
    while(running){
        printf("Enter num:\n");
        fgets(buff, 256, stdin);
        msg.type = 1;
        strcpy(msg.num, buff);
        if(msgsnd(msgid, (void *)&msg, strlen(buff), 0) == -1)
            exit(EXIT_FAILURE);
        if(strncmp(buff, "end", 3) == 0)
            running = 0;
    }
    exit(EXIT_SUCCESS);
}