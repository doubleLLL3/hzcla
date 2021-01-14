/*************************************************************************
	> File Name: oj-236.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 15 Nov 2020 03:21:21 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int n, m, num[15], cnt;  // cnt 体现回溯感的深度
void p() {
    for (int i = 0; i < cnt; i++) {
        i && cout << " ";
        cout << num[i];
    }
    cout << endl;
}
// s：从几开始；left：还剩几个要选
void func(int s, int left) {
    //【增加输出条件，够数了输出】
    if (left == 0) {
        p();
        return ;
    }
    for (int i = s; i <= n; i++) {
        num[cnt] = i;
        cnt++;
        func(i + 1, left - 1);
        cnt--;  // cnt在全局，所以需要++、--，而局部变量s、left不需要
    }
}
int main() {
    cin >> n >> m;
    func(1, m);

    return 0;
}
