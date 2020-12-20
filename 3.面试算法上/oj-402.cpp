/*************************************************************************
	> File Name: oj-402.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 20 Nov 2020 07:43:31 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
using namespace std;

struct node {
    int now, step;
};

int n, a, b, num[205], check[205];

int main() {
    cin >> n >> a >> b;
    // 特判
    if (a == b) {
        cout << 0 << endl;
        return 0;
    }
    // 能上下层数数组
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    queue<node> que;
    que.push((node){a, 0});
    check[a] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        // 上的结果 up；下的结果 down
        int up = temp.now + num[temp.now], down = temp.now - num[temp.now];
        // 终点？
        if (up == b || down == b) {
            cout << temp.step + 1 << endl;
            return 0;
        }
        // 没出上界
        if (up <= n && check[up] == 0) {
            que.push((node){up, temp.step + 1});
            check[up] = 1;
        }
        // 没出下界
        if (down >= 1 && check[down] == 0) {
            que.push((node){down, temp.step + 1});
            check[down] = 1;
        }
    }
    cout << -1 <<endl;
    return 0;
}
