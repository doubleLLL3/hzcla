/*************************************************************************
	> File Name: euler33.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 04 Nov 2020 07:19:45 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
// 是否满足条件
int check(int a, int b) {
    int x1 = a / 10, x2 = a % 10;  // 分子的十位和个位
    int y1 = b / 10, y2 = b % 10;  // 分母的
    if (!x1 || !x2 || !y1 || !y2) return 0;  // 不能为0
    // 十字相乘！
    if (x1 == y1 && a * y2 == b * x2) return 1;
    if (x1 == y2 && a * y1 == b * x2) return 1;
    if (x2 == y1 && a * y2 == b * x1) return 1;
    if (x2 == y2 && a * y1 == b * x1) return 1;
    return 0;
}
int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}
int main() {
    int a = 1, b = 1;  // 答案的分子、分母
    for (int i = 11; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            if (check(i, j)) {
                a *= i;
                b *= j;
                cout << i << " / " << j <<endl;
            }
        }
    }
    int c = gcd(a, b);  // 求公约数
    cout << b / c << endl;  // 除以公约数即为解

    return 0;
}
