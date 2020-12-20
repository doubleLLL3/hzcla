/*************************************************************************
	> File Name: oj-513.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 08 Nov 2020 07:38:14 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

// 把x的每一位拿出来，看是否等于t
int func(int x , int t) {
    while (x) {
        if (x % 10 == t) return 0;
        x /= 10;
    }
    return 1;
}

int main() {
    int m, t, ans = 0;  // ans：真实的楼层，记得初始化！
    cin >> m >> t;
    for (int i = 1; i <= m; i++) {
        /*if (func(i, t)) {
            ans++;
        }*/
        ans += func(i, t);
    }
    cout << ans <<endl;
    return 0;
}
