/*************************************************************************
	> File Name: oj-537.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 22 Nov 2020 02:11:18 PM CST
 ************************************************************************/
#include <algorithm>
#include <iostream>
using namespace std;

int l, c, cnt, ynum, fnum;
char num[30], ans[30];

void p() {
    for (int i = 0; i < l; i++) {
        cout << ans[i];
    }
    cout << endl;
}

int func(int s, int left, int deep) {
    if (deep == l) {
        if (ynum >= 1 && fnum >= 2) {
            p();
            cnt++;
            if (cnt == 25000) {
                return 1;
            }
        }
        return 0;
    }
    for (int i = s; i < c; i++) {
        ans[deep] = num[i];
        int f = 0;
        if (num[i] == 'a' || num[i] == 'e' || num[i] == 'i' || num[i] == 'o' || num[i] == 'u') {
            ynum++;
            f = 1;
        } else {
            fnum++;
        }
        if (func(i + 1, left -1, deep + 1) == 1) {
            return 1;
        }
        if (f == 0) {
            fnum--;
        } else {
            ynum--;
        }
    }
    return 0;
}

int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> num[i];
    }
    sort(num, num + c);
    func(0, l, 0);  // 第几个数，还剩几个数，第几轮开始

    return 0;
}
