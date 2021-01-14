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
        sleep(5);
        printf("Child Process!\n");
        return 256;
    } else {
        printf("Parent Process!\n");
        wait(&status);
        printf("wait status = %d\n", status);
        //sleep(500); 
    }
    
    /* 
    char name[20] = {0};
    scanf("%s", name);
    printf("%s", name);
    fork();
    sleep(100);   // sleep几秒才会输出两次；这里不会产生僵尸进程
    */
    return 0;
}
