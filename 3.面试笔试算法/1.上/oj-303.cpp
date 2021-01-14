/*************************************************************************
> File Name: oj-303.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 18 Nov 2020 07:20:37 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

struct node {
    int x, y, step;
};

int n, m, num[1005][1005];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
char mmap[1005][1005];  // 输入的地图

int main() {
    memset(num, -1, sizeof(num));
    cin >> n >> m;
    queue<node> que;
    // 从1开始存，【注意】边界是0，地图存的值是字符'0'、'1'
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '1') {
                que.push((node){i, j, 0});  // 多个起点入队
                num[i][j] = 0;              // 答案置0
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            // 未越界【地图值不为0即可】，且没来过【通过答案数组去重】
            if (mmap[x][y] != 0 && num[x][y] == -1) {
                num[x][y] = temp.step + 1;
                que.push((node){x, y, num[x][y]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) {
                cout << " ";
            }
            cout << num[i][j];
        }
        cout << endl;
    }
    return 0;
}
