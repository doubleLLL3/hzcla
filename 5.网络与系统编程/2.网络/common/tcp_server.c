/*************************************************************************
	> File Name: tcp_server.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 26 Jan 2021 08:39:08 PM CST
 ************************************************************************/

#include "head.h"

int socket_create(int port) {
    // 1、创建一个快递员: ipv4、字节流、TCP [socket属于系统调用]
    int sockfd;                                   // 记录快递员ID
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        // 可能失败：如文件打开数量限制
        return -1;                                // 作为接口，返回-1给上层处理
    }

    // 2-1、填写表单供bind使用：sockaddr_in -> sockaddr
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;                    // ipv4
    addr.sin_port = htons(port);                  // htons：主机->网络；端口：输入参数
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");  // 0.0.0.0代表可接受对于本机任意IP地址的连接
    // 2-2、绑定IP和端口：0~1023号端口需要权限 [周知端口]
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        return -1;                                // 可能没有权限；可能端口已被占用...
    }

    // 3、设为监听状态 [主动变为被动]；完成队列的长度为20 [两边都处于ESTABLISHED状态]
    if (listen(sockfd, 20) < 0) {
        return -1;
    }
    return sockfd;
}

