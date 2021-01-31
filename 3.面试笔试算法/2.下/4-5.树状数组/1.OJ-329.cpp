/*************************************************************************
	> File Name: 16.OJ-329.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 12 Jan 2021 10:47:11 AM CST
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
int c[MAX_N + 5];           // 树状数组：维护差分数组的前缀和
#define lowbit(x) (x & -x)  // lowbit方法

// 2、单点修改 n：原序列长度 [用来初始化和区间修改]
void add(int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);     // 向上更新
    }
    return ;
}

// 3、求差分数组的前缀和 [用来单点查询]
int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);     // 向前更新
    }
    return sum;
}

int main() {
    int n, pre = 0, a, m;   // pre：记录前一个元素，用来求差分
    cin >> n;
    // 1、存储差分数组 [从1开始]
    for (int i = 1; i <= n; i++) {
        cin >> a;
        add(i, a - pre, n); // 单点修改
        pre = a;            // 记得更新前一个元素pre
    }
    cin >> m;
    char s;
    int l, r, x;
    for (int i = 0; i < m; i++) {
        cin >> s;
        switch (s) {
            // 区间修改
            case 'C': {
                cin >> l >> r >> x;
                // 转换为单点修改 差分数组上两个端点l、r + 1 [也是从1开始]
                add(l, x, n); 
                add(r + 1, -x, n);
            } break;
            // 单点查询
            case 'Q': {
                cin >> x;
                cout << query(x) << endl;
            } break;
        }   
    }
    return 0;
}
