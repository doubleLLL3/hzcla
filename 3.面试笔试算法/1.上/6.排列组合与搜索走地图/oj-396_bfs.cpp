/*************************************************************************
	> File Name: oj-396_bfs.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 15 Nov 2020 08:46:17 PM CST
 ************************************************************************/
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y;  // 不涉及最小步数，所以不需要step
};
int n, mmap[50][50];
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    queue<node> que;
    que.push((node){0, 0});   // 入队
    mmap[0][0] = 3;           // 不被1包住的0统统改为3
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            // 判断边界、是否已标记[这里标记判断有些多余，因为地图有标记数组的作用]
            if (x < 0 || y < 0 || x > n + 1 || y > n + 1 || mmap[x][y] == 3) {
                continue;
            }
            if (mmap[x][y] == 0) {
                mmap[x][y] = 3;
                que.push((node){x, y});
            }
        }
    }
    // 输出
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= n; j++) {
            if (j != 1) {
                cout << " ";
            }
            if (mmap[i][j] == 3) {
                cout << 0;
            } else if (mmap[i][j] == 0) {
                cout << 2;
            } else {
                cout << 1;
            }
        }
        cout << endl;
    }
    return 0;
}
