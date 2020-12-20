/*************************************************************************
	> File Name: oj-235.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 15 Nov 2020 02:40:44 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, num[15];
// 输出此时深度为deep的数
void p(int deep) {
    for (int i = 1; i <= deep; i++) {
        // 末尾不能有空格
        if (i != 1) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
}
// 参数s：这一层从几开始选；deep：这一层是第几层
void func(int s, int deep) {
    // 选的数的范围：s ~ n
    for (int i = s; i <= n; i++) {
        num[deep] = i;          // 将当前deep层的值赋上
        p(deep);                // 根据层数deep输出此时num数组的值
        func(i + 1, deep + 1);  // 下一层deep + 1：从i + 1 ~ n里选
    }
}

int main() {
    cin >> n;
    func(1, 1);
    return 0;
}
