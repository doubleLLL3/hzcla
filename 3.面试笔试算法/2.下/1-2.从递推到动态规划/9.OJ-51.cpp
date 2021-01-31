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
int s[MAX_N + 5], top;          // 单调栈
int c[MAX_N + 5][MAX_N + 5];    // 代表从点[i, j]向上数有多少个连续的白色格子
int f[MAX_N + 5];               // [状态定义] 以某一行的某点为右下角坐标时，能够成的子矩形数量
int n, m;

void read() { 
    cin >> n >> m;
    // 读入数据，并处理
    //  从[1, 1]存，0坐标留给虚拟木板
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            // 如果是白色格子，就根据上一层累加
            if (c[i][j]) c[i][j] += c[i - 1][j];
            // 只需要这个[连续白色高度]信息了 
        }
    }
    return ;
}

long long solve() {
    long long ans = 0;                                           // 答案 [白色子矩形的数量]
    // 一行一行地算
    for (int i = 1; i <= n; i++) {
        c[i][0] = -1;                                            // 初始一个虚拟木板，极小值
        f[0] = 0;                                                // 初始递推状态为0 [子矩形个数]
        top = -1;
        s[++top] = 0;                                            // 压栈，存索引0
        for (int j = 1; j <= m; j++) {
            while (top != -1 && c[i][s[top]] >= c[i][j]) --top;  // 维护单调性 [存最近小于关系]
            f[j] = c[i][j] * (j - s[top]) + f[s[top]];           // 取最近小于值做计算：数量 = 右 + 左
            s[++top] = j;                                        // 入栈
            //f[j] %= MOD_NUM;  // 提前取余[题意]，防止ans + f[j]过大：其实最大达到ans + 1000 * 1000，而 ans 最大100007
            ans += f[j];
            ans %= MOD_NUM;                                      // 题目要求输出对100007取余
        }
    }
    return ans;
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}
