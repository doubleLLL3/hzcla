/*************************************************************************
	> File Name: euler30.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 04 Nov 2020 08:13:44 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int num[10];
// 初始化存储个位数五次幂的数组
void init() {
    for (int i = 1; i < 10; i++) {
        int t = i;
        for (int j = 1; j < 5; j++) {
            t *= i;
        }
        num[i] = t;
    }
}
// 满足条件？
int check(int x) {
    int raw = x, t = 0;  // raw 原数、t 五次幂和
    while (x) {
        t += num[x % 10];
        x /= 10;
    }
    return raw == t;
}

int main() {
    init();
    int ans = 0;
    for (int i = 10; i < 1000000; i++) {
        if (check(i)) {
            ans += i;
            cout << i << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
