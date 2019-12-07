#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(){
    int fd_1 = open("file.txt", O_RDONLY);
    char buff[256];
    int k = read(fd_1, buff, sizeof(buff));
    mode_t mode = S_IRUSR | S_IWUSR;
    int fd_2 = creat("file_2.txt", mode);
    write(fd_2, buff, k);
    
    close(fd_1);
    close(fd_2);
}
