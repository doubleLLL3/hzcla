/*************************************************************************
	> File Name: oj-514.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 08 Nov 2020 07:54:00 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int num[15] = {
    6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 2, 2
};

int sum(int x) {
    //if (x == 0) return num[0];  // 用do...while可以省掉该步
    int ans = 0;
    // 一位一位的算
    do {
        ans += num[x % 10];
        x /= 10;
    } while (x);
    return ans;
}

int func(int a, int b) {
    // sum 求某个数需要的火柴数
    int x = sum(a), y = sum(b), z = sum(a + b);
    return x + y + z + 4;  // 别忘了+、=需要的4根火柴
}
int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            // func 返回总共需要的火柴数
            if (func(i, j) == n) {
                ans++;
                cout << i << " + " << j << " = " << i + j << endl;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
