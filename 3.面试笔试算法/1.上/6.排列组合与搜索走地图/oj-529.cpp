/*************************************************************************
	> File Name: oj-529.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 18 Nov 2020 08:01:21 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
using namespace std;

struct node {
    int x, y, step;
};

int n, m;
int dir[8][2] = {
    0, 1, 0, -1, 1, 0, -1, 0,   // 前4个方向，两种方式都能用
    1, 1, -1, 1, -1, -1, 1, -1
};
char mmap[150][150];
// 返回1，代表继续；返回0，代表结束
int func() {
    // 输入数据
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (!a) return 0;
    // 不能改原地图，使用标记数组：终点、走过的点
    int mark[150][150] = {0};  // 局部变量，要初始化
    // 【先从终点标记终点集合】
    mark[a][b] = 1;            // 首先将敌人自己标记为【1】，终点
    for (int i = 0; i < 8; i++) {
        // 死循环，什么时候出去不知道
        for (int j = 1; 1; j++) {
            // 不断延伸，j倍
            int x = a + dir[i][0] * j;
            int y = b + dir[i][1] * j;
            // 判断是否出界或遇到障碍物，可统一为：不是空地
            if (mmap[x][y] != 'O') break;
            mark[x][y] = 1;    // 用【1】标记终点
        }
    }
    // 【特判】自己所在点就能干掉敌人 [下面判断不到]
    if (mark[c][d] == 1) {
        cout << 0 << endl;
        return 1;
    }
    queue<node> que;
    que.push((node){c, d, 0});
    mark[c][d] = 2;            // 用【2】标记走过的点，此标记可以少走一次起点
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            // 到达终点【1】，输出步数，返回1
            if (mark[x][y] == 1) {
                cout << temp.step + 1 << endl;
                return 1;
            }
            // 是否要走：可以走【地图 = 'O'】 && 没走过【标记 != 2】
            if (mmap[x][y] == 'O' && mark[x][y] != 2) {
                que.push((node){x, y, temp.step + 1});
                mark[x][y] = 2;// 标记【2】
            }
        }
    }
    cout << "Impossible!" << endl;
    return 1;                  // 记得return
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    // 对于多组数据，封装成函数，返回值反映是否结束
    while (func()) {}
    return 0;
}
