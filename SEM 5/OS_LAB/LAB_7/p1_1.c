#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>

struct msg_struct{
    long int type;
    char num[256];
};

int chkPalin(char str[], int k){
    int n = k-1;
    int i = 0, j = n-1;
    while(i<=j){
        if(str[i] == str[j]){
            i++;
            j--;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int main(){
    int running = 1;
    int msgid;
    int k;
    struct msg_struct msg;
    long int msg_to_recv = 0;
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if(msgid == -1)
        exit(EXIT_FAILURE);
    while(running){
        if((k = msgrcv(msgid, (void*)&msg, 256, msg_to_recv, 0)) == -1)
            exit(EXIT_FAILURE);
        if(strncmp(msg.num, "-1", 2) == 0)
            running = 0;
        if(chkPalin(msg.num, k)){
            printf("Palindrome\n");
        }
        else{
            printf("Not Palindrome\n");
        }
    }
    if(msgctl(msgid, IPC_RMID, 0) == -1)
        exit(EXIT_FAILURE);
    
    exit(EXIT_SUCCESS);
}