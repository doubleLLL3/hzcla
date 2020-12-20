/*************************************************************************
	> File Name: oj-305.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 18 Nov 2020 07:41:17 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
using namespace std;

struct node {
    int x, y, step;
};

int n, m, sx, sy;
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
char mmap[105][105];

int main() {
    cin >> m >> n >> sy >> sx;
    sx = n - sx + 1;             // 调整sx即可，sy不变
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];      // 一次读一行
    }
    queue<node> que;
    que.push((node){sx, sy, 0});
    mmap[sx][sy] = 0;            // 去重，0表示被入侵了
    int ans = 0;
    while (!que.empty()) {
        node temp = que.front();
        ans = temp.step;         // 最新的步数更新的肯定是最远的，不需要max，不能用++
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '.') {
                mmap[x][y] = 0;  // 去重
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}
