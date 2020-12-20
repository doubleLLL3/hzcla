/*************************************************************************
	> File Name: euler15.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 30 Oct 2020 06:58:25 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    // 方法一：动态规划
    long long dp[25][25] = {0};
    // 注意边界i <= 21
    for (int i = 1; i <= 21; i++) {
        for (int j = 1; j <= 21; j++) {
            // 特殊判断第一个点
            if (i == 1 &&j == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[21][21] << endl;
    // 方法二：排列组合通式
    long long ans = 1;
    for (int i = 40, j = 1; i > 20; i--, j++) {
        // 为了避免乘积越界，边乘边除
        ans *= i;
        ans /= j;
        // 一定没有小数，因为先乘后除，总能被整除
    }
    cout << ans << endl;
    return 0;
}
