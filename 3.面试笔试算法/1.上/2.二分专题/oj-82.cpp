/*************************************************************************
	> File Name: oj-82.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 03 Nov 2020 03:32:32 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, num[1000005], tr;

long long func(int h) {
    long long s = 0;
    for (int i = 0; i < n; i++) {
        // h是伐木的高度，num[i]是树的高度
        if (h < num[i]) {
            s += num[i] - h;
        }
    }
    return s;
}

// 1111110000000
int bin_search() {
    int l = 0, r = tr;
    while (l != r) {
        int mid = ((long long)l + r + 1) / 2;  // l、r可能很大
        long long s = func(mid);  // 切出来的长度有可能大于int
        if (s >= m) {
            l = mid;
        } else {
            r = mid -1;
        }
    }
    return r;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        tr = max(tr, num[i]);  // 记录上界
    }
    cout << bin_search() << endl;
    return 0;
}
