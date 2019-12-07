#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <time.h>
#include <sys/types.h>

#define port 10200

int sockfd, newsockfd;
struct sockaddr_in seraddr, cliaddr;
char buf[255];
time_t mytime;
char * time_str;

void CreateServerSocket(){
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    seraddr.sin_addr.s_addr = inet_addr("172.16.57.115");
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(port);

    bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    printf("Waiting\n");
}
void PerformServerTask(){
    listen(sockfd, 5);
    while(1){
        int clilen = sizeof(cliaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        read(newsockfd, buf, 255);
        printf("Sending date back::::\n");
        int pid = getpid();
        char mypid[6];   // ex. 34567
        sprintf(mypid, "%d", pid);
        write(newsockfd, time_str, 255);
        write(newsockfd, mypid, 255);
        break;
    }
}

int main(){
    mytime = time(NULL);
    time_str = ctime(&mytime);
    time_str[strlen(time_str) - 1] = '\0';
    CreateServerSocket();
    PerformServerTask();
}