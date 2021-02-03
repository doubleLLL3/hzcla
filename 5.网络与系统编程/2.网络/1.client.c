/*************************************************************************
	> File Name: 1.client.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 26 Jan 2021 08:55:50 PM CST
 ************************************************************************/

#include "common/head.h"
int sockfd;

// 函数出入参数没用到，但规定要有
void logout(int signum) {
    close(sockfd);
    printf("ByeBye!\n");
    exit(1);
}

int main(int argc, char **argv) {
    int port;
    char buff[512] = {0}, ip[20] = {0};

    if (argc != 3) {
        fprintf(stderr, "Usage : %s ip port\n", argv[0]);
        exit(1);
    }
    strcpy(ip, argv[1]);
    port = atoi(argv[2]);
    signal(SIGINT, logout); 
    if ((sockfd = socket_connect(ip, port)) < 0) {
        perror("socket_connet");
        exit(1);
    }
    
    printf("I think is connected.\n");

    while (1) {
        printf("<input> : ");
        scanf("%[^\n]s", buff);
        getchar();
        if (!strlen(buff)) continue;
        send(sockfd, buff, strlen(buff), 0);
        printf("sending %s...\n", buff);
        bzero(buff, sizeof(buff));
        recv(sockfd, buff, sizeof(buff), 0);
        printf("<Server> : %s\n", buff);
        bzero(buff, sizeof(buff));
    }
    return 0;
}

