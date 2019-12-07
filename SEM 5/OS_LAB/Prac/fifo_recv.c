#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/stat.h>

#define FIFO "/tmp/my_fifo"
#define SIZE sizeof(int)

int main(){
    int pipe_fd;
    int res;
    int open_mode = O_RDONLY;
    int n;
    
    pipe_fd = open(FIFO, open_mode);
    if(pipe_fd != -1){
        res = read(pipe_fd, &n, SIZE);
        (void)close(pipe_fd);
    }
    if(n%2 == 0)
        printf("EVEN\n");
    else
        printf("ODD\n");
    
    exit(0);
}