/*************************************************************************
	> File Name: 1.server.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 26 Jan 2021 08:50:30 PM CST
 ************************************************************************/

#include "common/head.h" 
int main(int argc, char **argv) {
    int server_listen, sockfd, port;  // 创建了两个socket：一个为被动
    if (argc != 2) {
        fprintf(stderr, "Usage : %s port!\n", argv[0]);
    }
    port = atoi(argv[1]);
    if ((server_listen = socket_create(port)) < 0) {
        perror("socket_create");
        exit(1);
    }
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    while (1) {
        // 只要有人发，就会回；被动
        if ((sockfd = accept(server_listen, (struct sockaddr *)&client, &len)) < 0) {
            perror("accept");
            exit(1);
        }
        printf("<%s> is online.\n", inet_ntoa(client.sin_addr));
        // 此时已有2个socket
        pid_t pid;
        if ((pid = fork()) < 0) {
            exit(1);
        }
        if (pid == 0) {
            close(server_listen);  // 关闭子进程中不需要的资源
            while (1) {
                char buff[512] = {0};
                char tobuff[1024] = {0};
                size_t ret = recv(sockfd, buff, sizeof(buff), 0);
                if (ret <= 0) {
                    printf("<%s> is offline.\n", inet_ntoa(client.sin_addr));
                    close(sockfd);
                    exit(1);
                }
                printf("recv : %s\n", buff);
                sprintf(tobuff, "I've recved your message: %s", buff);
                send(sockfd, tobuff, strlen(tobuff), 0);
            }
        } else {
            printf("<Parent> : 什么也不干...\n");
            close(sockfd);  // 是否真的对对端产生影响
        }
    }
}
