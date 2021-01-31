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
// 单调队列：q数组模拟，存储的是元素下标，可以索引到对应的值；反过来不行
int q[MAX_N + 5], head = 0, tail = 0;  // 需要头、尾指针 [同队列]
int val[MAX_N + 5];

int main() {
    int n, k;
    cin >> n >> k;
    // 读入数据：数组下标从1开始
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    // 单调递增队列：维护窗口内部最小值
    for (int i = 1; i <= n; i++) {
        while (tail - head && val[q[tail - 1]] > val[i]) --tail;  // 维护单调性 [踢队尾]
        // 上面先判断队列中有值：tail - head否则q[tail - 1]无意义
        q[tail++] = i;                                            // 入队 [新增]
        // 保持窗口大小为k
        if (q[head] <= i - k) head++;                             // 出队 [队首元素]
        // 当窗口大小已经达到要求的k时，输出
        if (i >= k) {
            i > k && cout << " ";                                 // 输出空格
            cout << val[q[head]];                                 // 根据题意而定
        }
    }
    cout << endl;

    head = tail = 0;                                              // 队列清空
    // 单调递减队列：维护最大值 [仅需改变维护单调性的符号方向]
    for (int i = 1; i <= n; i++) {
        while (tail - head && val[q[tail - 1]] < val[i]) --tail; 
        q[tail++] = i;
        if (q[head] <= i - k) head++;
        if (i >= k) {
            i > k && cout << " ";
            cout << val[q[head]];
        }
    }
    cout << endl;
    return 0;
}
