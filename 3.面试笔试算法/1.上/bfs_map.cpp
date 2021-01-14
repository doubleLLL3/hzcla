/*************************************************************************
	> File Name: bfs_map.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 15 Nov 2020 08:29:15 PM CST
 ************************************************************************/
#include <iostream>
#include <queue>
using namespace std;
// 【自定义结构】
struct node {
    int x, y, step;  // step 到这几步
};

int n, m, sx, sy;
int dir[4][2] = {0 , 1, 1, 0, 0, -1, -1, 0};  // 【方向数组】
char mmap[105][105];                          // 【地图】

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            // 需要获取起点，所以写两个循环，而不直接一次输入一行
            if (mmap[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    queue<node> que;              // 【队列】
    que.push((node){sx, sy, 0});  // 起点入队，起始步数为0
    // 广搜
    while (!que.empty()) {
        node temp = que.front();  // 拿队首
        que.pop();                // 拿完后出队
        for (int i = 0; i < 4; i++) {
            // 4个方向
            int x = temp.x + dir[i][0]; 
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == 'T') {
                // 输出答案，要+1，已经是下一步了
                cout << temp.step + 1 << endl; 
                return 0;
            }
            if (mmap[x][y] == '.') {
                mmap[x][y] = 0;   // 【去重】
                que.push((node){x, y, temp.step + 1});  // 入队
            }
        }
    }
    cout << "NO" << endl;         // 走不到终点
    return 0;
}
