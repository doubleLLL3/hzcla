/*************************************************************************
	> File Name: 2.ten.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 07 Jan 2021 07:35:33 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    int i;
    //int id[15];
    for (i = 1; i <= 10; i++) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        if (pid == 0) break;
        /*
        if (pid == 0) {
            printf("1");
        } else {

            printf("0");
        }
        */
        
    }
    printf("我是第 %d 个孩子\n", i);
    sleep(5);
    return 0;
}
