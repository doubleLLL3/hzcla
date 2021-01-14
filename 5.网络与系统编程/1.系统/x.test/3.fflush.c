/*************************************************************************
	> File Name: 3.fflush.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 31 Dec 2020 07:55:21 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main() {
    fprintf(stderr, "Hello world!");  // stderr是无缓冲的
    printf("Hello world!");
    //fflush(stdout);                 // 手动刷新缓冲区
    sleep(2);                         // <unistd.h>
    printf("\n");                     // 刷新缓冲区 [stdout是行缓冲的]
    sleep(5);
    return 0;
}
