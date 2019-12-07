#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

struct sockaddr_in sadd, cadd;
int sd;
int matrix[200][200];
int row_no = 0;

void CreateServerSocket(){
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    sadd.sin_addr.s_addr = inet_addr("172.16.57.188");
    sadd.sin_family = AF_INET;
    sadd.sin_port = htons(10000);
    bind(sd, (struct sockaddr *)&sadd, sizeof(sadd));
}

void addToMatrix(int row[], int n){
    for(int i = 0; i<n; i++){
        matrix[row_no][i] = row[i];
    }
    row_no++;
}

void PerformServerTask(){
    printf("Waiting\n");
    int len = sizeof(cadd);
    while(1){
        int n;
        recvfrom(sd, &n, sizeof(int), 0, (struct sockaddr *)&cadd, &len);
        int row[n];
        if(n == -1)
            break;
        recvfrom(sd, row, sizeof(row), 0, (struct sockaddr *)&cadd, &len);
        addToMatrix(row, n);
    }
    printf("\nThe Matrix::::\n");
    for(int i = 0; i<=row_no; i++){
        int k = 0;
        while(matrix[i][k] != 0){
            printf("%d ", matrix[i][k]);
            k++;
        }
        printf("\n");
    }
}

int main(){
    CreateServerSocket();
    PerformServerTask();
}
