#include <stdio.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    int chars = 0, lines = 0, words = 0;
    int fd = open("big_file.txt", O_RDONLY);
    char buff[256];
    int k = read(fd, buff, sizeof(buff));
    chars = k;
    for(int i = 0; i<k; i++){
        if(buff[i] == '\n' || buff[i] == '\0')
            lines++;
        if(buff[i] == ' ' || buff[i] == '\t' || buff[i] == '\n' || buff[i] == '\0'){
            words++;
        }
    }
    printf("Chars: %d, Words: %d, Lines: %d\n", chars, words, lines);
}