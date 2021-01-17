/*************************************************************************
	> File Name: OJ-45.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 27 Dec 2020 08:43:54 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define MAX_N 1000
string s1, s2;                 // 使用c++的string类
int dp[MAX_N + 5][MAX_N + 5];  // 自动初始化为0

int main() {
    cin >> s1 >> s2;
    // 根据状态定义，从dp[1][1]开始，dp[0][0]、dp[0][1]、dp[1][0]默认为0
    for (int i = 1; s1[i - 1]; i++) {
        // 而字符串索引从0开始
        for (int j = 1; s2[j - 1]; j++) {
            // 简化版代码
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // 情况1
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;         // 情况2：该值肯定不小于情况1
            }
            // 原理本对应的代码思路
            /*
            if (s1[i - 1] != s2[j - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            } else {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            */
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    return 0;
}
