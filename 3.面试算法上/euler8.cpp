/*************************************************************************
	> File Name: euler8.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 28 Oct 2020 07:21:35 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

char num[1005];
long long ans, zero_cnt, now = 1;

int main() {
    cin >> num;
    for (int i = 0; i < 1000; i++) {
        if (i < 13) {
            now *= num[i] - '0';  // - '0'将字符转成数字
        } else {
            // 主要考虑值是否为0
            // 进来的值
            if (num[i] == '0') {
                zero_cnt++;
            } else {
                now *= num[i] - '0';
            }
            // 出去的值
            if (num[i - 13] == '0') {
                zero_cnt--;
            } else {
                now /= num[i - 13] - '0';
            }
        }
        // zero_cnt：当前窗口内0的数量
        if (!zero_cnt) {
            ans = max(ans, now);
        }
    } 
    cout << ans <<endl; 
}
