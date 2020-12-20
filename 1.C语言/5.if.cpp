/*************************************************************************
	> File Name: 5.grades.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 17 Oct 2020 02:42:49 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    int ret;
    while((ret = scanf("%d", &n)) != -1){
        if (!ret) {
            printf("eat an char: [%c]\n", getchar());
            printf("not an int number!\n");
            continue;
        }
        printf("ret = %d; n = %d\n", ret, n);
        if (n == 0) {
            printf("FOOLISH");
        } else if (n > 0 && n < 60) {
            printf("FAIL");
        } else if (n >= 60 && n <75) {
            printf("MEDIUM");
        } else if (n >= 75 && n <= 100) {
            printf("GOOD");
        } else {
            printf("ERROR INPUT~");
        }
        printf("\n");

        // 可以对条件判断进行冗余检查，减少代码量
        // 因为输入是正整数
        if (!n) {
            printf("F");
        } else if (n < 60) {
            printf("FAIL");
        } else if (n < 75) {
            printf("MEDIUM");
        } else if (n <= 100) {
            printf("GOOD");
        } else {
            printf("ERR");
        }
        printf("\n");
       // break;
    }
    return 0;
}
