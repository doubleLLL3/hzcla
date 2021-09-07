/*************************************************************************
	> File Name: common.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 05 Jan 2021 06:36:50 PM CST
 ************************************************************************/
#include "head.h"

int make_nonblock(int fd) {
    int flag;
    // 必须先获得之前的flag
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        // fcntl有可能出错
        perror("fcntl");
        return -1;
    }
    // 在之前的flag上添加属性
    flag |= O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);  // 0: success, -1: error
}

int make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        perror("fcntl");
        return -1;
    }
    // 关注取反操作
    flag &= ~O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);
}

int recv_str_nonblock(int sockfd, char *buff, long size, int timeout) {
    // select，注意timeout为usec
    // 参照man手册的EXAMPLE
    fd_set rfds;
    int ret;
    struct timeval tv;
    
    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);

    tv.tv_sec = 0;
    tv.tv_usec = timeout;

    if ((ret = select(sockfd + 1, &rfds, NULL, NULL, &tv)) <= 0) {
        return -1;
    }

    int rsize = recv(sockfd, buff, sizeof(buff), 0);
    if (rsize <= 0) {
        return -1;
    }
    return 0;
}
