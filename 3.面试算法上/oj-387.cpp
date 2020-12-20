/*************************************************************************
	> File Name: oj-387.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 03 Nov 2020 02:13:54 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int cnt, num;
};
bool cmp(const node &a, const node &b) {
    return a.num < b.num;  // 从小到大排序
}
int n, m;
node wm[100005];

int main() {
    cin >> n >>m;
    for (int i = 0; i < n; i++) {
        cin >> wm[i].num;
        wm[i].cnt = i + 1;  // 编号从1开始
    }
    // 一个虚拟的编号为0的瓜，对应输出0的情况
    // 或者特判，记录瓜堆里最大瓜数
    wm[n].cnt = 0;
    wm[n].num = 2100000000;  // 超过最大瓜数10亿即可
    sort(wm, wm + n + 1, cmp);
    for (int i = 0; i < m; i++) {
        int t, l = 0, r = n;
        cin >> t;
        // 000011111的情况，找第一个1
        while (l != r) {
            // l != r 或者 l < r；而不是<=，越不过去
            int mid = (l + r) / 2;
            if (wm[mid].num >= t) {
                // 这是要满足的条件，所以为mid
                r = mid;
            } else {
                // 这是一定不满足的条件，所以为mid + 1
                l = mid + 1;
            }
        }
        cout << wm[l].cnt << endl;
    }
    return 0;
}
