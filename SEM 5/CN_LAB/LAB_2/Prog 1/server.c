#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define port 10200

int sockfd, newsockfd;
struct sockaddr_in seraddr, cliaddr;
char buf[255];

void CreateServerSocket(){
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(port);
    seraddr.sin_addr.s_addr = inet_addr("172.16.57.109");

    bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));

}

void PerformServerTask(){
    listen(sockfd, 5);
    while(1){
        int clilen = sizeof(clilen);
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        if(fork() == 0){
            read(newsockfd, buf, sizeof(buf));
            printf("PORT for the client: %d", ntohs(cliaddr.sin_port));
            printf("\nMessage from Client %s \n", buf);
            write(newsockfd, buf, sizeof(buf));
            close(newsockfd);
            exit(0);
        }
        else{
            close(newsockfd);
        }
    }
}

int main(){
    CreateServerSocket();
    PerformServerTask();
}