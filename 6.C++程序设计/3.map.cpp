/*************************************************************************
	> File Name: 3.map.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 17 Dec 2020 08:54:07 AM CST
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
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    map<int, int> arr;
    int n, a;  // n：数字；a：数字的出现次数
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr[a] += 1;
    }
    for (auto iter = arr.begin(); iter != arr.end(); iter++) {
        a = iter->first;
        n = iter->second;
        for (int i = 0; i < n; i++) {
            cout << a << " ";
        }
    }
    cout << endl;
    return 0;

    map<string, double> arr1;
    unordered_map<string, double> arr2;
    arr1["aaaa"] = 123;
    arr1["zzzz"] = 456;
    arr1["iiii"] = 7657;
    arr1["hhhh"] = 12;
    arr2["aaaa"] = 123;
    arr2["zzzz"] = 456;
    arr2["iiii"] = 7657;
    arr2["hhhh"] = 12;
    for (map<string, double>::iterator iter = arr1.begin(); iter != arr1.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << "---------------" << endl;
    for (unordered_map<string, double>::iterator iter = arr2.begin(); iter != arr2.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
