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
    printf("Enter number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the numbers: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    send(sockfd, arr, sizeof(arr), 0);
    printf("Sent Back: \n");
    
    recv(sockfd, arr, sizeof(arr), 0);
    printf("Sorted Array: \n");
    for(int k = 0; k < n; k++){
        printf("%d ", arr[k]);
    }
    printf("\n");  
}

int main(){
    CreateClientSocket();
    PerformClientTask();
}