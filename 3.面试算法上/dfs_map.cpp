/*************************************************************************
	> File Name: dfs_map.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 15 Nov 2020 04:26:30 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
int n, m, sx, sy;
char mmap[105][105];  // 【存地图】mmap，避免和map冲突
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};  // 【方向数组】横纵合在一起写，这里顺序不重要

int func(int x, int y) {
    // 4个方向
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == 'T') {
            return 1;
        }
        // 先判断能不能走
        if (mmap[xx][yy] == '.') {
            mmap[xx][yy] = '#';  // 【去重】这里必要，标记走过的值
            // 【递归】
            if (func(xx, yy) == 1) {
                return 1;
            }
        }
    }
    return 0;  // 都走过之后还没搜到，就返回0
}

int main() {
    cin >> n >> m;  // 图的大小：n 行数，m 列数
    // 【补0】从1开始存
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                sx = i, sy = j;  // 记录【起点】的坐标
            }
        }
    }
    // 设置一个返回值
    if (func(sx, sy) == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
