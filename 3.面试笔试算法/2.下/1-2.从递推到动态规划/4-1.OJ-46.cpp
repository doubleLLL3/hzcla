/*************************************************************************
	> File Name: 4.OJ-46.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 09 Jan 2021 02:31:26 PM CST
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
#define MAX_N 500000
int dp[MAX_N + 5];

// 判断字符串的第 i ~ j 位是不是一个回文串
bool is_palindrome(string &s, int i, int j) {
    while (i < j) {
        if (s[i++] - s[j--]) return false;  // ++、--操作在比较后进行
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    dp[0] = 0;                              // 代表取前0位字符串，相当于什么都不取
    for (int i = 1; i <= s.size(); i++) {
        dp[i] = dp[i - 1] + 1;              // 初始化，直接将当前字符看做一个回文
        for (int j = 0; j < i; j++) {
            // 字符串索引从0开始，所以对应 j ~ i-1
            if (is_palindrome(s, j, i - 1)) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    cout << dp[s.size()] - 1 << endl;       // 刀数 = 段数 - 1
    return 0;
}
