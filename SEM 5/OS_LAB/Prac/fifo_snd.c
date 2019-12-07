#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/stat.h>

#define FIFO "/tmp/my_fifo"
#define SIZE sizeof(int)

int main(){
    int pipe_fd;
    int res;
    int open_mode = O_WRONLY;
    int n;
    printf("Enter a number:\n");
    scanf("%d", &n);

    if(access(FIFO, F_OK) == -1)
        mkfifo(FIFO, 0777);
    
    pipe_fd = open(FIFO, open_mode);
    if(pipe_fd != -1){
        res = write(pipe_fd, &n, SIZE);
        (void)close(pipe_fd);
    }
    exit(0);
}
