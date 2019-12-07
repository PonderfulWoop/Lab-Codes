#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>

struct msg_struct{
    long int type;
    char text[256];
};

int main(){
    int running = 1;
    int msgid;
    struct msg_struct msg;
    long int msg_to_recv = 0;
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if(msgid == -1)
        exit(EXIT_FAILURE);
    while(running){
        if(msgrcv(msgid, (void*)&msg, 256, msg_to_recv, 0) == -1)
            exit(EXIT_FAILURE);
        
        printf("Written: %s", msg.text);
        if(strncmp(msg.text, "end", 3) == 0)
            running = 0;
    }
    if(msgctl(msgid, IPC_RMID, 0) == -1)
        exit(EXIT_FAILURE);
    
    exit(EXIT_SUCCESS);
}