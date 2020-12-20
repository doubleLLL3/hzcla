/*************************************************************************
	> File Name: oj-81.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 20 Nov 2020 06:22:21 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
using namespace std;

struct node {
    int x, y, step, f;  // f 有无手机
};
int n, m, check[2005][2005];
char mmap[2005][2005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
    cin >> n >> m;
    queue<node> que;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                que.push((node){i, j, 0, 0});  // 起点S
                check[i][j] = 1;               // 标记【1】没手机去过
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            // 排除两种重复情况
            // 只要没手机来过[包括有/无手机都来过]【1、3】 && 现在还是没手机
            if ((check[x][y] & 1) && temp.f == 0) {
                continue;
            }
            // 只要有手机来过[包括有/无手机都来过]【2、3】 && 现在有手机
            if ((check[x][y] & 2) && temp.f == 1) {
                continue;
            }
            // 是否结束？
            if (mmap[x][y] == 'T' && temp.f == 1) {
                cout << temp.step + 1 << endl;
                return 0;
            }
            // 是否可走？. S T
            if (mmap[x][y] == '.' || mmap[x][y] == 'S' || mmap[x][y] == 'T') {
                que.push((node){x, y, temp.step + 1, temp.f});
                check[x][y] += temp.f + 1;     // 用【一个式子】即可去重：+=
                // 四种可能：0→1、0→2、1→3、2→3
            }
            // 到了商店
            if (mmap[x][y] == 'P') {
                que.push((node){x, y, temp.step + 1, 1});  // f = 1
                check[x][y] = 3;               // 商店只需访问一次，直接标记为【3】
            }
        }
    }
    cout << -1 << endl;                        // 出于礼貌
    return 0;
}
