/*************************************************************************
	> File Name: oj-304.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 18 Nov 2020 06:23:28 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
using namespace std;

struct node {
    int x, y, step;
};

int n, m;  // 要反着输入
int dir[8][2] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};
char mmap[200][200];

int main() {
    cin >> m >> n;
    queue <node> que;  // 提前定义队列，待会输入时直接存起点
    // 5 ~ n + 4
    for (int i = 5; i < n + 5; i++) {
        // 注意边界
        for (int j = 5; j < m + 5; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'K') {
                que.push((node){i, j, 0});
            }
        }
    }
    // 开始搜索
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        // 方向数组变了，【8个方向】
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == 'H') {
                cout << temp.step + 1 << endl;
                return 0;          // 走到了，就退出程序了
            }
            if (mmap[x][y] == '.') {
                que.push((node){x, y, temp.step + 1});
                mmap[x][y] = '#';  // 去重
            }
        }
    }
    cout << -1 <<endl;
    return 0;
}
