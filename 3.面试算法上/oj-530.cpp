/*************************************************************************
	> File Name: oj-530.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 20 Nov 2020 08:14:42 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
#include <string>
using namespace std;

// 方向不重要？
struct node {
    int x, y;  // 只需要坐标，不需要步数
};

int n, m, cnt; // cnt 记录了几个方向
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};  // 待会方向需对应，↑↓←→，北南西东
char mmap[55][55];

int main() {
    queue<node> que;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '*') {
                que.push((node){i, j});
                mmap[i][j] = '.';            // 起点直接改为.，之后可以经过
            }
        }
    }
    cin >> cnt;                              // 方向数量
    // 搜每次的方向
    while (cnt--) {
        string str;                          // 临时字符串存方向
        cin >> str;
        // 【dir_num】 方向字符串对应的数字
        // 【check】   去重数组，为局部变量，每层都是新的
        // 【qsize】   每层的点数，先记录好，后面添加的元素是下一层的
        int dir_num, check[55][55] = {0}, qsize = que.size();
        if (str == "NORTH") {
            dir_num = 0;
        } else if (str == "SOUTH") {
            dir_num = 1;
        } else if (str == "WEST") {
            dir_num = 2;
        } else {
            dir_num = 3;
        }
        // [上面可以定义成pair或map]
        // 搜每层
        while (qsize--) {
            node temp = que.front();
            que.pop();
            // 死循环，直到走不了
            for (int i = 1; 1; i++) {
                int x = temp.x + dir[dir_num][0] * i;
                int y = temp.y + dir[dir_num][1] * i;
                if (mmap[x][y] != '.') {
                    break;
                }
                if (check[x][y] == 0) {
                    que.push((node){x, y});
                    check[x][y] = 1;         // 【去重】
                }
            }
        }
    }
    // 队列里最终存的就是答案：可能出现的位置
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        mmap[temp.x][temp.y] = '*';          // 更改地图里对应位置的符号
    }
    for (int i = 1; i <= n; i++) {
        cout << &mmap[i][1] << endl;
    }
    return 0;
}
