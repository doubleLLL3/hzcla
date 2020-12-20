/*************************************************************************
	> File Name: oj-536.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 15 Nov 2020 06:38:26 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int n, m, ans, temp;  // ans 当前最大的区域大小；temp 当前黑色区域的大小
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[105][105];  // 【存地图，char】

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == '1') {
            temp++;           // 区域大小 + 1
            mmap[xx][yy] = 0; // 【去重】
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];  // 一次直接读入一行，因为是字符且不需要记录起点
        // 注意从1开始存、&
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 找1，定位黑色区域
            if (mmap[i][j] == '1') {
                temp = 1;              // 当前黑色区域大小
                mmap[i][j] = 0;        // 【去重】
                func(i, j);
                ans = max(ans, temp);  // 更新【答案】最大值
            }
        }
    }
    cout << ans << endl;
    return 0;
}
