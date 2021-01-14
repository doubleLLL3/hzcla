/*************************************************************************
	> File Name: oj-404.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 15 Nov 2020 07:30:15 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int n, m, mark[3005][3005], ans, sx, sy;
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
char mmap[3005][3005];

void func(int x, int  y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        // 【同时判断边界、是否已标记】
        if (xx < 1 || yy < 1 || xx > n || yy > m || mark[xx][yy] == 1) {
            continue;
        }
        // 如果不相同，即0 → 1或1 → 0
        if (mmap[x][y] != mmap[xx][yy]) {
            ans++;
            mark[xx][yy] = 1;  // 【去重】标记
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];  // 字符类型输入
    }
    cin >> sx >> sy;  // 起点
    ans = 1;          // 答案包含起点
    mark[sx][sy] = 1; // 【去重】标记已走过的点
    func(sx, sy);     // 深搜
    cout << ans <<endl;

    return 0;
}
