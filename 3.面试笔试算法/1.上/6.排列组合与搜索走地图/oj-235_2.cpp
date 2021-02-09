/*************************************************************************
	> File Name: oj-235_2.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 15 Nov 2020 02:55:53 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, num[15], cnt;  // cnt：当前选到了第几个数，类似deep

void p() {
    for (int i = 0; i <= cnt; i++) {
        if (i) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
}

void func(int s) {
    for (int i = s; i <= n; i++) {
        num[cnt] = i;
        p();
        cnt++;       // 选下一个数了
        func(i + 1); // 去赋值下一个数
        cnt--;       // 又回到当前数
    }
}

int main() {
    cin >> n;
    func(1);
    return 0;
}
