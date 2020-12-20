/*************************************************************************
	> File Name: 6.switch.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 17 Oct 2020 03:14:46 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    int ret;
    while ((ret = scanf("%d", &n)) != -1) {
        if (!ret) {
            getchar();
            printf("Please input a number!\n");
            continue;
        }
        switch (n) {
            case 1: {
                printf("one\n");
                break;
            }
            case 2: {
                printf("two\n");
                break;
            }
            case 3: {
                printf("three\n");
                break;
            }
            default: {
                printf("error\n");
                break;
            }
        }
        switch(n) {
            case 1: {
                printf("one ");
            }
            case 2: {
                printf("two ");
            }
            case 3: {
                printf("three\n");
                break;
            }
            default: {
                printf("error\n");
                break;
            }
        }
    }
    return 0;
}
