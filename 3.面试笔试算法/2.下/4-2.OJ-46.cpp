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
vector<int> mark[MAX_N + 5];
int dp[MAX_N + 5];

void expand(string &s, int i, int j) {
    while (s[i] == s[j]) {
        mark[j + 1].push_back(i + 1);
        --i, ++j;
        if (i < 0 || j >= s.size()) break;
    }
    return ;
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; s[i]; i++) {
        expand(s, i, i);  // 奇数
        i + 1 < s.size() && expand(s, i, i + 1);  // 偶数
    }
    for (int i = 1; i <= s.size(); i++) {
        dp[i] = i;
        for (int j = 0; j < mark[i].size(); j++) {
            dp[i] = min(dp[i], dp[mark[i][j] - 1] + 1);
        }
    }
    cout << dp[s.size()] - 1 << endl;
    return 0;
}
