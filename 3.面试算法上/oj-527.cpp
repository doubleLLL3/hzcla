/*************************************************************************
	> File Name: oj-527.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 18 Nov 2020 08:37:45 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
using namespace std;

struct node {
    int x, y, step, d;             // step 时长(步数)；d 剩余能量
};

int n, m, d, mark[105][105][105];  // d 总能量；mark 考虑第三维度【剩余能量】
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[105][105];

int main() {
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    queue<node> que;
    que.push((node){1, 1, 0, d});
    // 对起点来说，任何剩余能量都可以去重
    for (int i = 0;  i <= d; i++) {
        mark[1][1][i] = 1;
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            // 飞
            for (int j = 2; j <= temp.d; j++) {
                int x = temp.x + dir[i][0] * j;
                int y = temp.y + dir[i][1] * j;
                // 越界？
                if (x < 1 || y < 1 || x > n || y > m) {
                    break;         // 这个方向不用飞了
                }
                // 终点？
                if (x == n && y == m) {
                    cout << temp.step + 1 << endl;
                    return 0;
                }
                // 可停留？必须落在没有以该剩余能量停留过[条件2]的平地[条件1]上
                if (mmap[x][y] == 'P' && mark[x][y][temp.d - j] == 0) {
                    que.push((node){x, y, temp.step + 1, temp.d - j});  // 剩余能量要更新
                    mark[x][y][temp.d - j] = 1;
                }
            }
            // 走 [越界可直接通过地图看出]
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x == n && y == m) {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == 'P' && mark[x][y][temp.d] == 0) {
                que.push((node){x, y, temp.step + 1, temp.d});
                mark[x][y][temp.d] = 1;
            }
        }
    }
    cout << "impossible" << endl;

    return 0;
}
