/*************************************************************************
	> File Name: euler32.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 04 Nov 2020 06:43:36 PM CST
 ************************************************************************/
#include <iostream>
#include <cmath>
using namespace std;
// 判断数字位数
int digit(int x) {
    // floor返回值类型为double
    return (int)floor(log10(x)) + 1;
}
// 检查每个数字，需要传入num
int check(int x, int *num) {
    // 遍历每一位，从个位开始
    while (x) {
        if (num[x % 10] == 1) {
            return 0;
        }
        num[x % 10] = 1;  // 标记
        x /= 10;
    }
    return 1;
}
// 判断是不是全数字
int func(int a, int b, int c) {
    int num[10] = {1};  // 直接把0当成存过的，避开0的存在
    if (check(a, num) == 0) return 0;
    if (check(b, num) == 0) return 0;
    if (check(c, num) == 0) return 0;
    return 1;
}
int main() {
    int ans = 0, mark[10005] = {0};  // mark 标记数组
    for (int i = 1; i < 100; i++) {
        for (int j = i + 1; 1; j++) {
            int a = digit(i), b = digit(j), c = digit(i * j);
            if (a + b + c == 9) {
                if (func(i, j, i * j)) {
                    if (mark[i * j] == 0) {
                        mark[i * j] = 1;  // 标记
                        ans += i * j;
                    }
                    cout << i << " * " << j << " = " << i * j << endl;
                }
            } else if (a + b + c > 9) {
                break;
            }  // < 9不做处理，直接自增即可
        }
    }
    cout << ans << endl;
    return 0;
}
