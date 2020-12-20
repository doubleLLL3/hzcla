/*************************************************************************
	> File Name: oj-600.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 04 Nov 2020 08:49:01 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int n, m, t, num[3005][3005];

int main() {
    scanf("%d%d", &n, &m);
    // 从1开始计数
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    scanf("%d", &t);
    int x = n, y = 1;  // 左下角开始找
    while (1) {
        if (num[x][y] == t) {
            printf("%d %d\n", x, y);
            return 0;
        }
        if (num[x][y] > t) {
            x--;
        } else {
            y++;
        }
        // 超出边界
        if (x < 1 || y > m) break;  // 只会往上或往右走
    }
    printf("-1\n");  // 输入输出函数都使用C语言的
    return 0;
}
