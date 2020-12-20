/*************************************************************************
	> File Name: oj-599.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 04 Nov 2020 08:35:35 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int n, t, num[1000005];
// 双指针法
int main() {
    scanf("%d%d", &n, &t);  // 避免超时
    for (int i = 0; i < n; i++) {
        scanf("%d", num + i);
    }
    int l = 0, r = n - 1;  // 定义左右指针
    while (l < r) {
        if (num[l] + num[r] == t) {
            cout << l << " " << r << endl;
            return 0;
        }
        // 数小或数大了
        if (num[l] + num[r] < t) {
            l++;
        } else {
            r--;
        }
    }
    cout << -1 << endl;  // 如果没找到
    return 0;
}
