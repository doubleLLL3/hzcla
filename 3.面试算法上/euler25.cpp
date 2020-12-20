/*************************************************************************
	> File Name: euler25.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 30 Oct 2020 06:12:06 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

// 大整数加法，大的数n1加到小的数n2里
int func(int *n1, int *n2) {
    n2[0] = n1[0];  // 被加数的位数调整为长的那一个n1，保证n1是大的
    for (int i = 1; i <= n2[0]; i++) {
        n2[i] += n1[i];
        // 如果有进位，↓
        if (n2[i] > 9) {
            n2[i + 1] += n2[i] / 10;
            n2[i] %= 10;
            if (i == n2[0]) {
                n2[0]++;
            }
        }
    }
    return n2[0] == 1000;  // >=也可以，可能更安全
}

int main() {
    int num[2][1100] = {{1, 1}, {1, 1}};  // 前两个数初始为1、1，其它位初始为0
    int a = 0, b = 1;  // 用来指代num[0]、num[1]，只针对索引交换，nice！
    // 两个变量循环加、存储
    for (int i = 3; 1; i++) {
        // 判断位数是否达到1000位
        if (func(num[a], num[b]) == 1) {
            cout << i << endl;
            break;
        }
        swap(a, b);  // 每次大的数的索引对应a
    } 
    return 0;
}
