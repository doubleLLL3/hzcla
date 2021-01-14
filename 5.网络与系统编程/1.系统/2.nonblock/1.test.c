/*************************************************************************
	> File Name: 1.test.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 05 Jan 2021 06:53:04 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    int age, ret;
    make_nonblock(0);
    //sleep(5);
    ret = scanf("%d", &age);
    printf("double is %d years old! <%d>\n", age, ret);
    perror("scanf");

    return 0;
}
