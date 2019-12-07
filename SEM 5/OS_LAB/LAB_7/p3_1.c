#include <sys/shm.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shm_com2.h"

int main(){
    int running = 1;
    char ch;
    void* shared_mem = (void*)0;
    struct shared_use_st* shared_stuff;
    int shmid;
    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666|IPC_CREAT);
    if(shmid == -1)
        exit(EXIT_FAILURE);
    shared_mem = shmat(shmid, (void*)0, 0);
    if(shared_mem == (void*)-1)
        exit(EXIT_FAILURE);
    printf("Memory attached: %d\n", (int)shared_mem);
    shared_stuff = (struct shared_use_st*)shared_mem;
    shared_stuff->written_parent = 0;
    while(running){
        if(shared_stuff->written_parent){
            ch = shared_stuff->ch;
            printf("written: %c\n", ch);
            printf("sending: %c\n", (char)++ch);
            if(ch == 'c')
                running = 0;
            shared_stuff->ch = ch;
            shared_stuff->written_child = 1;
            shared_stuff->written_parent = 0;
        }
    }

    if(shmdt(shared_mem) == -1)
        exit(EXIT_FAILURE);
    if(shmctl(shmid, IPC_RMID, 0) == -1)
        exit(EXIT_FAILURE);
    
    exit(EXIT_SUCCESS);
}