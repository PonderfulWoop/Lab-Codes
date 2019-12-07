#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct msg_s{
    long int type;
    int no;
};

int chkEven(int n){
    if(n%2 == 0)
        return 1;
    return 0;
}

int main(){
    int running = 1;
    long int msg_to_recv = 0;
    struct msg_s msg;
    int msgid = msgget((key_t)1234, 0666 | IPC_CREAT);

    while(running){
        int l = msgrcv(msgid, (void*)&msg, sizeof(int), msg_to_recv, 0);
        printf("\n");
        if(msg.no == -1){
            running = 0;
            break;
        }
        if(chkEven(msg.no))
            printf("%d: Even\n", msg.no);
        else
            printf("%d: Odd\n", msg.no);
    }

    msgctl(msgid, IPC_RMID, 0);
}