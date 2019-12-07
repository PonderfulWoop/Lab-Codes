#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

int sd;
struct sockaddr_in addr;

void CreateClientSocket(){
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    addr.sin_addr.s_addr = inet_addr("172.16.57.188");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(10000);
}

void PerformClientTask(){
    int n;
    int len = sizeof(addr);
    while(1){
        printf("Enter number of elems for row:\n");
        scanf("%d", &n);
        if(n == -1){
            sendto(sd, &n, sizeof(n), 0, (struct sockaddr *)&addr, len);
            break;
        }
        int arr[n];
        printf("Enter elems:\n");
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        sendto(sd, &n, sizeof(n), 0, (struct sockaddr *)&addr, len);
        sendto(sd, arr, sizeof(arr), 0, (struct sockaddr *)&addr, len);
        printf("Sent Row:::::\n");
    }
}

int main(){
    CreateClientSocket();
    PerformClientTask();
}
