/*************************************************************************
	> File Name: common.h
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 05 Jan 2021 06:36:59 PM CST
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H
int make_nonblock(int fd);
int make_block(int fd);
int recv_str_nonblock(int sockfd, char *buff, long size, int timeout);
#endif
