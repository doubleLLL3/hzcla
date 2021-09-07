/*************************************************************************
	> File Name: 1.client.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 26 Jan 2021 08:55:50 PM CST
 ************************************************************************/

#include "common/head.h"
#include "cmd.h"

int sockfd;

// 函数出入参数没用到，但规定要有
void logout(int signum) {
    close(sockfd);
    printf("ByeBye!\n");
    exit(1);
}

int main(int argc, char **argv) {
    int port;
    char buff[512] = {0}, ip[20] = {0}, name[20] = "double";  // 存放发送/接收数据、要连接的IP [输入]

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
    
    send(sockfd, name, strlen(name), 0);

    if (recv(sockfd, buff, sizeof(buff), 0) <= 0) {
        perror("recv");
        exit(1);
    }
    printf("<Server> %s\n", buff);
    while (1) {
        char cmd[1024] = {0};
        int flag = 0;
        scanf("%[^\n]s", cmd);
        getchar();
        if (!strlen(cmd)) continue;
        // s a.txt
        // r
        if (strlen(cmd) == 1 && cmd[0] == 'r') {
            flag |= RECV;
            send(sockfd, (char *)&flag, sizeof(int), 0);
            printf("Here Recv!\n"); 
        } else if (cmd[0] == 's' && cmd[1] == ' ') {
            flag |= SEND;
            char file[512] = {0};
            strcpy(file, cmd + 2);
            send(sockfd, (char *)&flag, sizeof(int), 0);
            printf("filename = %s\n", file);
            // xxx.jpg
            //send
        } else {
            flag |= NORMAL;
            send(sockfd, (char *)&flag, sizeof(int), 0);
            send(sockfd, cmd, strlen(cmd), 0);
        }
    }
    return 0;
}
