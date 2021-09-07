/*************************************************************************
	> File Name: tcp_client.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 26 Jan 2021 08:45:29 PM CST
 ************************************************************************/

#include "head.h"

int socket_connect(char *ip, int port) {
    // 1、创建
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return -1;
    }

    // 2-1、填表
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);           // 输入
    server.sin_addr.s_addr = inet_addr(ip);  // 输入
    // 2-2、主动连接指定IP和端口
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        return -1;
    }
    return sockfd;
}

