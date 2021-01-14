/*************************************************************************
	> File Name: OJ-44.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 27 Dec 2020 08:19:35 PM CST
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
#define MAX_N 1000000
int arr[MAX_N + 5];
int dp[MAX_N + 5];  // dp代表动态规划问题

int main() {
    int n;
    scanf("%d", &n);
    // 读入数据
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;  // 初始为1，算自己
        for (int j = 0; j < i; j++) {
            if (arr[j] >= arr[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);  // dp[i]代表之前的比较结果
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    cout << dp[n - 1] << endl;
    return 0;
}
