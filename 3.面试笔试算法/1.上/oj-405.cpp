/*************************************************************************
	> File Name: oj-405.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 15 Nov 2020 07:47:50 PM CST
 ************************************************************************/
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y;  // 记录坐标
};
queue<node> que;
int n, m, k, ans[3005][3005], temp;  // temp 有几个互相连通的点；ans 存答案&打标记
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[3005][3005];
void check() {
    // 其实一开始的que.size() = temp 
    while (!que.empty()) {
        node t = que.front();
        que.pop();
        ans[t.x][t.y] = temp;  // 此时，temp就是该点对应的答案
    }
}
void func(int x, int y) {
    que.push((node){x, y});  // 【重要】放入队列，便于后续存答案
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        // 【判断边界、标记与否、求过答案与否】
        if (xx < 1 || yy < 1 || xx > n || yy > m || ans[xx][yy] != 0) {
            continue;
        }
        // 能走的条件
        if (mmap[x][y] != mmap[xx][yy]) {
            ans[xx][yy] = 1;  // 【标记】
            temp++;
            func(xx, yy);
        }
    }
}
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];  // 一次读一行字符
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 如果之前没有求过答案，作为起点搜索
            if (ans[i][j] == 0) {
                temp = 1;
                ans[i][j] = 1;  // 先【标记】已经占了，后面要更新答案
                func(i, j);     // 深搜
                check();        // 【更新】队列里点对应的答案：能移动的格子数
            }
        }
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        cout << ans[a][b] << endl;  // 直接输出求好的答案
    }
    return 0;
}
