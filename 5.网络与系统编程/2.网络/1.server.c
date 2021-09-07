/*************************************************************************
	> File Name: 1.server.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 26 Jan 2021 08:50:30 PM CST
 ************************************************************************/

#include "common/head.h" 
int main(int argc, char **argv) {
    int server_listen, sockfd, port;  // socket * 2：一个持续监听用、一个给新的连接通信用
    if (argc != 2) {
        fprintf(stderr, "Usage : %s port!\n", argv[0]);
        exit(1);
    }
    // 0、获取输入：port
    port = atoi(argv[1]);             // const char *str -> int
    // 1、调用接口：在指定端口创建一个监听态的快递员
    if ((server_listen = socket_create(port)) < 0) {
        perror("socket_create");
        exit(1);
    }

    // 2、可持续监听，接受多个连接
    struct sockaddr_in client;            // 客户端的地址 [sockaddr_in类型]
    socklen_t len = sizeof(client);       // 地址长度
    while (1) {
        // 2-1、接受连接。sockfd为新的用于传输的快递员
        if ((sockfd = accept(server_listen, (struct sockaddr *)&client, &len)) < 0) {
            perror("accept");
            exit(1);
        }
        printf("<%s> is online.\n", inet_ntoa(client.sin_addr));
        // 用于连接多个客户端
        pid_t pid;
        if ((pid = fork()) < 0) {
            exit(1);
        }
        if (pid == 0) {
        // 2-2、子进程用于传输数据
            close(server_listen);         // 关闭子进程中不需要的资源 [监听态的socket]
            // 循环
            while (1) {
                char buff[512] = {0};     // 存放接收数据
                char tobuff[1024] = {0};  // 存放反馈信息
                // [1] 接收
                size_t ret = recv(sockfd, buff, sizeof(buff), 0);  // sizeof：能收多少收多少
                if (ret <= 0) {
                // < 0 连接出错；= 0 连接关闭
                    printf("<%s> is offline.\n", inet_ntoa(client.sin_addr));
                    close(sockfd);
                    exit(1);
                }
                printf("<%s>: %s\n", inet_ntoa(client.sin_addr), buff);
                // [2] 反馈
                sprintf(tobuff, "I've received your message: %s", buff);
                send(sockfd, tobuff, strlen(tobuff), 0);           // strlen：有多少发多少
            }
        } else {
        // 2-3、父进程继续下一次循环，接收连接
            //printf("<Parent> : nothing to do...\n");
            close(sockfd);                // 不会与对端断开连接 [只有文件打开数为0才会]
        }
    }
    return 0;
}
