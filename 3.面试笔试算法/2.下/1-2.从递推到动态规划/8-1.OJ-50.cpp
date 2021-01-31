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
// 空间限制：MAX_M无法设到2^32，dp数组过大
int dp[MAX_N + 5][MAX_M + 5];

int main() {
    int n, m;
    cin >> n >> m;
    // 初始化：1个鸡蛋测m层楼
    for (int i = 0; i <= m; i++) dp[1][i] = i;
    // [i] 用i个鸡蛋
    for (int i = 2; i <= n; i++) {
        // [j] 测j层楼
        for (int j = 1; j <= m; j++) {
            dp[i][j] = j;  // 初始化，最多也就测j次 [楼层高度]
            // [k] 从第k层楼扔：碎 or 没碎
            for (int k = 1; k <= j; k++) {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][k - 1], dp[i][j - k]) + 1);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
