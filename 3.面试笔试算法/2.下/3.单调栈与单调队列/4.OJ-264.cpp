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
long long s[MAX_N + 5], top;                           // 单调递增栈
long long h[MAX_N + 5], n;                             // 读入的木板高度
long long l[MAX_N + 5], r[MAX_N + 5];                  // 左边/右边最近小于值数组：l/r

void read() {
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) scanf("%lld", h + i);    // 下标从1开始，留0初始化边界
    return ;
}

long long solve() {
    h[0] = h[n + 1] = -1;                              // 将h数组两端初始化：高度极小的木板
    top = -1;
    s[++top] = 0;                                      // s[0]初始化为0，代表h的【索引】
    // 维护单调递增栈 [严格递增，要真正小于的木板高度]
    for (long long i = 1; i <= n; i++) {
        while (top != -1 && h[s[top]] >= h[i]) --top;  // 维护单调性 [出栈]
        l[i] = s[top];                                 // 存储左边最近小于值
        s[++top] = i;                                  // 入栈
    }
    // 栈清空
    top = -1;
    // 维护单调递增栈 [从右向左读]
    s[++top] = n + 1;                                  // 边界
    for (long long i = n; i >= 1; i--) {
        while (top != -1 && h[s[top]] >= h[i]) --top;
        r[i] = s[top];
        s[++top] = i;
    }

    /*
     * 输出左/右最近小于值
    cout << "------------------------------------"  << endl;
    cout << "木板索引\t左最近小\t右最近小" << endl;
    for (long long i = 1; i <= n; i++) {
        cout << i << "\t\t" << l[i] << "\t\t" << r[i] << endl;
    }
    cout << "------------------------------------"  << endl;
    */

    // 遍历每块木板，计算最大面积
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        ans = max(ans, h[i] * (r[i] - l[i] - 1));
    }
    return ans;
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}
