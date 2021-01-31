/*************************************************************************
	> File Name: 8-3.OJ-50.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 09 Jan 2021 08:01:33 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define MAX_N 32
#define MAX_X 70000
long long f[2][MAX_X + 5];

int solve(int n, int m) {
    if (n == 1) return m;
    // 初始化，只有一个鸡蛋，可以扔多少次就对应最多测多少层楼
    for (int i = 1; i <= MAX_X; i++) f[1][i] = i;
    for (int i = 2; i <= n; i++) {
        for (int x = 1; x <= MAX_X; x++) {
            // 上 + 下 + 1
            f[i % 2][x] = f[i % 2][x - 1] + f[(i - 1) % 2][x - 1] + 1;
        }
    }
    int x = 1;
    while (f[n % 2][x] < m) x++;  // 找第一个使>=楼层数m，对应的方法数x
    return x;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
    return 0;
}

