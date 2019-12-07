#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    pid_t pid;
    int status;
    pid = fork();

    if(pid < 0){
        printf("\n Fork Error \n");
        exit(-1);
    }
    else if(!pid){
        printf("old parent: %d\n", getppid());
        int i = 0;
        while(i<10000)
            i++;
        printf("new parent (init): %d\n", getppid());
    }
    else{
        exit(0);
    }
}