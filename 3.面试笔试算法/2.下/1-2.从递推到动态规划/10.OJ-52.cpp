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
long long s[MAX_N + 5], f[MAX_N + 5], dp[MAX_N + 5]; // 前缀和、函数值、需求解
int n, M;
int q[MAX_N + 5], head, tail;                        // 单调队列 

// 求斜率：f(s)
double slope(int i, int j) {
    return 1.0 * (f[i] - f[j]) / (s[i] - s[j]);
}

// 读入数据 [直接做出前缀和数组，单个消耗值没有其他用途]
void read() {
    cin >> n >> M;
    // 下标从1开始
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];                            // 存储前缀和
    }
    return ;
}

// 转移：j->i，即j+1~i是打字机一次打印的字符范围
void set_dp(int i, int j) {
    dp[i] = dp[j] + S(s[i] - s[j]) + M;              // 打印前i个字符的最小磨损值
    f[i] = dp[i] + S(s[i]);
    return ;
}

long long solve() {
    head = tail = 0;                                 // 初始化队列
    q[tail++] = 0;                                   // 入队初始索引：0
    // dp从1开始，0位置存初始状态：0
    for (int i = 1; i <= n; i++) {
        // 出队 
        // [至少存在两个点，才有斜率] && [head + 1 比 head 优秀] -> 出队；第二个条件类似滑动窗口的作用
        while (tail - head >= 2 && slope(q[head + 1], q[head]) < 2 * s[i]) ++head;
        // 取队首值 [从区间最小值转移]
        set_dp(i, q[head]); 
        // 入队 [先维护单调性-踢，再入]
        // 不能有弓背型曲线：i、tail - 1、tail - 2，踢出 tail - 1 拱起的
        while (tail - head >= 2 && slope(q[tail - 1], i) < slope(q[tail - 2], q[tail - 1])) --tail;
        q[tail++] = i;
    }
    return dp[n];                                    // 打印n个字符的最小磨损值
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}
