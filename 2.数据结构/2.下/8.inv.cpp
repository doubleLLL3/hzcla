/*************************************************************************
	> File Name: 8.inv.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Wed 13 Jan 2021 06:54:56 PM CST
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
#define MAX_N 1000
int inv[7] = {0};


int main() {
    inv[1] = 1;
    for (int i = 2; i < 7; i++) {
        inv[i] = ((-(7 / i) * inv[7 % i]) % 7 + 7) % 7;
        cout << i << " : " << inv[i] << endl;
    }
    return 0;
}
