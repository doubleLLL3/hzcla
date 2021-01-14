/*************************************************************************
	> File Name: euler18.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 30 Oct 2020 07:29:08 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, num[20][20], ans[20][20];

int main() {

    n = 15;  // 数据共15行
    for (int i = 1; i <= n; i++) {
        // 第i行有i个值
        for (int j = 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    // 方法一：自上而下
    int fin = 0;  // 存储最大值
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            // 别忘了加自己
            ans[i][j] = max(ans[i - 1][j - 1], ans[i - 1][j]) + num[i][j];
            fin = max(fin, ans[i][j]);
        }
    }
    cout << fin <<endl;
    //return 0;
    
    // 方法二：自下而上
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = max(ans[i + 1][j], ans[i + 1][j + 1]) + num[i][j];
        }
    }
    cout << ans[1][1] << endl;

    return 0;
}
