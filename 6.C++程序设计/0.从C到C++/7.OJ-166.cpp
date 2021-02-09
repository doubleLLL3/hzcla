/*************************************************************************
	> File Name: 7.OJ-166.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Thu 17 Dec 2020 11:20:51 AM CST
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
    string sa, sb;
    int ind;
    cin >> sa >> ind >> sb;
    if (sa.size() > 100) cout << 100 << endl;
    else cout << sa.size() << endl;
    sa.insert(ind - 1, sb);
    cout << sa << endl;
    cout << sa.size() - sa.rfind("x") << endl;
    //cout << sa.size() - sa.find_last_of("x") << endl;
    return 0;
}
