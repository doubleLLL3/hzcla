/*************************************************************************
	> File Name: 11.OJ-264.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 10 Jan 2021 04:22:59 PM CST
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
int s[MAX_N +5], top;
int h[MAX_N +5], n;
int l[MAX_N +5], r[MAX_N + 5];

void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    return ;
}

int solve() {
    h[0] = h[n + 1] = -1;
    top = -1;
    s[++top] = 0;
    for (int i = 1; i <= n; i++) {
        while (top != -1 && h[s[top]] >= h[i]) --top;
        l[i] = s[top];
        s[++top] = i;
    }
    top = -1;
    s[++top] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (top != -1 && h[s[top]] >= h[i]) --top;
        r[i] = s[top];
        s[++top] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, h[i] * (r[i] - l[i] + 1));
    }
    return ans;

}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}
