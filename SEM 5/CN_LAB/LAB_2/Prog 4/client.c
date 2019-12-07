#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define port 10200

int sockfd, newsockfd;
struct sockaddr_in addr;
int n;

void CreateClientSocket(){
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_addr.s_addr = inet_addr("10.86.3.14");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
}
void PerformClientTask(){
    int arr[2];
    char op;
    printf("Enter two numbers\n");
    scanf("%d%d", &arr[0], &arr[1]);
    printf("Enter the operator: \n");
    scanf(" %c", &op);
    send(sockfd, arr, sizeof(arr), 0);
    send(sockfd, &op, sizeof(op), 0);
    printf("Sent Back: \n");
    int result;
    recv(sockfd, &result, sizeof(int), 0);
    printf("Result: %d\n", result);
}

int main(){
    CreateClientSocket();
    PerformClientTask();
}