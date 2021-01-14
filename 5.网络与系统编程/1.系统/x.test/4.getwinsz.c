/*************************************************************************
	> File Name: 4.getwinsz.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 31 Dec 2020 08:35:59 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    struct winsize sz;
    if (ioctl(STDOUT_FILENO, TIOGCWINSZ, &sz) <0)  {
        // STDOUT_FILENO写1也可以
        pererror("ioctl");
        exit(1);
    }
    printf("size.x = %d, size.y = %d\n", sz.ws_col, sz.ws_row);
    return 0;
}
