/*************************************************************************
	> File Name: 14.OJ-372.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 10 Jan 2021 08:59:46 PM CST
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
#define MAX_N 500000

class Queue {
public:
    Queue(int *arr) : arr(arr) {}                                 // 与数组绑定：用传入的arr初始化arr变量
    void push(int i) {
        while (head - tail && arr[q[tail - 1]] > arr[i]) --tail;  // 维护单调性 [踢]
        q[tail++] = i;                                            // 入队
        return ;
    }
    void pop() { ++head; }                                        // 出队 [实际上用不到]
    int size() { return tail - head; }                            // 👉用大小变化来判断趋势
private:
    int *arr;
    int q[MAX_N + 5], head, tail;
};

int n;
int a[MAX_N + 5], b[MAX_N + 5];
Queue q1(a), q2(b);                                               // 两个单调队列，定义成类

// 读入数据
void read() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];                      // 从0、从1均可
    for (int i = 0; i < n; i++) cin >> b[i];
    return ;
}

int main() {
    read();
    int p;
    for (p = 0; p < n; p++) {
        q1.push(p);
        q2.push(p);
        if (q1.size() != q2.size()) break;                        // 妙！
    }
    cout << p << endl;
    return 0;
}
