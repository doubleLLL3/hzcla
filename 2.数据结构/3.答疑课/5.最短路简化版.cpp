/*************************************************************************
	> File Name: 5.最短路简化版.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 24 Jan 2021 06:29:18 PM CST
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

#define MAX_N 1000
int g[MAX_N + 5][MAX_N + 5];
inline void add(int a, int b) {
    g[a][++g[a][0]] = b;
    g[b][++g[b][0]] = a;
    return ;
}
int ans[MAX_N +5];

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        add(a, b);
    }
    queue<int> q;
    ans[c] = 1;
    q.push(c);
    while (!q.empty()) {
        int ind = q.front();
        for (int i = 1; i <= g[ind][0]; i++) {
            int to = g[ind][i];
            if (ans[to]) continue;
            ans[to] = ans[ind] + 1;
            q.push(to);
        }
        q.pop();
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] - 1 << endl;
    }
    return 0;
}
