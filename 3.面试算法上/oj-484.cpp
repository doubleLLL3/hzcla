/*************************************************************************
	> File Name: oj-484.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 08 Nov 2020 04:25:33 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int num[130];    // 计数，ASCII码共128位
char str[1005];  // 读入的字符串

int main() {
    while (cin >> str) {
        for (int i = 0; str[i]; i++) {
            num[str[i]]++;  // 设置num开130位，可以直接++
        }
    }
    int mmax = 0;
    // 得到最大行数
    for (int i = 'A'; i <= 'Z'; i++) {
        mmax = max(mmax, num[i]);
    }
    // 两个循环
    // **外层循环：输出满足当前行数的字符（从mmax到1）
    for (int i = mmax; i > 0; i--) {
        int ind = 'A';  // 初始化，假设s最右为A
        // 得到每行最后一个输出*的字符
        for (int j = 'Z'; j > 'A'; j--) {
            if (num[j] >= i) {
                ind = j;
                break;
            }
        }
        // *内层循环：从A开始到字符ind
        for (int j = 'A'; j <= ind; j++) {
            if (j != 'A') {
                cout << " ";  // 在q字符前输出空格，除了A
            } 
            if (num[j] >= i) {
                cout << "*";  // 判断该字符是否要输出*
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    // 这里用的是char，可以直接输出
    for (char i = 'A'; i <= 'Z'; i++) {
        if (i != 'A') {
            cout << " ";  // 首位判断
        }
        cout  << i;
    }
    cout << endl;

    return 0;
}
