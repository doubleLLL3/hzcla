/*************************************************************************
	> File Name: oj-480.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 08 Nov 2020 03:06:12 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
struct node {
    char s[4];  // 字节对齐，开4
    int num1, num2, flag;
}; 
node b[15];

int main() {
    int ans = 0;
    // 记录好每轮的得分状态
    for (int i = 0; cin >> b[i].s; i++) {
        if (b[i].s[0] == '/') {
            b[i].num1 = b[i].num2 = 10;
            b[i].flag = 2;  // 直接清空，还要加后2球得分
        } else if (b[i].s[1] == '/') {
            b[i].num1 = b[i].s[0] - '0';
            b[i].num2 = 10;
            b[i].flag = 1;
        } else {
            b[i].num1 = b[i].s[0] - '0';
            b[i].num2 = b[i].s[1] - '0' + b[i].num1;
            b[i].flag = 0;
        }
    }
    // 计算总分，算前10局，视第10局情况会自动补1或2局
    for (int i = 0; i < 10; i++) {
        ans += b[i].num2;  // 必加分
        if (b[i].flag == 1) {
            ans += b[i + 1].num1;
        } else if (b[i].flag == 2) {
            if (b[i + 1].flag == 2) {
                ans += 10 + b[i + 2].num1;
            } else {
                ans += b[i + 1].num2;
            }
        }
    }
    cout << ans <<endl;
    return 0;
}
