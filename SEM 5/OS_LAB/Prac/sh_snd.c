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
    void* shared_mem = (void*)0;
    struct shared_st* stuff;
    int n;
    int shmid = shmget((key_t)1234, sizeof(struct shared_st), 0666 | IPC_CREAT);
    shared_mem = shmat(shmid, (void*)0, 0);
    stuff = (struct shared_st*)shared_mem;

    printf("Enter number:\n");
    scanf("%d", &n);
    stuff->data = n;
    stuff->written = 1;

    while(stuff->written){}

    shmdt(shared_mem);
}