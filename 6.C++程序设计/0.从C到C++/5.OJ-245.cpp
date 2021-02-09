/*************************************************************************
	> File Name: 5.OJ-245.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 17 Dec 2020 10:18:40 AM CST
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

#define MAX_N 100000
int arr[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    nth_element(arr, arr + (n / 2), arr + n);  // 起始位置，要找的第k位，终止位置
    // 左右仓库数相等时的坐标
    int p = arr[n / 2], sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(arr[i] - p);
    }
    cout << sum << endl;
    return 0;
}
