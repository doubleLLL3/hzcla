/*************************************************************************
	> File Name: oj-386.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 03 Nov 2020 02:04:19 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int cnt, num;
};  // 一定记得这个分号！

int n, m;
node wm[100005];

bool cmp(const node &a, const node &b) {
    return a.num < b.num;  // 从小到大排序
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> wm[i].num;
        wm[i].cnt = i + 1;  // 编号从1开始
    }
    sort(wm, wm + n, cmp);  // 对于自定义结构需自定义cmp
    // 二分查找
    for (int i = 0; i < m; i++) {
        // t 要查找的值，f 返回的编号， l、r 左右边界
        int t, f = 0, l = 0, r = n - 1;
        cin >> t;
        while (l <= r) {
            int mid = ((long long)l + r) / 2;  // 要考虑溢出
            if (t == wm[mid].num) {
                f = wm[mid].cnt;  // 不是现在的位置mid
                break;
            }
            if (t < wm[mid].num) {
                r = mid - 1;  // mid肯定不是了，-1
            } else {
                l = mid + 1;
            }
        }
        cout << f <<endl;
    }
    return 0;
}
