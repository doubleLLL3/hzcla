/*************************************************************************
	> File Name: 380.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sat 28 Nov 2020 06:49:01 PM CST
 ************************************************************************/
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

struct node {
    int num;
    string s;
};

int n;
node p[105];

bool cmp(const node &a, const node &b) {
    if (a.s.size() == b.s.size()) {
        return a.s > b.s;
    }
    return a.s.size() > b.s.size();
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].s;
        p[i].num = i;
    }
    sort(p + 1, p + n + 1, cmp);
    cout << p[1].num << endl << p[1].s << endl;
    return 0;
}
