/*************************************************************************
	> File Name: 2.OJ-263.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 22 Jan 2021 03:43:08 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int a[30], s[30], top;                                 // s数组：模拟栈；top：栈顶指针

bool is_valid(int *a, int n) {
    int j = 0;                                         // j：当前入栈的最大值，即已进站的最大列车编号，初始为0
    top = -1;
    for (int i = 0; i < n; i++) {
        while (j < a[i]) { s[++top] = (++j); }         // 比较已经入栈的最大值和序列当前元素，如果小于，则正序入栈直到相等
        if (top == -1 || s[top] - a[i]) return false;  // 判断栈顶元素与序列当前元素是否相等
        // [top == -1，为了通用性，防止意外的意外，非法输入，如211，最后一个1会非法访问s[-1]]
        --top;
    }
    return true;
}

int main() {
    int n, ans = 20;
    cin >> n;
    for (int i = 0; i < n; i++) a[i] = i + 1;          // 读入数据，1 ~ n
    do {
        if (!is_valid(a, n)) continue;                 // 一般传数组都需要同时传数组大小
        // 如果合法就输出
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << endl;
        --ans;
    } while (ans && next_permutation(a, a + n));

    return 0;
}
