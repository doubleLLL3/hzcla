/*************************************************************************
	> File Name: oj-397.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 15 Nov 2020 06:24:54 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int n, m, ans, mmap[105][105];  // 【存地图，int型】
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] != 0) {
            mmap[xx][yy] = 0;  // 【去重】
            func(xx, yy);
        }
    }
    return ;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 找到一个非0值，开始深搜和它一波的僵尸
            if (mmap[i][j] != 0) {
                ans++;           // 波数 + 1
                mmap[i][j] = 0;  // 【去重】
                func(i, j);
            }
        }
    }
    cout << ans <<endl;
    return 0;
}
