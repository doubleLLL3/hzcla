/*************************************************************************
	> File Name: oj-382.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 07:24:44 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
using namespace std;

int main() {
    // n个人，报m的出列，现在报的号是now
    int n, m, now = 1;
    cin >> n >> m;
    queue<int> que;
    // 编号入队
    for (int i = 1; i <= n; i++) {
        que.push(i);
    }
    // 结束条件：队列只剩一人
    while (que.size() != 1) {
        // 报数m的人出队
        if (now == m) {
            que.pop();
            now = 1;  // 重置报数
        } else {
        // 不出队的人排队尾，再出队，顺序要对！
            que.push(que.front());
            now++;
            que.pop();
        }
    }
    cout << que.front() <<endl;
    return 0;
}
