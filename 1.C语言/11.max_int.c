/*************************************************************************
	> File Name: 11.max_int.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 22 Oct 2020 06:32:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#include<stdarg.h>

int max_int(int n, ...) {
    int ans = INT32_MIN;  // 考虑负数，需包含<inttypes.h>
    va_list arg;  // 需包含头文件<stdarg.h>
    va_start(arg, n);  // 将arg指向变参列表第一个参数的位置
    while (n--) {
        int temp = va_arg(arg, int);  // 返回下一个类型匹配的表达式
        //printf("%lf ", temp);
        if (temp > ans) ans = temp;
    }
    va_end(arg);  // 结束对可变函数实参的遍历，清除va_list空间
    return ans;
}

int main() {
    printf("-->%d\n", max_int(3, 2, 5, 10));               // 10
    printf("-->%d\n", max_int(2, 3, 4));                   // 4
    printf("-->%d\n", max_int(6, 1, 2, 4, 5, 7, 15, 17));  // 15 因为17已经在6个以外了
    return 0;
}
