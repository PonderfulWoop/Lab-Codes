#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
 
int sockfd, len, result;
struct sockaddr_in address;
char hostname[200] = "www.example.com";
char *header = "GET /index.html HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
char ip[200];
char buf[256];

int get_ip(char * hostname , char* ip) 
{  struct hostent *he;     
   struct in_addr **addr_list;     
   int i;     
   if ( (he = gethostbyname( hostname ) ) == NULL)     
   { herror("gethostbyname");         
     return 1;}     
   addr_list = (struct in_addr **) he->h_addr_list;
    for(i = 0; addr_list[i] != NULL; i++)
    {   strcpy(ip , inet_ntoa(*addr_list[i]) );
        return 0;}
    return 1;
}
 
void CreateClientSocket(){
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip);
    address.sin_port = htons(80);
    len = sizeof(address);
    result = connect(sockfd, (struct sockaddr *)&address, len);
}
 
void PerformClientTask(){
    while(1){
        send(sockfd, header, strlen(header), 0);
        printf("\nSent Back from server:\n");
        recv(sockfd, buf, 255, 0);
        printf("%s", buf);
        break;
    }
}
 
int main(){
    get_ip(hostname, ip);
    CreateClientSocket();
    if (result == -1){
        printf("Error\n");
        exit(1);
    }
    PerformClientTask();
}