/*************************************************************************
	> File Name: oj-398.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 18 Nov 2020 06:39:46 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

struct node {
    int x, y, step;
};

int num[405][405], n, m, sx, sy;   // 数组代替地图，可存答案、可去重
int dir[8][2] = {1, 2, -1, 2, -1, -2, 1, -2, 2, 1, 2, -1, -2, 1, -2, -1};

int main() {
    memset(num, -1, sizeof(num));  // 存成-1，方便输出答案：达不到的点和起点 <string.h>
    cin >> n >> m >> sx >> sy;
    num[sx][sy] = 0;               // 起点答案就是0
    queue<node> que;
    que.push((node){sx, sy, 0});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0 ;i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            // 判断边界，以及之前是否来过
            if (x < 1 || y < 1 || x > n || y > m || num[x][y] != -1) {
                continue;
            }
            num[x][y] = temp.step + 1;          // 【去重】第一次到达的step + 1就是答案
            que.push((node){x, y, num[x][y]});  // 入队
        }
    }
    // 1 ~ n、1 ~ m
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) {
                cout << " ";
            }
            cout << num[i][j];
        }
        cout << endl;
    }
    return 0;
}
