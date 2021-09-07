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
    char buff[512] = {0}, ip[20] = {0};  // 存放发送/接收数据、要连接的IP [输入]

    if (argc != 3) {
        fprintf(stderr, "Usage : %s ip port\n", argv[0]);
        exit(1);
    }
    // 0、获取输入：IP、port
    strcpy(ip, argv[1]);
    port = atoi(argv[2]);

    signal(SIGINT, logout); 

    // 1、调用接口：主动连接指定IP和端口
    if ((sockfd = socket_connect(ip, port)) < 0) {
        perror("socket_connet");
        exit(1);
    }
    
    printf("Connected！\n");

    while (1) {
        // 输入要传输的数据
        printf("<input> : ");
        scanf("%[^\n]s", buff);
        getchar();
        if (!strlen(buff)) continue;  // 没有输入?
        // [2] 发送数据
        send(sockfd, buff, strlen(buff), 0);  // strlen：有多少发多少
        printf("sending %s...\n", buff);
        bzero(buff, sizeof(buff));  // 清空供持续使用，并保证数据安全
        // [3] 获取反馈，确认发送成功
        recv(sockfd, buff, sizeof(buff), 0);
        printf("<Server> : %s\n", buff);
        bzero(buff, sizeof(buff));
    }
    return 0;
}

