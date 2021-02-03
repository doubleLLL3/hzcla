/*************************************************************************
	> File Name: test.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 19 Jan 2021 11:52:05 AM CST
 ************************************************************************/

#include "head.h"
#define INS 100

struct msg {
	int now, sum;
};

int main(int argc, char **argv) {
    int opt, start = 0, end = 0;
    while ((opt = getopt(argc, argv, "s:e:")) != -1) {
        switch (opt) {
            case 's':
                start = atoi(optarg);  // atoi: 字符串->整数
                break;
            case 'e':
                end = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s -s start_num -e end_num\n", argv[0]);
                exit(1);
        }
    }
    printf("start = %d\nend = %d\n", start, end);

	pid_t pid;
	int x = 0;        // x: 第几号进程
	for (int i = 1; i <= INS; i++) {
	    if ((pid = fork()) < 0) {
	        perror("fork");
	        exit(1);  // 只是图方便，工作中不如此操作
	    }
	    if (pid == 0) {
	        x = i;    // 给子进程编号
	        break;    // 关键，否则会不断套娃
	    }
	}
	if (pid != 0) {
	    // 防止产生僵尸进程
	    for (int i = 1; i <= INS; i++) {
	        wait(NULL);
	    }
	    // 父进程
	    printf("I'm parent!\n");  
	} else {
	    printf("I'm %dth child!\n", x);
	}

    return 0;
}
