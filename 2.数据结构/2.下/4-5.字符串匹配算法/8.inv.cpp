/*************************************************************************
	> File Name: 8.inv.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 13 Jan 2021 06:54:56 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int inv[7] = {0};

// 求 1~6 模7的逆元
int main() {
    inv[1] = 1;  // 初始化：1的逆元是1
    for (int i = 2; i < 7; i++) {
        // 求逆元
        // inv[i] = -k * inv[r] % p
        inv[i] = -(7 / i) * inv[7 % i] % 7;
        // 转换成正数
        inv[i] = (inv[i] + 7) % 7;
        cout << i << " : " << inv[i] << endl;
    }
    return 0;
}
