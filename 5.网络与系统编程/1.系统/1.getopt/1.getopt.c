/*************************************************************************
	> File Name: 1.getopt.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 29 Dec 2020 07:58:16 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>  // exit()
#include <unistd.h>  // getopt()

// 需要主函数的argc、argv
int main(int argc, char **argv) {
    int opt; // 返回值
    int a_flag = 0, l_flag = 0;  // 根据flag可分开写相应的功能
    // 使用循环：getopt里有一个指针optind
    while ((opt = getopt(argc, argv, "alm:o::")) != -1) {
        switch (opt) {
            case 'a':
                a_flag = 1;
                printf("a found!\n");
                break;
            case 'l':
                l_flag = 1;
                printf("l found!\n");
                break;
            case 'm':
                printf("msg = %s\n", optarg);
                break;
            case 'o':
                printf("opt = %s\n", optarg);
                break;
            default:
                // 打印到stderr，并退出程序
                fprintf(stderr, "Usage : %s -alm[]o[...]\n", argv[0]);
                exit(1);         // 非正常运行导致退出程序
        }
    }
    // 可直接输出外部变量
    printf("optind = %d\noptopt = %d\n", optind, optopt);
    return 0;
}
