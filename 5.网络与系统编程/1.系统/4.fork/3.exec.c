/*************************************************************************
	> File Name: 3.exec.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 07 Jan 2021 08:10:10 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if (pid == 0) {
        execlp("vim", "vim", "3.exec.c", NULL);
        //execl("./Test", "who am i", NULL);
        // 下面的代码永远不会执行，理解exec族的本质 [替换为全新]
        sleep(1000);
        printf("In End!\n");
    } else {
        wait(NULL);  // 只负责收尸，不关注子进程如何结束
        printf("After Child Terminated\n");
        sleep(5);
    }

    return 0;
}
