/*************************************************************************
	> File Name: 386.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 28 Nov 2020 06:54:21 PM CST
 ************************************************************************/
#include <algorithm>
#include <iostream>
using namespace std;

struct node {
    int cnt, num;
};

int n, m;
node wm[100005];

bool cmp(const node &a, const node &b) {
    return a.num < b.num;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> wm[i].num;
        wm[i].cnt = i + 1;
    }
    sort(wm, wm + n, cmp);
    for (int i = 0; i < m; i++) {
        int t, f = 0, l = 0, r = n - 1;
        cin >> t;
        while (l <= r) {
            int mid = ((long long)l + r) / 2;
            if (t == wm[mid].num) {
                f = wm[mid].cnt;
                break;
            }
            if (t < wm[mid].num) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << f << endl;
    }
    return 0;
}
