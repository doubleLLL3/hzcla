/*************************************************************************
	> File Name: 12.OJ-51.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 10 Jan 2021 07:09:23 PM CST
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
#define MOD_NUM 100007
int s[MAX_N + 5], top;
int c[MAX_N + 5][MAX_N + 5];
int f[MAX_N + 5];
int n, m;

void read() { 
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if (c[i][j]) c[i][j] += c[i - 1][j];
        }
    }
    return ;
}

long long solve() {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        top = -1;
        s[++top] = 0;
        c[i][0] = -1;
        f[0] = 0;
        for (int j = 1; j <= m; j++) {
            while (top != -1 && c[i][top] >= c[i][j]) --top;  // 踢掉
            f[j] = c[i][j] * (j - s[top]) + f[s[top]];
            f[j] %= MOD_NUM;
            s[++top] = j;
            ans += f[j];
            ans %= MOD_NUM;
        }
    }
    return ans;
}

int main() {
    read();
    cout << solve() << endl;

    return 0;
}
