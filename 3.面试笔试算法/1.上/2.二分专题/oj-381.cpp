/*************************************************************************
	> File Name: oj-381.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 04 Nov 2020 08:48:37 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct person {
    string name;
    int num, avg, cla, paper, m;
    char off, west;
};  // struct的分号记得！！
bool cmp(person a, person b) {
    if (a.m == b.m) {
        return a.num < b.num;
    }
    return a.m > b. m;
}

int n, ans;
person stu[105];
// 要放在声明的stu[105]后面
int func(int x) {
    int t = 0;
    if (stu[x].avg > 80 && stu[x].paper >= 1) t += 8000;
    if (stu[x].avg > 85 && stu[x].cla > 80) t += 4000;
    if (stu[x].avg > 90) t += 2000;
    if (stu[x].avg > 85 && stu[x].west == 'Y') t += 1000;
    if (stu[x].cla > 80 && stu[x].off == 'Y') t += 850;
    return t;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        // 按顺序读入即可
        cin >> stu[i].name >> stu[i].avg >> stu[i].cla\
        >> stu[i].off >> stu[i].west >> stu[i].paper;
        stu[i].num = i;  // 记录编号，待会排完序就没了
        stu[i].m = func(i); // func传入i即可
        ans += stu[i].m;
    }
    sort(stu, stu + n, cmp);
    cout << stu[0].name << endl << stu[0].m << endl << ans << endl;

    return 0;
}
