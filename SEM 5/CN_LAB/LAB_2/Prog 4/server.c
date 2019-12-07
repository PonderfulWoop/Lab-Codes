#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define port 10200

int sockfd, newsockfd;
struct sockaddr_in seraddr, cliaddr;
int n;

void CreateServerSocket(){
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(port);
    seraddr.sin_addr.s_addr = inet_addr("10.86.3.14");
    bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    printf("Waiting\n");
}
void PerformServerTask(){
    listen(sockfd, 5);
    while(1){
        int clilen = sizeof(cliaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        int arr[2];
        char op;
        if(fork() == 0){
            recv(newsockfd, arr, sizeof(arr), 0);
            recv(newsockfd, &op, sizeof(op), 0);
            printf("PORT for the client: %d\n", ntohs(cliaddr.sin_port));
            int result;
            switch(op){
                case '+':
                    result = arr[0] + arr[1];
                    break;
                case '-':
                    result = arr[0] - arr[1];
                    break;
                case '*':
                    result = arr[0]*arr[1];
                    break;
                case '/':
                    result = (int) arr[0]/arr[1];
                    break;
            }
            send(newsockfd, &result, sizeof(int), 0);
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