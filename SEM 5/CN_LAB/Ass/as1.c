#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

char buf[256];
struct sockaddr_in addr;
int sockfd;

void CreateClientSocket(){
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_addr.s_addr = inet_addr("172.16.58.36");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9734);

    connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
}

void PerformClientTask(){
    int n;
    printf("Enter a number:\n");
    scanf("%d", &n);
    send(sockfd, &n, sizeof(n), 0); //Sending to server
    recv(sockfd, buf, 256, 0); //receiving from server

    printf("Received: %s\n", buf);
}

int main(){
    CreateClientSocket();
    PerformClientTask();
}