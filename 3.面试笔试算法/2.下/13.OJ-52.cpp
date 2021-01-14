/*************************************************************************
	> File Name: 13.OJ-52.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 10 Jan 2021 08:30:03 PM CST
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
#define S(a) ((a) * (a))
long long s[MAX_N + 5], f[MAX_N + 5], dp[MAX_N + 5];
int n, M;
int q[MAX_N + 5], head, tail;


double slope(int i, int j) {
    return 1.0 * (f[i] - f[j]) / (s[i] - s[j]);
}

void read() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    return ;
}

void set_dp(int i, int j) {
    dp[i] = dp[j] + S(s[i] - s[j]) + M;
    f[i] = dp[i] + S(s[i]);
    return ;
}

long long solve() {
    head = tail = 0;
    q[tail++] = 0;
    for (int i = 1; i <= n; i++) {
        while (tail - head >= 2 && slope(q[head + 1], q[head]) < 2 * s[i]) ++head;
        set_dp(i, q[head]);
        while (tail - head >= 2 && slope(i, q[tail - 1]) < slope(q[tail - 2], q[tail - 1])) --tail;
        q[tail++] = i;
    }
    return dp[n];
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}
