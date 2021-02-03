/*************************************************************************
	> File Name: 9.LC-5.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Sun 24 Jan 2021 09:08:55 PM CST
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

class Solution {
public:
    string get_new_string(string &s) {
        string ns = "#";
        for (int i = 0; s[i]; i++) {
            (ns += s[i]) += '#';
        }
        return ns;
    }
    string longestPalindrome(string s) {
        string ns = get_new_string(s);
        int *r = new int [ns.size()], c, p;
        r[0] = 1, c = 0;
        for (int i = 1; i < ns.size(); i++) {
            if (i >= c + r[c]) {
                r[i] = 1;
            } else {
                r[i] = min(c + r[c] - i, r[2 * c - i]);
            }
            while (i - r[i] >= 0 && ns[i - r[i]] == ns[i + r[i]]) r[i] += 1;
            if (i + r[i] > c +r[c]) c = i;
        }
        int ans = 0;
        string ret = "";
        for (int i = 0; ns[i]; i++) { 
            ret = "";
            if (r[i] <= ans) continue;
            for (int j = i - r[i]; j < i + r[i]; j++) {
                if (ns[j] == '#')  continue;
                ret += ns[j];
            }
        }
        cout << endl;
        return ret;
    }
};

int main() {
    Solution solv;
    string s;
    while (cin >> s) {
        cout << solv.longestPalindrome(s) << endl;

    }
    return 0;
}
