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
int arr[MAX_N + 5];  // 存储数据
int dp[MAX_N + 5];   // 动规问题中常用dp命名数组

int main() {
    int n;
    scanf("%d", &n);
    // 读入数据
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;   // 算自己，初始为1
        // 看前面的状态
        for (int j = 0; j < i; j++) {
            if (arr[j] >= arr[i]) continue;  // 对偶条件
            dp[i] = max(dp[i], dp[j] + 1);   // dp[i]代表之前最大的dp[j] + 1的值
        }
        ans = max(ans, dp[i]);               // 记录最大的dp[i]的值
    }
    cout << ans << endl;
    return 0;
}
