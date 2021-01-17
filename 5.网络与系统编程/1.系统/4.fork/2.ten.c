/*************************************************************************
	> File Name: 2.ten.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 07 Jan 2021 07:35:33 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    int i;           // 方便下面打印自己“是第i个孩子”
    for (i = 1; i <= 10; i++) {
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        if (pid == 0) break;  // 【关键】
        // 否则子进程还在for循环里，也会产生子进程
    }
    printf("我是第 %d 个孩子\n", i);   // i变量继承自父进程
    sleep(10);                         // 进程sleep，i值相互独立
    printf("我还是第 %d 个孩子\n", i); // i在每个子进程中保持原有值
    return 0;
}
