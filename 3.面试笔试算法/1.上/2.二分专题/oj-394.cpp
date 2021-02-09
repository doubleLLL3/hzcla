/*************************************************************************
	> File Name: oj-394.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 03 Nov 2020 03:59:20 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
// ll 起点和终点的距离、上界；tl 下界
int ll, n ,m, num[50005], tl;
int func(int d) {
    int cnt = 0, last = 0;  // last 上一个石头的编号
    for (int i = 1; i <= n + 1; i++) {
        // 遍历到了终点，但不会移走终点的石头，移走前面一块是同样的效果
        if (num[i] - last < d) {
            cnt++;  // 需要移走此块石头
        } else {
            last = num[i];  // 不需要移走
        }
    }
    return cnt;
}
int bin_search() {
    int l = tl, r = ll;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int s = func(mid);
        if (s <= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return r;
}
int main() {
    cin >> ll >> n >> m;
    // 从1开始，起点0在num初始化时已存好
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        if (i == 1) {
            tl = num[1] - num[0];  // 不写也无妨
        } else {
            tl = min(tl, num[i]- num[i - 1]);
        }
    }
    num[n + 1] = ll;  // 存终点！
    cout << bin_search() << endl;
    return 0;
}
