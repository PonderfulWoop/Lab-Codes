#include <sys/shm.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include "shm_com.h"

int main(){
    int running = 1;
    int n;
    void* shared_mem = (void*)0;
    struct shared_st* stuff;
    int shmid = shmget((key_t)1234, sizeof(struct shared_st), 0666|IPC_CREAT);

    shared_mem = shmat(shmid, (void*)0, 0);

    stuff = (struct shared_st*)shared_mem;
    while(running){
        if(stuff->written){
            n = stuff->data;
            if(n%2 == 0)
                printf("EVEN\n");
            else
                printf("ODD\n");
            stuff->written = 0;
            running = 0;
        }
    }
    
    shmdt(shared_mem);
    shmctl(shmid, IPC_RMID, 0);

}