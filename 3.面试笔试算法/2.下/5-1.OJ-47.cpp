/*************************************************************************
	> File Name: 5.OJ-47.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 09 Jan 2021 03:00:42 PM CST
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
#define MAX_N 100
#define MAX_V 10000
int v[MAX_N + 5], w[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];

int main() {
    int V, n;
    cin >> V >> n;
    // 存储物品重量、价值
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    // 前i个物品
    for (int i = 1; i <= n; i++) {
        // 背包最大承重为j
        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            // 需要还可以放得下v[i]重量的物品
            if (j >= v[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            //dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << dp[n][V] << endl;
    return 0;
}
