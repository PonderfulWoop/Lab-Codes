#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE 4*sizeof(int)

int main(){
    int pipe_fd;
    int res;
    int open_mode = O_RDONLY;
    int buff[4];
    int bytes_read = 0;
    memset(buff, '\0', BUFFER_SIZE);
    printf("Process %d opening \n", getpid());
    pipe_fd = open(FIFO_NAME, open_mode);
    printf("Process %d result %d\n", getpid(), pipe_fd);
    if(pipe_fd != -1){
        do{
            res = read(pipe_fd, buff, BUFFER_SIZE);
            bytes_read+=res;
        }while(res>0);
        (void)close(pipe_fd);
    }
    else
        exit(EXIT_FAILURE);
    
    for(int i = 0; i<4; i++)
        printf("%d ", buff[i]);
    printf("\n");
    printf("Process %d finished, %d bytes read", getpid(), bytes_read);
    exit(EXIT_SUCCESS);
}