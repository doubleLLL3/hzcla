/*************************************************************************
	> File Name: oj-393.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 03 Nov 2020 03:07:17 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
double num[10005], tr;

// 长度→可分段数
int func(double len) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += num[i] / len;  // double/double给到int里，直接去小数点取整
    }
    return s;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        tr = max(tr, num[i]);  // 更新最大值
    }
    double l = 0, r = tr;
    // 111111000000型
    while (r - l > 0.00001) {
        double mid = (l + r) / 2;
        int s = func(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid;
        }
    }
    // 两种方式：直接舍掉小数点后两位后的输出
    // 方式一
    printf("%.2f\n", (int)(l * 100) / 100.0);
    // 方式二
    //printf("%.2f\n", l - 0.005);
    return 0;
}
