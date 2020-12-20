/*************************************************************************
	> File Name: oj-590.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 30 Oct 2020 08:26:15 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int n, m, num[1005][1005], utd[1005][1005], dtu[1005][1005], ans[1005][1005], mmax[1005][2];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &num[i][j]);  // 这样输入可以加速
        }
    }
    // 记录自上而下路径和
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            utd[i][j] = max(utd[i - 1][j - 1], utd[i - 1][j]) + num[i][j];
        }
    }
    // 记录自下而上路径和
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            dtu[i][j] = max(dtu[i + 1][j + 1], dtu[i + 1][j]) + num[i][j];
        }
    }
    // 记录每个点对应的最大路径和
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = utd[i][j] + dtu[i][j] - num[i][j];
        }
    }
    // 记录每一行对应的最大路径和与次大路径和
    for (int i = 1; i <= n; i++) {
        // m2 次大值 m1 最大值 cnt 最大值的坐标
        int m2 = 0, m1 = 0, cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (ans[i][j] > m1) {
                m2 = m1;  // 更新次大值为当前最大值
                m1 = ans[i][j];  // 更新最大值
                cnt = j;  // 记录最大值坐标
            } else if (ans[i][j] > m2) {
                // 别少了次大值更新的另一种情况
                m2 = ans[i][j];
            }
        }
        // 记录最大值坐标！和次大值！（亮点）
        mmax[i][0] = cnt;
        mmax[i][1] = m2;
    }
    // 遍历输入的ban点
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 1 && b == 1) {
            printf("-1\n");
        } else if (mmax[a][0] == b) {
            printf("%d\n", mmax[a][1]);
        } else {
            printf("%d\n", dtu[1][1]);
        }
    }
    return 0;
}
