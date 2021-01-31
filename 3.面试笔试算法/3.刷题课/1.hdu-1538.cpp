/*************************************************************************
	> File Name: 1.hdu-1538.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Mon 25 Jan 2021 08:39:44 PM CST
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

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    if (n <= 2 * m + 1) {
        if (n == p) {
            cout << m - (n - 1) / 2 << endl;
            return ;
        }
        if ((n & 1) == (p & 1)) {
            cout << 1 << endl;
            return ;
        } else {
            cout << 0 << endl;
            return ;
        } 
    } else {
        int f = 2 * m + 1;
        for (int i = 0; (2 * m + (1 << i)) <= n; i++) f = 2 * m + (1 << i);
        if (p > f) {
            cout << "Thrown" << endl;
        } else {
            cout << 0 << endl;
        }
        return ;
    }
   
}

int main() {
    int tmp;
    cin >> tmp;
    while (tmp--) {
        solve();
    }
    return 0;
}
