#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define port 10200

int server_sockfd, client_sockfd;
int client_len;
struct sockaddr_in server_addr;
struct sockaddr_in client_addr;
char * time_str;
int result;

fd_set readfds, testfds;

void CreateServerSocket(){
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("10.86.3.14");
    server_addr.sin_port = htons(port);

    bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

}

void PerformServerTask(){
    listen(server_sockfd, 5);
    FD_ZERO(&readfds);
    FD_SET(server_sockfd, &readfds);

    while(1){
        char ch;
        int fd, nread;
        testfds = readfds;
        printf("server waiting\n");
        result = select(FD_SETSIZE, &testfds, (fd_set *)0, (fd_set *)0, (struct timeval *)0);
        if(result < 0){
            perror("server error");
            exit(1);
        }
        for(fd = 0; fd<FD_SETSIZE; fd++){
            if(FD_ISSET(fd, &testfds)){
                if(fd == server_sockfd){
                    client_len = sizeof(client_addr);
                    client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_len);
                    FD_SET(client_sockfd, &readfds);
                    printf("adding client on fd %d\n", client_sockfd);
                }
                else{
                    ioctl(fd, FIONREAD, &nread);
                    if(nread == 0){
                        close(fd);
                        FD_CLR(fd, &readfds);
                        printf("removing client on fd %d\n", fd);
                    }
                    else{
                        read(fd, &ch, 1);
                        sleep(5);
                        printf("serving client on fd %d\n", fd);
                        time_t mytime = time(NULL);
                        time_str = ctime(&mytime);
                        time_str[strlen(time_str) - 1] = '\0';
                        write(fd, time_str, 255);
                    }
                }
            }
        }
    }
}

int main(){
    CreateServerSocket();
    PerformServerTask();
}
