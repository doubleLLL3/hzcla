/*************************************************************************
	> File Name: 10.OJ-271.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 10 Jan 2021 03:48:22 PM CST
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

#define MAX_N 300000
// q数组存储的是索引，可以取到下标，反过来不行
int q[MAX_N + 5], head = 0, tail = 0;
int val[MAX_N + 5];


int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i <= n; i++) {
        while (tail - head && val[q[tail - 1]] > val[i]) --tail;
        q[tail++] = i;
        if (q[head] <= i - k) head++;
        if (i >= k) {
            i > k && cout << " ";
            cout << val[q[head]];
        }
    }
    cout << endl;
    head = tail = 0;
    for (int i = 1; i <= n; i++) {
        while (tail - head && val[q[tail - 1]] < val[i]) --tail;  // 维护单调性
        q[tail++] = i;  // 入队
        if (q[head] <= i - k) head++;  // 出队
        if (i >= k) {
            i > k && cout << " ";
            cout << val[q[head]];
        }
    }
    cout << endl;
    return 0;
}
