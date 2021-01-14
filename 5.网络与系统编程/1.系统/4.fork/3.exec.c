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
        execl("./a.out", "./a.out", "3.exec.c", NULL);
        sleep(1000);
        printf("In End!\n");
    } else {

        wait(NULL);
        printf("After Child Terminated\n");
        sleep(5);
    }

    return 0;
}
