/*************************************************************************
	> File Name: 8.灌溉.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 24 Jan 2021 08:20:50 PM CST
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
struct Edge {
    int v, u, c;
};

vector<Edge> e;

bool cmp(const Edge &a, const Edge &b) {
    return a.c < b.c;
}

int fa[MAX_N + 5];
int get(int x) {
    return fa[x] = (x - fa[x] ? get(fa[x]) : x);
}
void merge(int a, int b) {
    fa[get(a)] = get(b);
}
void init(int n) {
    for (int i = 0; i <= n; i++) fa[i] = i;
}


int main() {
    int n;
    cin >> n;
    for (int i = 1, a; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a;
            if (i < j) e.push_back({i, j, a});
        }
    }
    sort(e.begin(), e.end(), cmp);
    init(n);
    int ans = 0;
    for (int i = 0; i < e.size(); i++) {
        int v = e[i].v, u = e[i].u, c = e[i].c;
        if (get(v) == get(u)) continue;
        merge(v, u);
        ans += c;
    }
    cout << ans << endl;

    return 0;
}
