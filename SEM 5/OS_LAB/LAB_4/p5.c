#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

int main(){
    char buf[100] = "Hello World!";
    mode_t mode = S_IRUSR | S_IWUSR;
    int fp = creat("file.txt", mode);
    if(write(fp, buf, strlen(buf)) < 0){
        printf("Error writing\n");
        exit(-1);
    }

    if(close(fp) == 0){
        printf("Success\n");
        exit(0);
    }
    exit(-1);
}