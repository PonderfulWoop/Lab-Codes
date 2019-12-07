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
        printf("Child_P2 process\n");
        execlp("./p1", "p1", NULL);
        exit(0);
    }
    else{
        wait(&status);
        printf("Parent_P2 process\n");
        printf("\nChild_P2 finished with: %d\n", status);
        exit(0);
    }

}