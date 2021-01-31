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
int dp[MAX_V + 5];

int main() {
    int V, n, v, w;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = V; j >= v; j--) {
            // 隐含：
            // 右边的dp[j]、dp[j - v]对应的【商品件数维度】的索引其实是i - 1，而左边是i
            // 所以逆向遍历j可以保证上面的i - 1；否则正向遍历，dp[j - v](比j小)已经更新成为i了
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[V] << endl;
    return 0;
}
