#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shm_com.h"

int main(){
    int running = 1;
    void* shared_mem = (void*)0;
    struct shared_use_st* shared_stuff;
    char buff[256];
    int shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666|IPC_CREAT);
    if(shmid == -1)
        exit(EXIT_FAILURE);
    shared_mem = shmat(shmid, (void*)0, 0);
    if(shared_mem == (void*)-1)
        exit(EXIT_FAILURE);
    printf("Memory attached: %d\n", (int)shared_mem);
    shared_stuff = (struct shared_use_st *)shared_mem;
    while(running){
        while(shared_stuff->written == 1){
            sleep(1);
            printf("waiting for client..\n");
        }
        printf("Enter some text:\n");
        fgets(buff, 256, stdin);
        strncpy(shared_stuff->text, buff, 2048);
        shared_stuff->written = 1;
        if(strncmp(buff, "end", 3) == 0)
            running = 0;
    }
    if(shmdt(shared_mem) == -1)
        exit(EXIT_FAILURE);
    
    exit(EXIT_SUCCESS);
}