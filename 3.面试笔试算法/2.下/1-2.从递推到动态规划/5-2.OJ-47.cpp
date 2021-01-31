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
int dp[2][MAX_V + 5];

int main() {
    int V, n;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            // 使用模运算，实现滚动数组
            dp[i % 2][j] = dp[(i - 1) % 2][j];
            if (j >= v[i]) 
                dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j - v[i]] + w[i]);
        }
    }
    cout << dp[n % 2][V] << endl;
    return 0;
}
