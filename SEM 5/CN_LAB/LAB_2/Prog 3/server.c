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

void sortArr(int a[], int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j< len-i-1; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void PerformServerTask(){
    listen(sockfd, 5);
    while(1){
        int clilen = sizeof(cliaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        int arr[100];
        if(fork() == 0){
            n = recv(newsockfd, arr, sizeof(arr), 0);
            n = n/sizeof(int);
            printf("PORT for the client: %d\n", ntohs(cliaddr.sin_port));
            printf("Length of array sent: %d", n);
            sortArr(arr, n);
            send(newsockfd, arr, sizeof(arr), 0);
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