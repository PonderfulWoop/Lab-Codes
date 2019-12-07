#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    int fd[2];
    char buff[256];
    char* data = "Hello darkness my old friend!";
    pipe(fd);
    write(fd[1], data, strlen(data));
    if((n = read(fd[0], buff, 256))>=0){
        buff[n] = '\0';
        printf("Read from the pipe: %s\n", buff);
    }
    else{
        exit(-1);
    }
    exit(0);
}