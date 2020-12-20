/*************************************************************************
	> File Name: oj-535.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 15 Nov 2020 06:08:37 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int n, m, sx, sy, ans = 1;  // 起点@也算一个黑色瓷砖
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};  // 【方向数组】
char mmap[55][55];  // 【存地图】52*52即可，用来补0

// 不需要返回值，统计全局变量ans即可
void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == '.') {
            ans++;
            mmap[xx][yy] = 0;  // 【去重】不是'.'即可
            func(xx, yy);
        }
    }
    return ;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '@') {
                sx = i, sy = j;  // 记录起点
            }
        }
    }
    func(sx, sy);  // 深搜
    cout << ans << endl;
    return 0;
}
