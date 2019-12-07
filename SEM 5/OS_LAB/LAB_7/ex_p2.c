#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    int fd[2];
    pid_t pid;
    char buf;
    if(pipe(fd) == -1)
        exit(-1);

    pid = fork();

    if(pid == -1)
        exit(-1);

    if(pid == 0){
        close(fd[1]);
        printf("Sent from parent proc: \n");
        while(read(fd[0], &buf, 1)>0)
            write(STDOUT_FILENO, &buf, 1);
        write(STDERR_FILENO, "\n", 1);
        close(fd[0]);
        exit(0);
    }
    else{
        char* data = "Writing this message!!!";
        close(fd[0]);
        write(fd[1], data, strlen(data));
        close(fd[1]);
        wait(NULL);
        exit(0);
    }
}