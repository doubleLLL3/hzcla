/*************************************************************************
	> File Name: oj-401.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 18 Nov 2020 06:56:56 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

struct node {
    int x, y, step;
};

int n, num[505][505];              // n组数据
int dir[12][2] = {
    1, 2, 1, -2, -1, 2, -1, -2,    // 马1
    2, 1, 2, -1, -2, 1, -2, -1,    // 马2
    2, 2, 2, -2, -2, 2, -2, -2     // 象
};

int main() {
    memset(num, -1, sizeof(num));  // 初始化为-1
    queue<node> que;
    que.push((node){1, 1, 0});     // 起点入队
    num[1][1] = 0;                 // 答案数组也初始化为0
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        // 12个方向
        for (int i = 0; i < 12; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            // 判断边界、走过与否
            if (x < 1 || y < 1 || x > 500 || y > 500 || num[x][y] != -1) {
                continue;
            }
            // 存答案、入队
            num[x][y] = temp.step + 1;
            que.push((node){x, y, temp.step + 1});
        }
    }
    // 输入、输出
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << num[a][b] << endl;
    }
    return 0;
}
