/*************************************************************************
	> File Name: oj-390.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 03 Nov 2020 02:47:29 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

// lr 右界
int n, m, num[100005], lr;

// 根据长度求可以切出的段数
int func(int len) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += num[i] / len;  // 每段木头可以切出的段数
    }
    return s;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        lr = max(lr, num[i]);  // 确定右界
    }
    int l = 1, r = lr;  // 左右指针指向左右界
    // 11111000000
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int s = func(mid);  // 根据长度mid得到段数
        if (s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;  // 输出l、r都可以
    return 0;
}
