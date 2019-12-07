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
    if(access(FIFO, F_OK) == -1)
        mkfifo(FIFO, 0777);
    int pipe_fd = open(FIFO, O_WRONLY);
    int n = 132;
    write(pipe_fd, &n, SIZE);
    close(pipe_fd);
}