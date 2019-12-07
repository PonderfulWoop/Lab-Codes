#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <unistd.h>

struct msg_s{
    long int type;
    int no;
};

int main(){
    struct msg_s msg;
    int n;
    int running = 1;
    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    while(running){
        printf("Enter a number: \n");
        scanf("%d", &n);
        msg.type = 1;
        msg.no = n;
        int k = msgsnd(msgid, (void*)&msg, sizeof(int), 0);
        printf("\n");
        if(n == -1)
            running = 0;
    }
}