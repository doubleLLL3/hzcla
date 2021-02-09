/*************************************************************************
	> File Name: euler22.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 06 Nov 2020 11:10:37 AM CST
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
// 计算每个姓名的得分
int cop(string name) {
    int score = 0;
    for (int i = 0; name[i]; i++) {
        // 终止条件: i < name.size() 或 name[i]
        score += name[i] - 'A' + 1;
    }
    return score;
}
// 计算总得分
int func(int n, string names[]) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cop(names[i]) * (i + 1);
    }
    return ans;
}
int main() {
    int n = 0;
    string name[6005];
    // 小技巧：遇到EOF时，cin返回false
    while (cin >> name[n]) {
        n++;
    }
    sort(name, name + n);  // 先排序
    cout << func(n, name) << endl;
    return 0;
}
