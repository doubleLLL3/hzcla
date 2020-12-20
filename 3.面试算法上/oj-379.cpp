/*************************************************************************
	> File Name: oj-379.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 07:01:40 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    // 两个栈：g 货物栈；mmax 最大值栈
    stack<int> g, mmax;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;  // 先用来读取操作
        cin >> t;
        if (t == 0) {
            // 0 入库
            cin >> t;  // 也可以用t，之前的t没用了
            g.push(t);
            // 注意最大值栈的判空
            if (mmax.empty()) {
                mmax.push(t);
            } else {
                mmax.push(max(t, mmax.top()));
            }
        } else if (t == 1) {
            // 1 出库，注意判空
            if (!g.empty()) {
                g.pop();
                mmax.pop();
            }
        } else if (t == 2) {
            // 2 查询，注意判空
            if (g.empty()) {
                cout << 0 <<endl;
            } else {
                cout << mmax.top() << endl;
            }
        }
    }
    return 0;
}
