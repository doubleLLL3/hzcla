/*************************************************************************
	> File Name: oj-531.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 20 Nov 2020 08:53:03 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
using namespace std;

struct node {
    int status, step;                       // 状态值，步数
};
// num2  每个按钮用二进制表示对应的值 1 2 3 4 ... -> 2 4 8 16 ...
// check 最大可达 2^21
// num   每个按钮被按下后对应弹出的按钮们，其二进制表示对应的值相加的值
int n, num2[25] = {1}, check[2200000], num[25];

// 初始化num2
void init() {
    for (int i = 1; i <= 20; i++) {
        num2[i] = num2[i - 1] * 2;
    }
}

int main() {
    init();
    cin >> n;
    int start = 0;                          // 【起始状态值】
    // 根据输入，求起始状态对应值
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        // 该按钮被按下
        if (t == 1) {
            start |= num2[i];               // 相当于+=操作
        }
    }
    // 根据输入，初始化num
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        for (int j = 1; j<= t; j++) {
            int t2;
            cin >> t2;
            num[i] |= num2[t2];
        }
    }
    // 开始搜索
    queue<node> que;
    que.push((node){start, 0});
    check[start] = 1;                       // 【去重】起点
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        // 【终点】先判断，第3个按钮被按下其他被释放：2 ^ 3 = 8
        // 或者可以在每次转移时判断，可能更快，但要在起点后做一次特判
        if (temp.status == 8) {
            cout << temp.step << endl;
            return 0;
        }
        // 每个按钮都尝试一下
        for (int i = 1; i <= n; i++) {
            // 当按钮没被按下时，【转移】
            if ((temp.status & num2[i]) == 0) {
                int t = temp.status;
                t &= ~num[i];               // 两种状态取按钮交集【关键】
                t |= num2[i];               // 把该按钮也要按下
                if (check[t] == 0) {
                    que.push((node){t, temp.step + 1});
                    check[t] = 1;           // 【去重】
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
