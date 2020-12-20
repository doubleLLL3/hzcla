/*************************************************************************
	> File Name: fib.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 28 Oct 2020 08:14:19 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

long long num[50];

// 使用long long以防溢出
long long f(int n) {
    if (n == 1 || n == 2) return 1;
    if (num[n]) return num[n];  // 加入记忆数组
    return num[n] = f(n - 1) + f(n - 2);  // 赋完值后返回num[n]的值
}

int main() {
    // 为了统计速度，来一个循环输出
    for (int i = 1; i <= 40; i++) {
        cout << i << " : " << f(i) << endl;
    }
    return 0;
}
