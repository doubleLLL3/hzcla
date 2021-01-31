/*************************************************************************
	> File Name: 6.OJ-48.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 09 Jan 2021 03:50:13 PM CST
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
#define MAX_N 10000
int dp[MAX_N + 5];

int main() {
    int V, n, v, w;
    cin >> n >> V;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        // 与0/1背包相反，此处正向遍历j
        for (int j = v; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[V] << endl;
    return 0;
}
