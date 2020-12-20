/*************************************************************************
	> File Name: 10.ex_gcd.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 20 Oct 2020 08:43:39 PM CST
 ************************************************************************/

#include<stdio.h>

int ex_gcd(int a, int b, int *x, int *y) {  // x、y需用指针方式，一开始没有值
    if (!b) {
        *x = 1, *y = 0;  // y可以为任意值
        return a;
    }
    // 递推过程，一直到x = 1, y = 0返回
    // xx、yy为中间值，ret为第k层的返回值
    int xx, yy, ret = ex_gcd(b, a % b, &xx, &yy);
    // 回溯过程
    *x = yy;
    *y = xx - a / b * yy;  // k值为a / b下取整
    return ret;  // 即a、b的最大公约数
}

int main() {
    int a, b, x, y;
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("ex_gcd(%d, %d) = %d\n", a, b, ex_gcd(a, b, &x, &y));  // 输出最大公约数
        printf("%d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);  // 输出求解结果
    }

    return 0;
}
