/*************************************************************************
	> File Name: stack.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 11 Nov 2020 07:21:24 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>   // 栈的头文件
using namespace std;

int main() {
    stack<int> sta;
    for (int i = 9; i > 4; i--) {
        sta.push(i);
    }
    while (!sta.empty()) {
        // sta.size()
        cout << "sta.top() = " << sta.top() << "\tsta.size() = " << sta.size() << endl;
        sta.pop();
    }
    return 0;
}
