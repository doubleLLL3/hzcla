/*************************************************************************
	> File Name: oj-380.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Tue 03 Nov 2020 11:01:08 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 把得票数和编号糅在一起
struct node {
    int num;
    string s;
};  // 一定记得分号~

int n;
node p[105];

// 从大到小排序
bool cmp(const node &a, const node &b) {
    // &传的是引用，要加const；不加&也可以
    // 如果长度一致，比较字典序即可
    if (a.s.size() == b.s.size()) {
        return a.s > b.s;  // string给">"重载了字典序排序
    }
    // 大体上是按长度排序
    return a.s.size() > b.s.size(); // size()是自带的
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].s;
        p[i].num = i;
    }
    sort(p + 1, p + n + 1, cmp);  // 从索引1开始
    cout << p[1].num << endl << p[1].s << endl;
    return 0;
}
