/*************************************************************************
	> File Name: 14.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 27 Nov 2020 11:00:05 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int num[1000000];
// 求长度
int func(long long n) {
    if (n == 1) return 1;
    if (n < 1000000 && num[n]) return num[n];
    int t;
    if (n % 2 == 0) {
        t = func(n / 2) + 1;
    } else {
        t = func(3 * n + 1) + 1;
    }
    if (n < 1000000) {
        num[n] = t;
    }
    return t;
}

int main() {
    int ans = 1;
    int max_len = 1;
    for (int i = 2; i <= 1000000; i++) {
        int len = func(i);
        if (max_len < len) {
            ans = i;
            max_len = len;
        }
    }
    cout << ans << endl;
    return 0;
}
