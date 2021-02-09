/*************************************************************************
	> File Name: oj-538.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 20 Nov 2020 07:20:13 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int n, arr[25][25], check[25];

void func(int now) {
    // 第一个输出的一定是1
    if (now != 1) {
        cout << '-';
    }
    // 输出now，并标记
    cout << now;
    check[now] = 1;
    // 再在now所在行遍历
    for (int i = 1; i <= n; i++) {
        // 如果该点没有走过，并且两点存在关系
        if (check[i] == 0 && arr[now][i] == 1) {
            func(i);  // 继续深搜
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    // 遍历所有元素
    for (int i = 1; i <= n; i++) {
        // 没被遍历过，就开始深搜
        if (check[i] == 0) {
            func(i);
        }
    }
    cout << endl;
    return 0;
}
