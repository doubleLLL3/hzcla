/*************************************************************************
	> File Name: oj-391.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 03 Nov 2020 03:47:39 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

// tl、tr 左右界
long long n, m, num[100005], tl, tr;
// 最大和→段数
long long func(long long x) {
    long long cnt = 0, now = 0;  // cnt 段数，now 当前和
    // 分为三种情况，需要好好琢磨！！
    for (int i = 0; i < n; i++) {
        if (now + num[i] == x) {
            // 正好是一段
            cnt++;
            now = 0;
        } else if (now + num[i] > x) {
            // 超出最大和，回一位
            cnt++;
            now = num[i];  // 提前记录好前一段的值
        } else {
            // 小于，继续累加
            now += num[i];
        }
    }
    // 如果now里有值，说明还剩一段没加，对应上面后2种情况
    if (now) {
        cnt++;
    }
    return cnt;
}
long long bin_search() {
    long long l = tl, r = tr;  // 可以不用定义，直接用
    while (l != r) {
        long long mid = (l + r) / 2;
        long long s = func(mid);  // 其实用int就行
        if (s <= m) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        tl = max(tl, num[i]);
        tr += num[i];
    }
    cout << bin_search() << endl;

    return 0;
}
