/*************************************************************************
	> File Name: oj-541.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 22 Nov 2020 02:47:59 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, arr[2][20][20], ans[2][100000], cnt[2];  // arr 两个人 二维

void func(int pnum, int now, int cost) {
    if (now == n) {
        ans[pnum][cnt[pnum]++] = cost;
        return ;
    }
    for (int i = now + 1; i <= n; i++) {
        if (arr[pnum][now][i] != 0) {
            func(pnum, i, cost + arr[pnum][now][i]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[0][a][b] = arr[0][b][a] = c;
        arr[1][a][b] = arr[1][b][a] = d;
    }
    func(0, 1, 0);
    func(1, 1, 0);
    int fin = 2100000000;
    for (int i = 0; i < cnt[0]; i++) {
        if (fin < ans[0][i]) {
            continue;
        }
        for (int j = 0; j < cnt[1]; j++) {
            if (ans[0][i] == ans[1][j]) {
                // 一轮只有可能更新一个答案
                fin = ans[0][i];
            }
        }
    }
    if (fin == 2100000000) {
        cout << "IMPOSSIBLE" << endl;
    }else {
        cout << fin << endl;
    }
    return 0;
}
