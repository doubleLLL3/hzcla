/*************************************************************************
	> File Name: oj-383.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 06:09:43 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
using namespace std;

int main() {
    int x, y, n;
    cin >> x >> y >> n;
    queue<int> qx, qy;  // 两个队列：男队、女队
    // 初始化队列
    for (int i = 1; i <= x; i++) {
        qx.push(i);
    }
    for (int i = 1; i <= y; i++) {
        qy.push(i);
    }
    // 出队、入队
    for (int i = 1; i <= n; i++) {
        cout << qx.front() << " " << qy.front() << endl;
        // 先放队尾，再删除
        qx.push(qx.front());
        qy.push(qy.front());
        qx.pop();
        qy.pop();
    }

    return 0;
    
}
