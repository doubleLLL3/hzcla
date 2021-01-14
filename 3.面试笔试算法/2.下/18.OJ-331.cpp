/*************************************************************************
	> File Name: 18.OJ-331.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 12 Jan 2021 06:35:30 PM CST
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
#define MAX_N 80000
int c[MAX_N + 5];
#define lowbit(x) (x & -x)
void add(int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return ;
}

int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int n;
int cnt[MAX_N + 5], ind[MAX_N + 5];

void read() {
    cin >> n;
    ind[1] = 0;
    for (int i = 2; i <= n; i++) cin >> cnt[i];
    for (int i = 1; i <= n; i++) {
        add(i ,1, n);
    }
    return ;
}

int binary_search(int n, int x) {
    int head = 1, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (query(mid) < x) head = mid + 1;
        else tail = mid;
    }
    return head;
}

void solve() {
    for (int i = n; i >= 1; --i) {
        ind[i] = binary_search(n, cnt[i] + 1);
        add(ind[i], -1, n);
    }
    return ;
}
void output() {
    for (int i = 1; i <= n; i++) {
        cout << ind[i] << endl;
    }
    return ;
}

int main() {
    read();
    solve();
    output();
    return 0;
}
