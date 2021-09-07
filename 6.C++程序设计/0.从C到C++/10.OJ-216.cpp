/*************************************************************************
	> File Name: 12.OJ-216.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 27 Feb 2021 05:14:18 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;

int main() {
    string s;
    map<string, int> h;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        // h[s.substr(3, s.size()] += 1;  // 从第3位截取字符串的size大小，超出尾部不计
        h[s.substr(3)] += 1;              // 从第3位截取到末尾
        // += 1：因为名字有重复
    }
    for (auto iter = h.begin(); iter != h.end(); ++iter) {
        // 名字有重复
        for (int i = 0; i < iter->second; i++) cout << iter->first << endl;
    }
    return 0;
}
