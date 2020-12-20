/*************************************************************************
	> File Name: oj-542.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 22 Nov 2020 03:27:52 PM CST
 ************************************************************************/
#include <queue>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int t, n, h, r, s[1005], scnt, e[1005], arr[1005][1005], check[1005], ball[1005][3];  // 起点需要计数器

int func(int now) {
    if (e[now] == 1) {
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        // 球相通，并且没有走过
        if (arr[now][i] && check[i] == 0) {
            check[i] = 1;
            if (func(i)){
                return 1;
            } // 以i点为起点继续
        }
    }
    return 0;
}

int main() {
    cin >> t;
    while (t--) {
        scnt = 0;  // 起点数量得清0，每组测试样例
        memset(e, 0, sizeof(e));
        memset(arr, 0, sizeof(arr));
        memset(check, 0, sizeof(check));
        cin >> n >> h >> r;
        // 要判断起点、终点、关系
        for (int i = 1; i <= n; i++) {
            cin >> ball[i][0] >> ball[i][1] >> ball[i][2];
            if (ball[i][2] <= r) {
                s[scnt++] = i;
            }
            if (ball[i][2] + r >= h) {
                e[i] = 1;
            }
            for (int j = 1; j < i; j++) {
                int x0 = ball[i][0] - ball[j][0];
                int y0 = ball[i][1] - ball[j][1];
                int z0 = ball[i][2] - ball[j][2];
                if (sqrt(x0 * x0 + y0 * y0 + z0 * z0) <= 2 * r) {
                    arr[i][j] = arr[j][i] = 1;  // 邻接矩阵置1
                }
            }
        }
        int f =  0;
        // scnt 存起点数量
        for (int i = 0; i < scnt; i++) {
            if (check[s[i]] == 0) {
                check[s[i]] = 1;
                if (func(s[i])) {
                    cout << "Yes" << endl;
                    f = 1;
                    break;
                }
            }
        }
        if (f == 0) {
            cout << "No" << endl;
        }
    }
    return 0;
}
