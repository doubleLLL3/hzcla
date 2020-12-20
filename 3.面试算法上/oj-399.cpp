/*************************************************************************
	> File Name: oj-399.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 18 Nov 2020 06:10:05 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
using namespace std;

struct node {
    int x, y, step;  // 需要存步数
};
int n, m, sx, sy;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[505][505];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '2') {
                sx = i, sy = j;  // 【也可以不记录，将起点直接放入搜索队列中】
            }
        }
    }
    queue<node> que;
    que.push((node){sx, sy, 0});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '3') {
                cout << temp.step + 1 << endl;  // 到达终点，记得+1
                return 0;
            }
            if (mmap[x][y] == '.') {
                mmap[x][y] = 0;  // 【去重】
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
