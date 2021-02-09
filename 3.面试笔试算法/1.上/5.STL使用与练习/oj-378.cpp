/*************************************************************************
	> File Name: oj-378.cpp
	> Author: Double
	> Mail: doubleliu3@gmail.com
	> Created Time: Fri 13 Nov 2020 06:18:32 PM CST
 ************************************************************************/
#include <stack>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    stack<char> sta;
    for (int i = 0; i < s.size(); i ++) {
        // 遇到左括号入栈
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            sta.push(s[i]);
        } else if (s[i] == ')') {
            // ①均需先考虑栈为空的情况，②再考虑匹配与否
            if (sta.empty() || sta.top() != '(') {
                cout << "NO" << endl;
                return 0;
            }
            sta.pop();  // 匹配则将左括号出栈
        } else if (s[i] == ']') {
            if (sta.empty() || sta.top() != '[') {
                cout << "NO" << endl;
                return 0;
            } 
            sta.pop();
        } else if (s[i] == '}') {
            if (sta.empty() || sta.top() != '{') {
                cout << "NO" << endl;
                return 0;
            }
            sta.pop();
        }
    }
    // ③ 结束时栈判空：是否还有左括号
    if (sta.empty()) {
        cout << "YES" << endl;   
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
