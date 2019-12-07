#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shm_com2.h"

int main(){
    int running = 1;
    void* shared_mem = (void*)0;
    struct shared_use_st* shared_stuff;
    char ch;
    int shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666|IPC_CREAT);
    if(shmid == -1)
        exit(EXIT_FAILURE);
    shared_mem = shmat(shmid, (void*)0, 0);
    if(shared_mem == (void*)-1)
        exit(EXIT_FAILURE);
    printf("Memory attached: %d\n", (int)shared_mem);
    shared_stuff = (struct shared_use_st *)shared_mem;
    while(running){
        if(shared_stuff->written_child){
            printf("written: %c\n", shared_stuff->ch);
            shared_stuff->written_child = 0;
            ch = shared_stuff->ch;
            if(ch == 'c')
                break;
        }
        if(!shared_stuff->written_parent){
            printf("Enter some char:\n");
            scanf("%c", &ch);
            shared_stuff->ch = ch;
            shared_stuff->written_parent = 1;
            sleep(4);
        }
    }
    if(shmdt(shared_mem) == -1)
        exit(EXIT_FAILURE);
    
    exit(EXIT_SUCCESS);
}