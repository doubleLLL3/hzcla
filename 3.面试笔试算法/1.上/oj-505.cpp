/*************************************************************************
	> File Name: oj-505.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 08 Nov 2020 06:36:05 PM CST
 ************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s[100005];  // 最多10万个int型整数连接
int n;  

bool cmp(const string &a, const string &b) {
    return a + b > b + a;  // 判断连接后的顺序即可
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}
