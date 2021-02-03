/*************************************************************************
	> File Name: tcp_server.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 26 Jan 2021 08:39:08 PM CST
 ************************************************************************/

#include "head.h"

int socket_create(int port) {
    int sockfd;
    // 类似于创建一个快递员: ipv4, TCP。socket属于系统调用
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        // 可能失败：如数量限制
        return -1;
    }
    // 填写表单
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;  // ipv4
    addr.sin_port = htons(port); // 端口：可以随意写 [但可能出错]
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");  // 任意IP地址的数据都收
    
    // 绑定0~1023号端口需要权限
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        return -1;
    }
    // 变为被动，队列长度为20，可以由20个人等
    if (listen(sockfd, 20) < 0) {
        return -1;
    }
    return sockfd;
}

