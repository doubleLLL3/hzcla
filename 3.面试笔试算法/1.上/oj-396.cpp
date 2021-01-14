/*************************************************************************
	> File Name: oj-396.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 15 Nov 2020 07:02:05 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int n, mmap[35][35];                         // 【存地图，int】
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1 ,0};  // 【方向数组】

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        // 【注意】判断边界：0 ~ n + 1
        if (xx < 0 || yy < 0 || xx > n + 1 || yy > n + 1) {
            continue;  // 出界直接”下一位“
        }
        if (mmap[xx][yy] == 0) {
            mmap[xx][yy] = 3;  // 【去重，并改成非0、1值】
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n;  // n * n的地图
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    mmap[0][0] = 3;  // 先把起点[0, 0]改为3
    func(0, 0);      // 一次深搜即可
    // 输出
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= n; j++) {
            if (j != 1) {
                cout << ' ';  // 格式要求
            }
            if (mmap[i][j] == 3) {
                cout << 0;
            } else if (mmap[i][j] == 0) {
                cout << 2;
            } else {
                cout << 1;
            }
        }
        cout << endl;
    }
    return 0;
}
