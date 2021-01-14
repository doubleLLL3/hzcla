/*************************************************************************
	> File Name: 590.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
    > Created Time: Sat 28 Nov 2020 06:15:35 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, num[1005][1005], utd[1005][1005], dtu[1005][1005], ans[1005][1005], mmax[1005][2];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            utd[i][j] = max(utd[i - 1][j - 1], utd[i - 1][j]) + num[i][j];
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            dtu[i][j] = max(dtu[i + 1][j + 1], dtu[i + 1][j]) + num[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = utd[i][j] + dtu[i][j] - num[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        int m2 = 0, m1 = 0, cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (ans[i][j] > m1) {
                m2 = m1;
                m1 = ans[i][j];
                cnt = j;
            } else if (ans[i][j] > m2) {
                m2 = ans[i][j];
            }
        }
        mmax[i][0] = cnt;
        mmax[i][1] = m2;
    }
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
