/*************************************************************************
	> File Name: 6.sort.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 17 Dec 2020 10:44:57 AM CST
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

int arr[1000];

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool cmp(int a, int b) {
    return a > b;
}

// C++中struct代表类
struct CMP {
    // 重载运算符：小于号
    int operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);                                      // 默认从小到大排序
    output(arr, n);
    sort(arr, arr + n, cmp);                                 // 使用函数
    output(arr, n);
    sort(arr, arr + n, CMP());                               // 使用对象
    output(arr, n);
    sort(arr, arr + n, [](int a, int b) { return a > b; });  // 使用lamda表达式 [可以不写返回值]
    output(arr, n);
    sort(arr, arr + n, greater<int>());                      // 使用模板类greater
    output(arr, n);
    sort(arr, arr + n, less<int>());                         // 使用模板类less
    output(arr, n);
    return 0;
}
