#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define port 10200

int sockfd;
struct sockaddr_in addr;
char buf[255], ch[255];

void CreateClientSocket(){
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_addr.s_addr = inet_addr("172.16.57.115");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
}
void PerformClientTask(){
    printf("Enter DT:\n");
    gets(ch);
    ch[strlen(ch)] = '\0';
    write(sockfd, ch, 255);
    printf("sent back: \n");
    while(1){
        read(sockfd, buf, 255);
        puts(buf);
        read(sockfd, buf, 255);
        puts(buf);
        break;
    }
}

int main(){
    CreateClientSocket();
    PerformClientTask();
}