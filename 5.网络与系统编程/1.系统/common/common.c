/*************************************************************************
	> File Name: common.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 05 Jan 2021 06:36:50 PM CST
 ************************************************************************/

#include "head.h"

int make_nonblock(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }  // 先要获得之前的flag
    flag |= O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);
}

int make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return -1;
    }  // 先要获得之前的flag
    flag &= ~O_NONBLOCK;
    return fcntl(fd, F_SETFL, flag);
}
