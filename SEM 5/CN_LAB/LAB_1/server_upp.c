#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define port 10200

int sockfd, newsockfd;
struct sockaddr_in seraddr, cliaddr;

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
    int clilen = sizeof(cliaddr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
    printf("IP: %s\n", inet_ntoa(cliaddr.sin_addr));
    printf("PORT: %d\n", ntohs(cliaddr.sin_port));

    while(1){
        char buf[255];
        read(newsockfd, buf, 255);
        if(strcmp(buf, "quit") == 0)
            break;
        for(int i = 0; i<strlen(buf); i++)
            if((int)buf[i] < 97)
                continue;
            else
                buf[i] = (char)(buf[i]^32);
        printf("Message Sent: %s\n", buf);
        write(newsockfd, buf, 255);
    }
}

int main(){
    CreateServerSocket();
    PerformServerTask();
}