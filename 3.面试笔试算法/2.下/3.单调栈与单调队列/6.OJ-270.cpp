/*************************************************************************
	> File Name: 15.OJ-270.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 10 Jan 2021 09:14:09 PM CST
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
#include <climits>
using namespace std;
#define MAX_N 300000
int s[MAX_N + 5], n, m;                     // s：前缀和数组
int q[MAX_N + 5], head, tail;               // 单调队列

void read() {
    cin >> n >> m;
    // 凡是涉及前缀和的数组，下标从1开始，而s[0]=0
    for (int i = 1; i<= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    return ;
}

int solve() {
    int ans = INT_MIN;                      // <climits>
    head = tail = 0;                        // 先将队列清空
    q[tail++] = 0;                          // 初始先压入s[0]
    for (int i = 1; i <= n; i++) {
        if (i - q[head] > m) head++;        // 出队 [已超出窗口] ❗ i - q[head] = m时，窗口大小为M
        ans = max(ans, s[i] - s[q[head]]);  // 取值
        while (tail - head && s[q[tail - 1]] > s[i]) --tail;  // 维护单调性 [最小值]
        q[tail++] = i;                      // 入队
    }
    return ans;
}
int main() {
    read();
    cout << solve() << endl;
    return 0;
}
