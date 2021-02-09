/*************************************************************************
	> File Name: oj-237.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 15 Nov 2020 03:42:51 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
int n, num[15], mark[15], cnt;  // 【mark标记数组】，定义cnt更清晰
void p() {
    for (int i = 0; i < n; i++) {
        if (i) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;

}
// left 还剩几个数
void func(int left) {
    // 输出条件
    if (left == 0) {
        p();
        return ;
    }
    // 都是从1到n
    for (int i = 1; i <= n; i++) {
        // 如果i还未使用
        if (mark[i] == 0) {
            mark[i] = 1;  // 打标记，已使用
            num[cnt] = i; // 记录
            cnt++;
            func(left - 1);
            cnt--;
            mark[i] = 0;  // 去除标记
        }
    }
}
int main() {
    cin >> n;
    func(n);  // 还有n个数要选
    return 0;
}
