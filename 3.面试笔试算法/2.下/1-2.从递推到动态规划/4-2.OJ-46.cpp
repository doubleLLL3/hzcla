/*************************************************************************
	> File Name: 4-2.OJ-46.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 09 Jan 2021 09:31:34 PM CST
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
vector<int> mark[MAX_N + 5];                      // 相当于二维数组！
int dp[MAX_N + 5];

// 向两边扩展找回文串
//  将以j + 1结尾的回文串的起始坐标i + 1存储在mark[j + 1]中，mark[j + 1]是一个vector
int expand(string &s, int i, int j) {
    while (s[i] == s[j]) {
        mark[j + 1].push_back(i + 1);             // mark数组从1开始，与dp对应
        --i, ++j;
        if (i < 0 || j >= s.size()) break;        // 停止条件
    }
    return 1;                                     // 有返回值是为了下面的短路原则
}

int main() {
    string s;
    cin >> s;
    // 预处理
    // 以s[i]为中心，扩展找回文串
    for (int i = 0; s[i]; i++) {
        expand(s, i, i);                          // 奇数个字符的
        i + 1 < s.size() && expand(s, i, i + 1);  // 偶数个字符的 [注意前提：i + 1]
    }
    // 此时mark数组每一位已经存储了以该位结尾的【所有】回文串的下标值，vector

    // dp、mark数组下标从1开始，字符串下标从0开始
    for (int i = 1; i <= s.size(); i++) {
        dp[i] = i;                                // 初始化，i个字符最多分i段
        // 遍历mark数组
        for (int j = 0; j < mark[i].size(); j++) {
            // mark[i][j]为回文串起始坐标，所以要dp索引里要-1，回文串算一段
            dp[i] = min(dp[i], dp[mark[i][j] - 1] + 1); 
        }
    }
    cout << dp[s.size()] - 1 << endl;
    return 0;
}
