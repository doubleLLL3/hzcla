/*************************************************************************
	> File Name: 1.test.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 05 Jan 2021 06:53:04 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    int age, ret;
    make_nonblock(0);  // 0、1、2文件不需要open，继承自父进程
    sleep(5);        // sleep完再对非阻塞的stdin进行scanf
    ret = scanf("%d", &age);
    printf("double is %d years old! < %d >\n", age, ret);
    perror("scanf");   // 查看此时errno对应的报错信息
    return 0;
}
