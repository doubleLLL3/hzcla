/*************************************************************************
	> File Name: oj-69.c
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 24 Nov 2020 04:36:11 PM CST
 ************************************************************************/
#include <stdio.h>
// 版本一：空间换时间版
int check(int y, int m, int d) {
    if (m <= 0 || m > 12 || d <= 0) return 0;
    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 对于闰年处理下数组即可
    if ((y % 4 == 0 && y % 100) || y % 400 == 0) month[2]++; 
    return d <= month[m];
}
// 版本二：复杂的if else版
int check_bad(int y, int m, int d) {
    if (m <= 0 || m > 12 || d <= 0) return 0;       // 基本的合法性判断
    // 每月的天数判断
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
        if (d <= 31) 
            return 1;
        else 
            return 0;
    } else {
        if (m == 2) {
            // 对于2月份，判断是否为闰年
            if ((y % 4 == 0 && y % 100) || y % 400 == 0) {
                return d <= 29;
            }
            return d <= 28;                         // 不是闰年的情况
        }
        return d <= 30;
    }
}

int main() {
    int y, m, d;
    // 读取年月日
    scanf("%d%d%d", &y, &m, &d);
    /*if (check(y, m, d)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }*/ 
    printf("%s\n", check(y, m, d) ? "YES" : "NO");  // if else → 三目运算符
    return 0;
}
