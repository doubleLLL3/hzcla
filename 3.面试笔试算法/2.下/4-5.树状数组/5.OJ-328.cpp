/*************************************************************************
	> File Name: 20.OJ-328.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 12 Jan 2021 07:28:08 PM CST
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
#define MAX_N 200000
long long c[MAX_N + 5];                 // 树状数组 [标记已经出现的元素i为1]
#define lowbit(x) (x & -x)

// 单点修改
void add(long long i, long long x, long long n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return ;
}

// 前缀和查询
long long query(long long i) {
    long long sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

long long n;
long long val[MAX_N + 5];               // 读入值 [1 ~ n]

void read() {
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> val[i];
        // 树状数组初始为0，表示还没有访问过，所以不用手动初始化
    }
    return ;
}

void solve(long long &x, long long &y) {
    // x、y传引用
    x = y = 0;                          // 初始化总数量
    for (long long i = 1; i <= n; i++) {
        long long a1 = query(val[i]);   // [已记录] < val[i]的数量 [往前看]
        long long a2 = val[i] - a1 - 1; // [未记录] < val[i]的数量 [换算1]
        long long b1 = i - a1 - 1;      // [已记录] > val[i]的数量 [换算2]
        long long b2 = n - val[i] - b1; // [未记录] > val[i]的数量 [换算3]
        x += b1 * b2;
        y += a1 * a2;
        add(val[i], 1, n);              // 标记val[i]已记录过
    }
    return ;
}

int main() {
    read();
    long long a, b;                     // 两个图腾的数量 a：V，b：^
    solve(a, b);
    cout << a << " " << b << endl;
    return 0;
}
