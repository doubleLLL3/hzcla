/*************************************************************************
	> File Name: 1.fork.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 07 Jan 2021 06:32:42 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    int status;
    if ((pid = fork()) < 0) {
        perror("fork()");  // 出错的最常见原因：内存不够
        exit(1);
    }
    if (pid == 0) {
        sleep(2);
        printf("Child Process!\n");
        return 100;         // 子进程的返回值
    } else {
        wait(&status);
        printf("Wait Status = %d\n", WEXITSTATUS(status));
    }
    return 0;
    
    char name[20] = {0};
    scanf("%s", name);
    printf("%s", name);  // [关键] 没有'\n'，不会刷新缓冲区
    fork();              // 缓冲区里的数据也会被复制
    
    return 0;
}
