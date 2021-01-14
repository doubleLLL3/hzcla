/*************************************************************************
	> File Name: euler36.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 04 Nov 2020 07:43:54 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
// 按照n进制翻转
int check(int x, int n) {
    int raw = x, t = 0;  // raw 原数字 t 翻转后的数字
    // 翻转
    while (x) {
        t = t * n + x % n;
        x /= n;
    }
    return t == raw; 
}

int main() {
    int ans = 0;
    for (int i = 1; i < 1000000; i++) {
        if (check(i, 10) && check(i, 2)) {
            ans += i;
            cout << i <<endl;
        }
    }
    cout << ans << endl;
    return 0;
}
