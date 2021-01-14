/*************************************************************************
	> File Name: OJ-45.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 27 Dec 2020 08:43:54 PM CST
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
string s1, s2;
int dp[MAX_N + 5][MAX_N + 5] = {0};

int main() {
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            // 两两比较
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s1[i - 1] == s2[j - 1]) {
                //dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    return 0;
}
