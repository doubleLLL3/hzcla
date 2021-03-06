/*************************************************************************
	> File Name: 7.OJ-49.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 09 Jan 2021 04:05:40 PM CST
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
#define MAX_N 100000
int dp[MAX_N + 5];

int main() {
    int V, n, v, w, s;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w >> s;
        // 两倍两倍的拆，从小到大拆
        for (int k = 1; s; k *= 2) {
            if (k > s) k = s;                               // 对应最后一堆
            s -= k;                                         // 记录剩余件数
            for (int j = V; j >= k * v; j--) {
                dp[j] = max(dp[j], dp[j - k * v] + k * w);  // 加入件数k
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}
