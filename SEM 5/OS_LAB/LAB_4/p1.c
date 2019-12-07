#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
    int status;
    pid_t pid;
    pid = fork();
    
    if(pid == -1)
        printf("\nProcess_p1 fork error\n");
    else if(pid == 0){
        printf("\nChild_p1 process \n");
        exit(0);
    }
    else{
        wait(&status);
        printf("\n Parent_p1 Process \n");
        printf("\n Child finished with: %d\n", status);
    }
}
