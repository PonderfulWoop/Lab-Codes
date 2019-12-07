#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define port 10200

int sockfd, newsockfd;
struct sockaddr_in seraddr, cliaddr;
char buf[255];

void CreateServerSocket(){
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    seraddr.sin_addr.s_addr = inet_addr("172.16.57.115");
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(port);

    bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    printf("Waiting:\n");
}
void PerformServerTask(){
    listen(sockfd, 5);
    while(1){
        int clilen = sizeof(cliaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        read(newsockfd, buf, 255);
        printf("Message: %s\n", buf);
        write(newsockfd, buf, 255);
        break;
    }
}

int main(){
    CreateServerSocket();
    PerformServerTask();
}