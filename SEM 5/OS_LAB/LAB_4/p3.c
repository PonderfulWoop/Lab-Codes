#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t pid;
    int status;
    pid = fork();

    if(pid < 0){
        printf("\n Fork Error \n");
        exit(-1);
    }
    else if(!pid){
        printf("Child: %d", getpid());
        printf("My Parent: %d", getppid());
        exit(0);
    }
    else{
        wait(&status);
        printf("Parent: %d", getpid());
        printf("Parent's parent: %d", getppid());
        exit(0);
    }

}