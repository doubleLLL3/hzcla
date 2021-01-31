/*************************************************************************
	> File Name: 8.OJ-50.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 09 Jan 2021 04:47:07 PM CST
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
#define MAX_N 32
#define MAX_M 1000000
int dp[MAX_N + 5][MAX_M + 5];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= m; i++) dp[1][i] = i;
    // 用i个鸡蛋
    for (int i = 2; i <= n; i++) {
        int k = 1; 
        // 测j层楼
        for (int j = 1; j <= m; j++) {
            // 判断测j层楼时，【k2 = k1 + 1】 or 【k2 = k1】？
            // 如果将 k2 = k + 1 代入 dp[i - 1][k2 - 1] <= dp[i][j - k2] 成立
            if (dp[i - 1][k] <= dp[i][j - k - 1]) ++k;
            // 等价于下面这一句：区别在<=换成了<，考虑的就是 k 而不是 k + 1
            //if (dp[i - 1][k - 1] < dp[i][j - k]) ++k;
            // 此时已经找到最优的k
            dp[i][j] = max(dp[i - 1][k - 1], dp[i][j - k]) + 1;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
