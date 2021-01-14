/*************************************************************************
	> File Name: 4.OJ-245.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 17 Dec 2020 09:39:21 AM CST
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

int main() {
    vector<int> arr;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());  // 【核心】
    // 左右仓库数相等时的坐标
    int p = arr[n / 2], sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(arr[i] - p);
    }
    cout << sum << endl;
    return 0;
}
