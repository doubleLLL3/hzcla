/*************************************************************************
	> File Name: oj-389.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 03 Nov 2020 02:57:54 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

// num 工位编号数组；tr 上界
int n, m, num[100005], tr;

// 临时距离d→可安排人数s
int func(int d) {
    int s = 1, last = num[0];  // last 上一个安排的人的位置
    for (int i = 1; i < n; i++) {
        // 能否坐人
        if (num[i] - last >= d) {
            s++;
            last = num[i];
        }
    }
    return s;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        tr = max(tr, num[i]);  // 为了方便，直接求最大
    }
    // 默认从小到大排序
    sort(num, num + n);
    int l = 1, r = tr;
    // 11111000000
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int s = func(mid);  // 根据答案得到判断依据
        if (s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}
